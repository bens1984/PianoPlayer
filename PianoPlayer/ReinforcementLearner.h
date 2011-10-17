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
    SpatialEncoder *myEncoder, *intervalEncoder, *othersEncoder;
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
    ReinforcementLearner();
    ~ReinforcementLearner();
    
    double ProcessNewObservation(const int& obs);  // this is the next pitch that is observed
    
    int PredictMaximalInput();      // look one step ahead and calculate what input value would be most rewarding
    double CalcPredictedReward(int test);
    
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
};