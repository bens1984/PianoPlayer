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
#include "OSCSend.h"
#include "TempoTracker.h"

using namespace std;

int main (int argc, const char * argv[])
{
    double rewards[11];
    bool analyze = true;
    double learnRates[4];
    learnRates[0] = 0.15; learnRates[1] = 0.05; learnRates[2] = 0.1; learnRates[3] = 0.15;
    TempoTracker* myTT = new TempoTracker(5000);
    ReinforcementLearner* myRL = new ReinforcementLearner(learnRates[0], learnRates[1], learnRates[2], learnRates[3]); //6, 0, 0.1, 0.95);
    OSCReceive myOSC;
    myOSC.StartReception();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    while (1) {
        OSCData* data = myOSC.ReadAPacket();
        if (data != 0x00)
        {
            if (data->header == oscUpdate && data->data.size() > 0) {
//                double *input = new double[data->data.size()];
//                for (int i = 0; i < data->data.size(); i++)
//                    input[i] = data->data[i];
//                cout << "input: ";
//                for (int i = 0; i < 6; i++)
//                    cout << input[i] << " ";
//                cout << endl;
                float IR = myRL->CalcPredictedReward(data->data[0], data->data[1], true, &rewards[0]);  // this is how we get the reward that we will receive for this observation
                OSCSend::getSingleton()->oscSend("/rewards", 11, &rewards[0]);
                
//                float IR = myRL->ProcessNewObservation(data->data[0], data->data[1]); //, data.data.size());
//               cout << "Category: " << myRL->GetChosenCategory() << " distance: " << myRL->GetDistance() << endl;
//                delete input;
                
//               cout << "Reward: " << IR << endl << endl;
                OSCSend::getSingleton()->oscSend("/IR", 1, &IR);
                
                if (!analyze)
                {
                    int nextStep = myRL->PredictMaximalInput();
                    OSCSend::getSingleton()->oscSend("/predict", 1, &nextStep);
                }
                
                myTT->AddPulse(data->data[1]);
                cout << "Tempo: " << myTT->CalculateTempo() << endl;
            } else if (data->header == oscSponteneity) {
                myRL->SetSponteneity(data->data[0]);
            } else if (data->header == oscReset) {
                ReinforcementLearner* oldRL = myRL;
                myRL = new ReinforcementLearner(learnRates[0], learnRates[1], learnRates[2], learnRates[3]);
                delete oldRL;
            } else if (data->header == oscAnalyze) {
                analyze = !analyze;
                if (analyze)
                    cout << "Switching to analysis only mode." << endl;
                else
                    cout << "Switching to predictive mode." << endl;
            } else if (data->header == oscLearnRates) {
                for (int i = 0; i < 4; i++)
                    learnRates[i] = data->data[i];
            } else if (data->header == oscRewardWeights) {
                myRL->SetRewardWeights(&data->data[0]);
            }
            delete data;
        } else
            usleep(10);
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

