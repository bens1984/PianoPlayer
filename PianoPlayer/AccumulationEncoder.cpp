//
//  AccumulationEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "AccumulationEncoder.h"


AccumulationEncoder::AccumulationEncoder(int tokenCount, float accumulation, bool dynamic) : SpatialEncoder(tokenCount, dynamic), accumulationAmount(accumulation) {
    myDecay = ExponentialDecay;
    decayAmount = 1.0 - accumulationAmount;
}
AccumulationEncoder::~AccumulationEncoder() {
//    SpatialEncoder::~SpatialEncoder();
}

void AccumulationEncoder::AddToken(int token) {
    double currentValue = 0.0;
    if (token < dimensions && token >= 0)
        currentValue = myEncoder[token];
    
    SpatialEncoder::AddToken(token);    // this sets it to 1 and expands the encoder if necessary.
    
    if (token < dimensions && token >= 0)       // overwrite the 1 with our own accumulated amount.
        myEncoder[token] = currentValue + accumulationAmount;
}

void AccumulationEncoder::SetAccumulationAmount(float a)
{
    accumulationAmount = a;
}

void AccumulationEncoder::Copy(AccumulationEncoder* that)
{
    SpatialEncoder::Copy(that);
    SetAccumulationAmount(that->GetAccumulationAmount());
}