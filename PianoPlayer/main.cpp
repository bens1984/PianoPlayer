//
//  main.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 9/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "ReinforcementLearner.h"
#include "OSCReceive.h"

using namespace std;

int main (int argc, const char * argv[])
{
    ReinforcementLearner* myRL = new ReinforcementLearner(); //6, 0, 0.1, 0.95);
    OSCReceive myOSC;
    myOSC.StartReception();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    while (1) {
        OSCData data = myOSC.ReadAPacket();
        if (data.header == oscUpdate) {
            double *input = new double[data.data.size()];
            for (int i = 0; i < data.data.size(); i++)
                input[i] = data.data[i];
//            input[0] = (rand() % 100) * 0.01;
            myRL->ProcessNewObservation(input[0]); //, data.data.size());
            cout << "input: ";
            for (int i = 0; i < 6; i++)
                cout << input[i] << " ";
            cout << endl;
            cout << "Category: " << myRL->GetChosenCategory() << " distance: " << myRL->GetDistance() << endl;
            delete input;
        }
    }    
//    double* input = new double[6];
//    for (int i = 0; i < 25; i++)
//    {
//        for (int j = 0; j < 6; j++)
//            input[j] = (rand() % 100) * 0.01;
//        myART->ProcessNewObservation(input, 6);
//        cout << "input: " << input[0] << endl;
//        cout << "Category: " << myART->GetChosenCategory() << " distance: " << myART->GetDistance() << endl;
//    }
    return 0;
}

