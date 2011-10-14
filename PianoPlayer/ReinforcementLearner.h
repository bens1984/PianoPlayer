#pragma once
//
//  fuzzyART.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
//  implementation of Carpenter and Grossberg's fuzzy Adaptive Resonance Theory
//      neural net.

//
// fuzzy Adaptive Resonance Theory Implementation
//			2010, Benjamin Smith <ben@musicsmiths.us> - GPL license.
//				http://ben.musicsmiths.us/
//		based on Carpenter and Grossberg - search on google scholar
//
//  arguments are: Choice, learn rate and Vigilance
//
//  parameters:
//		distance boolean - if true outputs accuracy of the input, how close it hits the center of the known category
// class representation of each discovered category in the ART algorithm (each Node)

#include <iostream>
#include "ART.h"
#include "SpatialEncoder.h"

#include "OSCSend.h"

#define NEW_THRESHOLD 0.001          // how mush residual a new category creation is "worth". When the predictor can't find
                                    // a known category with this much residual it will then consider creating new categories


class ReinforcementLearner
{
private:
    SpatialEncoder *myEncoder, *intervalEncoder;
    ART *myArt;
    int inputCount; // how many inputs we have fed into the ART
    vector<int> occurrences;    // how many time each category has been observed
//    int mDimensions;
//    double mChoice, mLearnRate, mVigilance;	// store for reset
    // outputs from processing in the ART
    const double *fitVector;
    double *importance;
    int chosenCategory;
    double distance;
    int prevObs;    // previous pitch input
    double mySponteneity;
    
public:
    ReinforcementLearner() /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/ : fitVector(0x00), importance(0x00), inputCount(0), prevObs(-1), mySponteneity(NEW_THRESHOLD/19.0)
    {
//        mDimensions = (dimensions > 0 ? dimensions : 1);
//        mLearnRate = (_learnRate != 0 ? _learnRate : 0.5);
//        mChoice = _choice;
//        mVigilance = _Vigilance;
        
        myArt = new ART(0, 0.5, 0.925);    // params: choice, learning rate, vigilance
        myEncoder = new SpatialEncoder(12);     // for encoding pitch inputs
        intervalEncoder = new SpatialEncoder(7);        // for encoding intervals
        std::cout << "ReinforcementLearner -- ©2010 Benjamin Smith\n";
//        std::cout << " init with Dimensions: " << dimensions << ", Choice: " << _choice <<
//            ", Learn Rate: " << mLearnRate << ", Vigilance: " << _Vigilance << std::endl;
    }
    ~ReinforcementLearner()
    {
        delete myArt;
        delete myEncoder;
    }
    
    double ProcessNewObservation(const int& obs)  // this is the next pitch that is observed
    {
        myEncoder->AddToken(obs);       // spatially encode the input
        if (prevObs != -1)
        {
            int interval = abs(obs-prevObs);
            if (interval > 6)
                interval = 12-interval;
            intervalEncoder->AddToken(interval);
        }
        prevObs = obs;
        double featureVector[12+7];
        memcpy(&featureVector, &myEncoder->GetEncoding(), 12*8);
        memcpy(&featureVector[12], &intervalEncoder->GetEncoding(), 7*8);
        OSCSend::getSingleton()->oscSend("/stm", 19, &featureVector[0]);
        
        myArt->ProcessNewObservation(&featureVector[0], 19);    // add it to the ART
        if (fitVector != 0x00)
            delete fitVector;
        fitVector = myArt->GetCategoryChoice(); // get the resonance of each category against this input.
//        importance = myArt->GetImportance();
        
        chosenCategory = myArt->makeChoice();	// make a choice and learn from it. This modifies the resonances, so the must be received first
        
        inputCount += 1;                        // count up this input
        while (occurrences.size() < chosenCategory+1)
            occurrences.push_back(0);
        occurrences.at(chosenCategory) += 1;
        
        double importSum = 0.0;
        if (importance != 0x00)                 // now calculate the importance vector
            delete importance;
        importance = new double[occurrences.size()];
        for (int i = 0; i < occurrences.size(); i++)
        {
            importance[i] = fitVector[i]; // * (occurrences.at(i) / (double)inputCount);
            importSum += importance[i];
        }
        importSum = importSum;    // try magnitude of import vector
//        cout << importSum << " residual: " << myArt->GetResidual() << endl;
        
        const double* w = myArt->GetWeights(0);
        OSCSend::getSingleton()->oscSend("/0", 19*2, w);
        delete w;
        
        return importSum * myArt->GetResidual();  // this is the intrinsic reward for observing this input!
    }
    
    int PredictMaximalInput()      // look one step ahead and calculate what input value would be most rewarding
    {
        double mImportance[occurrences.size()];
        double reward[12]; //, rewardLR[12];      // hold the potential reward for each of our proposals
        SpatialEncoder tempEncoder(12);
        SpatialEncoder tempIntEncoder(7);
        for (int i = 0; i < 12; i++)    // try each of the pitches
        {
            tempEncoder.Copy(myEncoder);    // copy the 'real' encoder's state
            tempEncoder.AddToken(i);        // add the proposed input
            tempIntEncoder.Copy(intervalEncoder);
            int interval = abs(i-prevObs);
            if (interval > 6)
                interval = 12-interval;
            tempIntEncoder.AddToken(interval);
            
            double featureVec[19];
            memcpy(&featureVec, &tempEncoder.GetEncoding(), 12*8);
            memcpy(&featureVec[12], &tempIntEncoder.GetEncoding(), 7*8);
//            OSCSend::getSingleton()->oscSend("/tempEncoding", 12, &tempEncoder.GetEncoding());
            
            myArt->ProcessNewObservation(&featureVec[0], 19);  // stick it in the ART and let it think about it.
            if (fitVector != 0x00)
                delete fitVector;
            fitVector = myArt->GetCategoryChoice();                         // get the resonance of each category
            
            int cat = myArt->PredictChoice();
            
            double importSum = 0.0;     // now calculate the importance vector, i.e. how boring something is.
            for (int j = 0; j < occurrences.size(); j++)
            {
                mImportance[j] = fitVector[j] / occurrences.size(); // * (occurrences.at(j) / (double)inputCount);
                importSum += mImportance[j];
            }
            importSum = importSum;    // try magnitude of import vector
            
            double res = myArt->GetResidual();
            if (res > 1)      // it's creating a new category, so treat it seperately
                reward[i] = importSum * mySponteneity;
            else
                reward[i] = res * importSum; //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new
//            cout << "predict cat " << cat << " produces " << res << ", reward: " << reward[i] << endl;
//            rewardLR[i] = (1.0-importSum) * myArt->GetResidualLR();
        }
        OSCSend::getSingleton()->oscSend("/predictReward", 12, &reward[0]);
        double max = -1;
        int maxInput = -1;
        for (int i = 0; i < 12; i++)
        {
            if (reward[i] > max)
            {
                max = reward[i];
                maxInput = i;
            }
        }
        return maxInput;
    }
    
    // ---------------- List: input of new feature vector
//    void ProcessNewObservation(double *list, int length)
//    {
//        myArt->ProcessNewObservation(list, length);
//        if (fitVector != 0x00)
//            delete fitVector;
//        fitVector = myArt->GetCategoryChoice();
////        if (importance != 0x00)
////            delete importance;
////        importance = myArt->GetImportance();
//        
//        chosenCategory = myArt->makeChoice();	// make a choice and learn from it
//    }
    
    // ------- Accessors ----------
    const double *GetFitVector()
    {
        return fitVector;
    }
    double *GetImportance()
    {
        return importance;
    }
    int GetChosenCategory()
    {
        return chosenCategory;
    }
    double GetDistance()
    {
        return myArt->calcDistance(chosenCategory);
    }
    void SetSponteneity(double s)
    {
        mySponteneity = s / 19.0;   // divide by the number of feature vector dimensions
    }
    // ----------------------------S
//    void outputInitialWeights(double *choices)
//    {
//        Atom[] out = new Atom[choices.length];
//        for(int i = 0; i < choices.length; i++)
//            out[i] = choices[i];
//        outlet(1, out);
//    }
    
//    void categories()
//    {
//        double[][] weights = myArt.getWeights();
//        for (int i = 0; i < weights.length; i++)
//        {
//            Atom[] out = Atom.newAtom(weights[i]);
//            outlet(2, (String)Integer.toString(i), out);
//        }
//    }
    
//    void centers()
//    {
//        double[][] weights = myArt.getWeights();
//        for (int i = 0; i < weights.length; i++)
//        {
//            double[] centers = new double[mDimensions];	// calculate the center positions of the weights
//            for (int j = 0; j < mDimensions; j++)	// same as mDimensions
//                centers[j] = (weights[i][j] + weights[i][j+mDimensions]) * 0.5;
//            Atom[] out = Atom.newAtom(centers);
//            outlet(2, (String)Integer.toString(i), out);
//        }
//    }
    
//    void reset()
//    {
////        post("> reset fuzzyArt with Dimensions: " + mDimensions + ", Choice: " + mChoice + ", Learn Rate: " + mLearnRate + ", Vigilance: " + mVigilance);
//        delete myArt;
//        myArt = new ART(mDimensions, mChoice, mLearnRate, mVigilance);
//    }
};