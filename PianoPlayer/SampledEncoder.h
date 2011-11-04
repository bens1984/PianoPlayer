//
//  SampledEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 11/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

class SampledEncoder : public SpatialEncoder {
private:
    double sampleSize;
public:
    SampledEncoder(int tokens);
    
    void AddToken(double sample);
    void DoEncoding(const double& scalar);
};