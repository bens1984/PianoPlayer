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

// all of the ARTs:
//  myArt - watches pitch, interval, and auxiliary features
//  derivedArt - watches the inter-feature-vector distance and curvature
//  upperArt - watches the outputs of myArt, derivedArt
//  thirdArt - watches the category IDs from the upperArt

// all of the STMs: (note that each has a "temp" version used during the prediction step)
//  myEncoder - 12 pitch classes
//  intervalEncoder - 7 interval classes
//  othersEncoder - direction of step, octave leap?, register (pitch / 12)
//  upperEncoder - encodes the outputs of the first level ARTs
//  thirdSTM - encodes the category IDs from the upperEncoder

#include <iostream>
#include "ART.h"
#include "SpatialEncoder.h"
#include "MappedEncoder.h"
#include "WaveletEncoder.h"
#include "AccumulationEncoder.h"

#include "OSCSend.h"

#define NEW_THRESHOLD 0.0001          // how mush residual a new category creation is "worth". When the predictor can't find
                                    // a known category with this much residual it will then consider creating new categories
class ReinforcementLearner
{
private:
    SpatialEncoder *pitchEncoder, *intervalEncoder, *othersEncoder;
    AccumulationEncoder *tonalityEncoder, *tempTonalityEncoder;
    SpatialEncoder *tempEncoder, *tempIntEncoder, *tempOtherEncoder;
    ART *pitchArt, *intervalArt, *othersArt, *derivedArt;       // one ART for each section of the input feature vector
    WaveletEncoder *distanceEncoder, *curvatureEncoder, *tempDistanceEncoder, *tempCurvatureEncoder;     // for the derivedART input
    MappedEncoder   *upperEncoder, *tempUpperEncoder;
    ART *upperArt;  // a 2nd ART to watch the transitions between myArt's categories
    ART *bigArt;    // a first level ART to watch all of the features together
    ART *thirdArt;  // watches resonances of lower ARTs
    MappedEncoder *thirdSTM, *tempThirdSTM;   //encoding category IDs from myArt for the thirdArt to watch
    double * featureVector, *prevFeatureVector;
    double occurrencesTotal, recencyTotal; // how much total resonance we have observed from the ART, size of recency vector
    vector<double> occurrences;    // how much resonance has been observed for each category
    vector<double> recency;         // a decaying sum of observed resonance for each category
//    int mDimensions;
//    double mChoice, mLearnRate, mVigilance;	// store for reset
    // outputs from processing in the ART
    const double *fitVector;
    double *prevFitVector, *fitVectorDistances;
    int prevFitVectorSize;
    double *importance;
    int chosenCategory;
    double distance;
    int prevObs;    // previous pitch input
    double mySponteneity;
    bool    useRecency;     // do we weight resonance by a measure of recency?
private:
    void CalcFeatureVectorDistance();
    double CalcFitVectorDistance();   // distance between prevFitVector and fitVector
    double DoFirstLevelDistance(bool retain);     // get the distance between first level resonance vectors and learn on it, returns importanceSum
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
        return pitchArt->calcDistance(chosenCategory);
    }
    void SetSponteneity(double s)
    {
        mySponteneity = s / 30.0;   // divide by the number of feature vector dimensions
    }
    void SetUseRecency(bool b)
    {
        useRecency = b;
    }
};