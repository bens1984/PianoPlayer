
//
//  SpatialEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"
#include <string.h>

SpatialEncoder::SpatialEncoder(int tokenCount, bool dynamic) : dimensions(tokenCount), myDecay(LinearDecay), decayAmount(ENCODER_DECAY_RATE), dynamicGrow(dynamic)
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
//        for (int i = 0; i < size; i++)
            AddToken(tokens, size);
    }
}
void SpatialEncoder::AddToken(int token)
{
    if (token >= 0) { // && token < dimensions) {
        if (token > dimensions-1)
            if (dynamicGrow)
            {
                double* newEncoder = (double*)malloc((token+1)*sizeof(double));
                memcpy(newEncoder, myEncoder, dimensions*sizeof(double));
                dimensions = token+1;
                delete myEncoder;
                myEncoder = newEncoder;
            } else
            {
                cout << "Warning: SpatialEncoder::AddToken: '" << token << "' token out of range: " << dimensions << endl;
                return; // it's an error!
            }
//        token = token % dimensions;
        myEncoder[token] = 1.0;
    } else
        cout << "Warning: SpatialEncoder::AddToken: '" << token << "' token out of range: " << dimensions << endl;
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
            for (int i = 0; i < dimensions; i++) {
                myEncoder[i] -= scalar;
                myEncoder[i] = max(myEncoder[i], 0.0);
            }
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
    if (dimensions != that->GetDimensions()) {
        delete myEncoder;   // clean up old encoder space
        dimensions = that->GetDimensions();
        myEncoder = (double*)malloc(dimensions*8);
    }
    decayAmount = that->GetDecayAmount();
    myDecay = that->GetDecayModel();
    std::memcpy(myEncoder, that->GetEncoding(), dimensions*sizeof(double));
}