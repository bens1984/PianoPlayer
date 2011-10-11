//
//  SpatialEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

SpatialEncoder::SpatialEncoder(const int& tokenCount) : dimensions(tokenCount), myDecay(ExponentialDecay), decayAmount(0.95)
{
    myEncoder = new double[dimensions];
    for (int i = 0; i < dimensions; i++)
        myEncoder[i] = 0;
}
SpatialEncoder::~SpatialEncoder()
{
    delete myEncoder;
}

void SpatialEncoder::AddToken(const int& token)
{
    if (token >= 0 && token < dimensions) {
        DecayEncoding(decayAmount);
        myEncoder[token] = 1.0;
    } else
        cout << "Warning: SpatialEncoder::AddToken: token out of range." << endl;
}

void SpatialEncoder::DecayEncoding(const double& scalar)
{
    switch (myDecay) {
        case LinearDecay:
            for (int i = 0; i < dimensions; i++)
                myEncoder[i] -= scalar;
            break;
        case ExponentialDecay:
        default:
            for (int i = 0; i < dimensions; i++)
                myEncoder[i] *= scalar;
            break;
    }
}

const double& SpatialEncoder::GetEncoding()
{
    return *myEncoder;
}

void SpatialEncoder::SetDecayAmount(const double& decay) {
    decayAmount = decay;
}
void SpatialEncoder::SetDecayModel(DecayModel model)
{
    myDecay = model;
}