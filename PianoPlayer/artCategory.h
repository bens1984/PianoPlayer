#pragma once
//
//  artCategory.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <Math.h>
#include <string.h>

class ArtCategory
{
private:
    bool committed;	// switch to true after the category is committed
    double* weighting;
    int dimensions;
    double sum;
    
public:
    ArtCategory(int dim);
    ~ArtCategory();
    
    // calculate the mChoice match factor for this category and the given input
    double Choose(double input[], int size, double mChoice);
    
    bool mVigilance(double input[], int size, double mVigilance);
    double GetVigilance(double input[], int size);
    
    double Learn(const double* input, int size, double mLearnRate);
    double GetResidual(const double* input, int size, double mLearnRate);  // return the amount of change in the category if this input was learned with LearnRate=1
    
    const double* GetWeights();
    
    const double distance(double input[]);
    
    void resizeCategory(int newSize);
};
