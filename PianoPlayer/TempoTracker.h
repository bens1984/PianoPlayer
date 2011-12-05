//
//  TempoTracker.h
//  PianoPlayer
//
//  Created by Ben Smith on 12/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

// TempoTracker - implements a rough and ready tempo tracking model
//      takes in timing information
//      makes a good guess at what tempo the pulses are playing at
//      and returns said tempo

#include <vector>

using namespace std;

class TempoTracker {
private:
    vector<double> durations;
    vector<double> stackedDurations;
    
    double windowSize;
public:
    TempoTracker(double _windowSize);
    ~TempoTracker();
    
    void AddPulse(double duration);
    double CalculateTempo();
};