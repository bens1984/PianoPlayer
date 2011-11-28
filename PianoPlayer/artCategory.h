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
#include <vector.h>

struct ResonanceGroup {    // a rough way to set relative modifiers for different sub-groups of features in the STM
    int startIndex, length;
    double weight;
    
    ResonanceGroup(int _in, int _size, double _weight) : startIndex(_in), length(_size), weight(_weight)
    { }
};

class ArtCategory
{
private:
    bool committed;	// switch to true after the category is committed
    double* weighting;
    int dimensions;
    double sum;
    double magnitude;
    
    double GetMagnitude();
public:
    ArtCategory(int dim);
    ~ArtCategory();
    
    // calculate the mChoice match factor for this category and the given input
    double Choose(const double* input, int size, double mChoice);
    double Choose(const double* input, int size, double mChoice, vector<ResonanceGroup>& resonanceWeights);
    
    bool mVigilance(const double* input, int size, double mVigilance);
    double GetVigilance(const double* input, int size);
    
    double Learn(const double* input, int size, double mLearnRate);
    double GetResidual(const double* input, int size, double mLearnRate);  // return the amount of change in the category if this input was learned with LearnRate=1
    
    const double* GetWeights();
    
    const double distance(const double* input);
    const double curvature(const double* theseWeights);    // return the angle of change between theseWeights and our weighting
    
    void resizeCategory(int newSize);
    
    char* Serialize(int &size);
    void Deserialize(char* data, int size);
};
