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


class ReinforcementLearner
{
private:
    SpatialEncoder *myEncoder;
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
    
public:
    ReinforcementLearner() /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/ : fitVector(0x00), importance(0x00), inputCount(0)
    {
//        mDimensions = (dimensions > 0 ? dimensions : 1);
//        mLearnRate = (_learnRate != 0 ? _learnRate : 0.5);
//        mChoice = _choice;
//        mVigilance = _Vigilance;
        
        myArt = new ART(1, 0, 0.1, 0.9);    // initial feature vector dimensions, choice, learning rate, vigilance
        myEncoder = new SpatialEncoder(12);
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
        OSCSend::getSingleton()->oscSend("/stm", 12, &myEncoder->GetEncoding());
        
        myArt->ProcessNewObservation(&myEncoder->GetEncoding(), 12);    // add it to the ART
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
            importance[i] = fitVector[i] * (occurrences.at(i) / (double)inputCount);
            importSum += importance[i];
        }
        importSum = importSum;    // try magnitude of import vector
        cout << importSum << " residual: " << myArt->GetResidual() << endl;
        
        return importSum * myArt->GetResidual();  // this is the intrinsic reward for observing this input!
    }
    
    int PredictMaximalInput()      // look one step ahead and calculate what input value would be most rewarding
    {
        double mImportance[occurrences.size()];
        double reward[12]; //, rewardLR[12];      // hold the potential reward for each of our proposals
        SpatialEncoder tempEncoder(12);
        for (int i = 0; i < 12; i++)    // try each of the pitches
        {
            tempEncoder.Copy(myEncoder);    // copy the 'real' encoder's state
            tempEncoder.AddToken(i);        // add the proposed input
//            OSCSend::getSingleton()->oscSend("/tempEncoding", 12, &tempEncoder.GetEncoding());
            
            myArt->ProcessNewObservation(&tempEncoder.GetEncoding(), 12);  // stick it in the ART and let it think about it.
            if (fitVector != 0x00)
                delete fitVector;
            fitVector = myArt->GetCategoryChoice();                         // get the resonance of each category
            
            int cat = myArt->PredictChoice();
            
            double importSum = 0.0;     // now calculate the importance vector, i.e. how boring something is.
            for (int j = 0; j < occurrences.size(); j++)
            {
                mImportance[j] = fitVector[j] * (occurrences.at(j) / (double)inputCount);
                importSum += mImportance[j];
            }
            importSum = importSum;    // try magnitude of import vector
            
            double res = myArt->GetResidual();
            reward[i] = importSum * res;               // here we want a lot of change to something boring, or minimal change to something new
            cout << "predict cat " << cat << " produces " << res << ", reward: " << reward[i] << endl;
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