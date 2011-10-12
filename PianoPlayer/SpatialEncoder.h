#pragma once
//
//  SpatialEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

//  linear STM spatial encoder model
#include <iostream>

using namespace std;

enum DecayModel {
    LinearDecay,
    ExponentialDecay
};

class SpatialEncoder
{
private:
    int         dimensions;
    double*     myEncoder;
    double      decayAmount;
    DecayModel  myDecay;
public:
    SpatialEncoder(int tokenCount);
    ~SpatialEncoder();
    
    void AddToken(int token);
    void DecayEncoding(const double& scalar);
    
    const double& GetEncoding();
    int GetDimensions();
    double GetDecayAmount();
    DecayModel GetDecayModel();
    
    void SetDecayAmount(const double& decay);
    void SetDecayModel(DecayModel model);
    
    void Copy(SpatialEncoder* that);  // copy 'that' into us
};