//
//  FeatureDistanceEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 11/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

class FeatureDistanceEncoder : public SpatialEncoder {
private:
    double * averagePosition[4];
    int     inputSize;
public:
    FeatureDistanceEncoder(int dimensions);
    ~FeatureDistanceEncoder();
    
//    void AddToken(double sample);
    void DoEncoding(double * sample, int size);
    
    const double* GetAverages(int index);
    int GetInputSize();
    
    void Copy(FeatureDistanceEncoder* that);
};