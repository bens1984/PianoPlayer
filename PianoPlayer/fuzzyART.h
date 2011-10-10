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


class fuzzyART
{
private:
    ART *myArt;
    int mDimensions;
    double mChoice, mLearnRate, mVigilance;	// store for reset
    // outputs from processing in the ART
    double *fitVector, *importance;
    int chosenCategory;
    double distance;
    
public:
    fuzzyART(int dimensions, double _choice, double _learnRate, double _Vigilance) : fitVector(0x00), importance(0x00)
    {
        mDimensions = (dimensions > 0 ? dimensions : 1);
        mLearnRate = (_learnRate != 0 ? _learnRate : 0.5);
        mChoice = _choice;
        mVigilance = _Vigilance;
        
        myArt = new ART(dimensions, _choice, _learnRate, _Vigilance);
        std::cout << "FuzzyART -- implementation ©2010 Benjamin Smith\n";
        std::cout << " init with Dimensions: " << dimensions << ", Choice: " << _choice <<
            ", Learn Rate: " << mLearnRate << ", Vigilance: " << _Vigilance << std::endl;
    }
    // ---------------- List: input of new feature vector
    void ProcessNewObservation(double *list, int length)
    {
//        double input[mDimensions * 2];
//        for (int i = 0; i < length; i++)
//            input[i] = list[i];
        myArt->setInput(list, length);
        myArt->normalizeInput();
        myArt->complementCode();
        
        if (fitVector != 0x00)
            delete fitVector;
        fitVector = myArt->getCategoryChoice();
        if (importance != 0x00)
            delete importance;
        importance = myArt->GetImportance();
        
        chosenCategory = myArt->makeChoice();	// make a choice and learn from it
    }
    
    // ------- Accessors ----------
    double *GetFitVector()
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
    
    void IncreaseVigilance()
    {
        int output = myArt->increaseVigilance();
        std::cout << "Increasing vigilance: " << output << std::endl;
    }
    
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
    
    void reset()
    {
//        post("> reset fuzzyArt with Dimensions: " + mDimensions + ", Choice: " + mChoice + ", Learn Rate: " + mLearnRate + ", Vigilance: " + mVigilance);
        delete myArt;
        myArt = new ART(mDimensions, mChoice, mLearnRate, mVigilance);
    }
};