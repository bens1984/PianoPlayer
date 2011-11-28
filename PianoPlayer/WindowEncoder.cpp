//
//  WindowEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 11/26/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "WindowEncoder.h"
#include <math.h>

WindowEncoder::WindowEncoder(int dim) : SpatialEncoder(dim * 2) {
    
}
WindowEncoder::~WindowEncoder() {
    
}

void WindowEncoder::DoEncoding(double token) {
    DecayEncoding(0);
    AddToken(token);
}
void WindowEncoder::DoEncoding(double token, double sign) {
    DecayEncoding(0);
    AddToken(token);
    myEncoder[1] = sign;
}
void WindowEncoder::AddToken(double token) {
    myEncoder[0] = fabs(token);
    myEncoder[1] = (token > 0 ? 1 : token == 0 ? 0.5 : 0);
}
void WindowEncoder::DecayEncoding(const double& scalar) {
    for (int i = dimensions-2; i >= 2; i-=2) {
        myEncoder[i] = myEncoder[i-2];
        myEncoder[i+1] = myEncoder[i-1];
    }
}