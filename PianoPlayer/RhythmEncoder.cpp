//
//  RhythmEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 11/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RhythmEncoder.h"
#include <math.h>

#define RATIO_TOLERANCE 0.1 // how much drift is taken into account when discovering integer ratios

RhythmEncoder::RhythmEncoder() : SpatialEncoder(21), prevDuration(0.0) {
    
}
RhythmEncoder::~RhythmEncoder() {
    
}

void RhythmEncoder::AddToken(float duration) {
    int ratio = -1;
    float bigValue, smallValue;
    
    if (prevDuration != 0.0) {
        bigValue = max(duration, prevDuration);
        smallValue = min(duration, prevDuration);
        ratio = floor(bigValue / smallValue);
        if (bigValue / smallValue - ratio < RATIO_TOLERANCE)  // we have a whole number ratio match!
            ratio = (min(ratio, 7) - 1);
        else {
            smallValue *= 0.5;      // original divided by 2
            ratio = floor(bigValue / smallValue);
            if (bigValue / smallValue - ratio < RATIO_TOLERANCE)  // we have a whole number ratio match!
                ratio = (min(ratio, 7) + 6);
            else {
                smallValue *= 0.66667;  // original divided by 3
                ratio = floor(bigValue / smallValue);
                if (bigValue / smallValue - ratio < RATIO_TOLERANCE)  // we have a whole number ratio match!
                    ratio = (min(ratio, 7) + 13);
                else {  // no match, for now
                    ratio = -1;
                }
            }
        }
    }
    prevDuration = duration;
    
    if (ratio != -1)
        SpatialEncoder::AddToken(ratio);
}