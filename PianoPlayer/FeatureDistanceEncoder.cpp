//
//  FeatureDistanceEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 11/3/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "FeatureDistanceEncoder.h"
#include <math.h>
#include <stdio.h>

FeatureDistanceEncoder::FeatureDistanceEncoder(int tokens) : SpatialEncoder(4), inputSize(tokens) {
    for (int i = 0; i < 4; i++)
    {
        averagePosition[i] = (double*)malloc(tokens * sizeof(double));
        for (int j = 0; j < tokens; j++)
            averagePosition[i][j] = 0.0;
    }
}
FeatureDistanceEncoder::~FeatureDistanceEncoder() {
    for (int i = 0; i < 4; i++)
        delete averagePosition[i];
}
//
//void FeatureDistanceEncoder::AddToken(double sample) {
//    
//}
void FeatureDistanceEncoder::DoEncoding(double * sample, int size) {
    if (dimensions > 0) // && size == dimensions) // && token < dimensions) {
    {
        DecayEncoding(decayAmount);
        double distance;
        for (int i = 0; i < 4; i++)
        {
            double filterFactor = 1.0 / pow(2, i);
            double FF_1 = 1.0 - filterFactor;
            distance = 0;
            for (int j = 0; j < size; j++)
            {
                distance += pow(averagePosition[i][j] - sample[j], 2.0);
                averagePosition[i][j] = averagePosition[i][j] * FF_1 + sample[j] * filterFactor;
            }
            distance = sqrt(distance);
            myEncoder[i] = distance;
        }
    } else
        cout << "FeatureDistanceEncoder error: incorrect dimensions or size input!" << endl;
}

const double* FeatureDistanceEncoder::GetAverages(int index) {
    return averagePosition[index];
}

void FeatureDistanceEncoder::Copy(FeatureDistanceEncoder* that) {
    SpatialEncoder::Copy(that);
    inputSize = that->GetInputSize();
    int bufSize = inputSize * sizeof(double);
    for (int i = 0; i < 4; i++)
    {
        averagePosition[i] = (double*)malloc(bufSize);
        memcpy(averagePosition[i], that->GetAverages(i), bufSize);
    }
}
int FeatureDistanceEncoder::GetInputSize() {
    return inputSize;
}