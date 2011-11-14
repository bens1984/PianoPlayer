//
//  MappedEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

//  an extended SpatialEncoder that takes any arbitrary token, maps it to a sequential dimension
//      and then functions normally.

#include "SpatialEncoder.h"
#include <map.h>

class MappedEncoder : public SpatialEncoder
{
private:
    typedef std::map<int, int> myMap; 
    myMap* encoderMapping;
    
    int GetMapping(int inToken);
public:
    MappedEncoder();
    ~MappedEncoder();
    
    void DoEncoding(int token);
    void DoEncoding(int* tokens, int size);
    
    void AddToken(int token);
//    void AddToken(int* tokens, int size);    // input several tokens at once
    void Copy(MappedEncoder * that);
    myMap* FillMapping(myMap* that);  // stick my map into that
};