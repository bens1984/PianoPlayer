
//
//  SpatialEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"
#include <string.h>

SpatialEncoder::SpatialEncoder(int tokenCount) : dimensions(tokenCount), myDecay(ExponentialDecay), decayAmount(0.7)
{
    if (dimensions == 0)
        dimensions = 2;
    myEncoder = (double*)malloc(dimensions*sizeof(double)); //new double[dimensions];
    for (int i = 0; i < dimensions; i++)
        myEncoder[i] = 0;
}
SpatialEncoder::~SpatialEncoder()
{
    delete myEncoder;
}

void SpatialEncoder::DoEncoding(int token)
{
    if (dimensions > 0 && token >= 0) // && token < dimensions) {
    {
        DecayEncoding(decayAmount);
        AddToken(token);
    }
}
void SpatialEncoder::DoEncoding(int* tokens, int size)
{
    if (dimensions > 0) // && token < dimensions) {
    {
        DecayEncoding(decayAmount);
        for (int i = 0; i < size; i++)
            AddToken(tokens[i]);
    }
}
void SpatialEncoder::AddToken(int token)
{
    if (dimensions > 0 && token >= 0) { // && token < dimensions) {
        token = token % dimensions;
        myEncoder[token] = 1.0;
    } else
        cout << "Warning: SpatialEncoder::AddToken: '" << token << "' token out of range. " << dimensions << endl;
}

void SpatialEncoder::AddToken(int* token, int size)    // input several tokens at once
{
    for (int i = 0; i < size; i++)
        AddToken(token[i]);
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

double* SpatialEncoder::GetEncoding()
{
    return myEncoder;
}
int SpatialEncoder::GetDimensions()
{
    return dimensions;
}
double SpatialEncoder::GetDecayAmount()
{
    return decayAmount;
}
DecayModel SpatialEncoder::GetDecayModel()
{
    return myDecay;
}

void SpatialEncoder::SetDecayAmount(const double& decay) {
    decayAmount = decay;
}
void SpatialEncoder::SetDecayModel(DecayModel model)
{
    myDecay = model;
}

void SpatialEncoder::Copy(SpatialEncoder* that) {
    dimensions = that->GetDimensions();
    decayAmount = that->GetDecayAmount();
    myDecay = that->GetDecayModel();
    delete myEncoder;   // clean up old encoder space
    myEncoder = new double[dimensions];
    std::memcpy(myEncoder, that->GetEncoding(), dimensions*sizeof(double));
}