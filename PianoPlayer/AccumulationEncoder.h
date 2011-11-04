//
//  AccumulationEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "SpatialEncoder.h"

class AccumulationEncoder : public SpatialEncoder
{
private:
    float accumulationAmount;
public:
    AccumulationEncoder(int tokenCount, float accumulation, bool dynamic = false);
    ~AccumulationEncoder();
    
    void DoEncoding(int token);
    void AddToken(int token);
    
//    void DecayEncoding(const double& scalar);
    
    void SetAccumulationAmount(float a);
    float GetAccumulationAmount() { return accumulationAmount; }
    
    void Copy(AccumulationEncoder* that);
};