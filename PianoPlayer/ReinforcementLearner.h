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

#define NEW_THRESHOLD 0.1          // how mush residual a new category creation is "worth". When the predictor can't find
                                    // a known category with this much residual it will then consider creating new categories


class ReinforcementLearner
{
private:
    SpatialEncoder *myEncoder, *intervalEncoder, *othersEncoder;
    SpatialEncoder *tempEncoder, *tempIntEncoder, *tempOtherEncoder;
    ART *myArt;
    ART *upperArt;  // a 2nd ART to watch the transitions between myArt's categories
    double * featureVector;
    double occurrencesTotal, recencyTotal; // how much total resonance we have observed from the ART, size of recency vector
    vector<double> occurrences;    // how much resonance has been observed for each category
    vector<double> recency;         // a decaying sum of observed resonance for each category
//    int mDimensions;
//    double mChoice, mLearnRate, mVigilance;	// store for reset
    // outputs from processing in the ART
    const double *fitVector;
    double *importance;
    int chosenCategory;
    double distance;
    int prevObs;    // previous pitch input
    double mySponteneity;
    bool    useRecency;     // do we weight resonance by a measure of recency?
    
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
    void SetUseRecency(bool b)
    {
        useRecency = b;
    }
};