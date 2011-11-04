//
//  TonalityEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 11/2/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

class TonalityEncoder : public SpatialEncoder
{
public:
    TonalityEncoder(int tokenCount);
    
//    void DoEncoding(int token);
    void AddToken(int token);
    void DecayEncoding(const double& scalar);
};