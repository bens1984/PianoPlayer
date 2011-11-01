//
//  WaveletEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "WaveletEncoder.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

WaveletEncoder::WaveletEncoder(int numOfBanks) : filterCount(numOfBanks)
{
    filterBank = (double*)malloc(sizeof(double)*filterCount);
    for (int i = 0; i < numOfBanks; i++)
        filterBank[i] = 0.0;
}
WaveletEncoder::~WaveletEncoder() {
    delete filterBank;
}

void WaveletEncoder::AddSample(double sample)
{
    for (int i = 0; i < filterCount; i++)
    {
        double len = pow(2,i);
        filterBank[i] = (filterBank[i] * (len-1) + sample) / len;
    }
}
const double * WaveletEncoder::GetEncoding()
{
    return &filterBank[0];
}
int WaveletEncoder::GetEncoderSize() {
    return filterCount;
}

void WaveletEncoder::Copy(WaveletEncoder* that) {
    if (that != 0x00)
    {
        delete filterBank;
        filterCount = that->GetEncoderSize();
        filterBank = new double(filterCount);
        memcpy(filterBank, that->GetEncoding(), filterCount);
    }
}