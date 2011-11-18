//
//  RhythmEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 11/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

class RhythmEncoder : public SpatialEncoder {
private:
    float prevDuration;
public:
    RhythmEncoder();
    ~RhythmEncoder();
    
    void AddToken(float duration);
};