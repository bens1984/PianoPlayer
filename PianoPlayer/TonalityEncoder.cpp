//
//  TonalityEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 11/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
//  an attempt at characterizing the perception of tonality.
//      as a note is heard its influence is increased, as it
//      receds in memory its influence decays.
//      a vector of 1s represents an empty memory
//      a new pitch sets a node to current value * 0.5
//      all nodes decay at a linear rate of +0.15 each time step

#include "TonalityEncoder.h"

#define TONALITY_DECAY_AMOUNT 0.05
#define TONALITY_ACCUM_RATE 0.5

TonalityEncoder::TonalityEncoder(int tokenCount) : SpatialEncoder(tokenCount) {
    for (int i = 0; i < dimensions; i++)
        myEncoder[i] = 1.0;
}

void TonalityEncoder::AddToken(int token) {
    double prevValue = 1.0;
    if (dimensions > token)
        prevValue = myEncoder[token];
    
    SpatialEncoder::AddToken(token);
    
    myEncoder[token] = prevValue * TONALITY_ACCUM_RATE;
}

void TonalityEncoder::DecayEncoding(const double& scalar) {
    for (int i = 0; i < dimensions; i++)
    {
        myEncoder[i] += TONALITY_DECAY_AMOUNT;
        myEncoder[i] = min(myEncoder[i], 1.0);
    }
}