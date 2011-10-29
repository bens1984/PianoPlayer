//
//  WaveletEncoder.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

// actually a quasi-wavelet processor for a stream of samples
//      keeps a series of averages of the samples
//      all are powers of 2 in length (1, 2, 4, 8, etc.)

class WaveletEncoder {
private:
    double * filterBank;
    int filterCount;
public:
    WaveletEncoder(int numOfBanks);
    ~WaveletEncoder();
    
    void AddSample(double sample);
    const double * GetEncoding();
    int GetEncoderSize();
    int GetDimensions() { return GetEncoderSize(); }
    
    void Copy(WaveletEncoder* that);
};