//
//  MappedEncoder.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "MappedEncoder.h"
MappedEncoder::MappedEncoder() : SpatialEncoder(0, true) {
    
}
MappedEncoder::~MappedEncoder() {
    
}

int MappedEncoder::GetMapping(int inToken)
{
    myMap::iterator it = encoderMapping.find(inToken);
    if (it == encoderMapping.end())
    {
        encoderMapping.insert(std::pair<int, int>(inToken, dimensions));
        return dimensions;
    } else
        return it->second;
}

void MappedEncoder::DoEncoding(int token) {
    SpatialEncoder::DoEncoding(GetMapping(token));
}
void MappedEncoder::DoEncoding(int* tokens, int size) {
    
    if (dimensions > 0)
        DecayEncoding(GetDecayAmount());
    
    for (int i = 0; i < size; i++)
        AddToken(tokens[i]);
}

void MappedEncoder::AddToken(int token) {
    SpatialEncoder::AddToken(GetMapping(token));
}
//void MappedEncoder::AddToken(int* tokens, int size) {    // input several tokens at once
//
//}