//
//  WindowEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 11/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
// takes a sequence of floats(doubles) and encodes them as a sliding window function
// each element of the vector represents a time step, new values are pushed in at the bottom,
// old values pop off the top

#include "SpatialEncoder.h"

class WindowEncoder : public SpatialEncoder {
  
    
public:
    WindowEncoder(int dim);
    ~WindowEncoder();
    
    void DoEncoding(double token);
    void DoEncoding(double token, double sign);     // sets elements 0 & 1 to token & sign
    void AddToken(double token);
    virtual void DecayEncoding(const double& scalar);
};
