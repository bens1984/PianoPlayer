#pragma once
//
//  ART.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "artCategory.h"
#include <vector.h>
#include "OSCSend.h"

#define RECENCY_DECAY_RATE  0.99     // how quickly the recency vector decays. This is how quickly ideas become familiar and no longer fresh
#define OBSERVATION_VALUE 0.01      // how much an observation weights a category.

//#define USING_RECENCY       // comment out to block using the recency vector during importance calculations

using namespace std;

class ART
{
private:
    int mDimensions; // how many dimensions to match data on
    vector<ArtCategory*> mCategories;
    vector<ResonanceGroup> mResonanceWeights;
    vector<double> mObservations;     // how many times each category has been seen. trying to measure how "confident" we are in the observation
    int inputCount;  // how many inputs we have seen
    vector<double> mRecency;
    double maxRecency;
    double mChoice, mLearnRate, mVigilance;
    double *input, *choices;
    int recentChoice, choiceSize;	// the most recently chosen category, the size of the choices array
    double residual;    // how much the chosen category changed with the last input/learning step
    
    // private member functions
    void normalizeInput();
    inline void complementCode();
    void setInput(const double *_in, int size);
    
    //	set the mVigilance just high enough to reset the chosen category and look again.
    int increaseVigilance();
    void FillCategoryChoice();
    void DecayRecency();
public:
    ART(double _choice, double _learnRate, double _Vigilance);
    ~ART();
    void ProcessNewObservation(const double *input, int length);
    
    void setVigilance(double v);
    void setLearnRate(double v);
    void setChoice(double v);
    double GetResidual();
    const double* GetCategoryChoice();
    int GetCategoryCount(); // how many categories?
    
    void AddResonanceGroup(int startIndex, int groupSize, double weight);

    int makeChoice();
    int makeChoice(double workingVigilance);
    double PredictChoice();
    double PredictChoice(double workingVigilance);
    int GetChosenCategoryID();
    double calcDistance(int cat);	// use set input and calculate distance to center of specified category
    const double *getWeights();	// return all of the weights of all of our categories
    const double* GetWeights(int index);
    
    double GetImportanceSum();
};
