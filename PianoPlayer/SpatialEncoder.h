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
    bool        dynamicGrow;    // allow the size of the STM to grow if new tokens are input?
public:
    SpatialEncoder(int tokenCount, bool dynamic = false);
    ~SpatialEncoder();
    
    void DoEncoding(int token);
    void DoEncoding(int* tokens, int size);
    
    void AddToken(int token);
    void AddToken(int* tokens, int size);    // input several tokens at once
    void DecayEncoding(const double& scalar);
    
    double* GetEncoding();
    int GetDimensions();
    double GetDecayAmount();
    DecayModel GetDecayModel();
    
    void SetDecayAmount(const double& decay);
    void SetDecayModel(DecayModel model);
    
    void Copy(SpatialEncoder* that);  // copy 'that' into us
};