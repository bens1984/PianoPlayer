//
//  SampledEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 11/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SampledEncoder.h"
#include <math.h>
#include "stdio.h"

SampledEncoder::SampledEncoder(int tokens) : SpatialEncoder(tokens)
{
//    decayAmount = 0.9;
    sampleSize = 1.0 / (double)tokens;
}

void SampledEncoder::AddToken(double sample)
{
    int token = floor(sample / sampleSize);
    SpatialEncoder::AddToken(token);
}
void SampledEncoder::DoEncoding(const double& scalar)
{
    DecayEncoding(decayAmount);
    AddToken(scalar);
}