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

using namespace std;

class ART
{
private:
    int mDimensions; // how many dimensions to match data on
    vector<ArtCategory*> mCategories;
    vector<ResonanceGroup> mResonanceWeights;
//    vector<int> mCount;     // how many times each category has been seen. trying to measure how "confident" we are in the observation
//    int inputCount;  // how many inputs we have seen
    double mChoice, mLearnRate, mVigilance;
    double *input, *choices;
    int recentChoice, choiceSize;	// the most recently chosen category, the size of the choices array
    double residual;    // how much the chosen category changed with the last input/learning step
    
    // private member functions
    void normalizeInput();
    inline void complementCode();
    void setInput(double *&_in, int size);
    
    //	set the mVigilance just high enough to reset the chosen category and look again.
    int increaseVigilance();
    void FillCategoryChoice();
public:
    ART(double _choice, double _learnRate, double _Vigilance);
    ~ART();
    void ProcessNewObservation(double *&input, int length);
    
    void setVigilance(double v);
    void setLearnRate(double v);
    void setChoice(double v);
    double GetResidual();
    const double* GetCategoryChoice();
    
    void AddResonanceGroup(int startIndex, int groupSize, double weight);

    int makeChoice();
    int makeChoice(double workingVigilance);
    int PredictChoice();
    int PredictChoice(double workingVigilance);
    double calcDistance(int cat);	// use set input and calculate distance to center of specified category
    const double *getWeights();	// return all of the weights of all of our categories
    const double* GetWeights(int index);
};
