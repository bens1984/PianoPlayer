//
//  fuzzyART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ReinforcementLearner.h"

ReinforcementLearner::ReinforcementLearner()  : fitVector(0x00), importance(0x00), inputCount(0), prevObs(-1), mySponteneity(NEW_THRESHOLD/21.0) /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/
{
    myArt = new ART(0, 0.3, 0.95);    // params: choice, learning rate, vigilance
    myEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    intervalEncoder = new SpatialEncoder(7);        // for encoding intervals
    othersEncoder = new SpatialEncoder(7);          // for other measures of the token sequence
    std::cout << "ReinforcementLearner -- ©2011 Benjamin Smith\n";
}
ReinforcementLearner::~ReinforcementLearner()
{
    delete myArt;
    delete myEncoder;
    delete intervalEncoder;
    delete othersEncoder;
    if (importance != 0x00)
        delete importance;
    if (fitVector != 0x00)
        delete fitVector;
}
double ReinforcementLearner::ProcessNewObservation(const int& obs)  // this is the next pitch that is observed
{
    myEncoder->DoEncoding(obs % 12);       // spatially encode the input
    if (prevObs != -1)
    {
        int interval = abs(obs-prevObs) % 12;
        if (interval > 6)
            interval = 12-interval;
        intervalEncoder->DoEncoding(interval);
    }
    int others[2];
    others[0] = (obs > prevObs ? 2 : (obs < prevObs ? 0 : 1));
    others[1] = ((obs-36) / 12) + 3;    // which octave + index into othersEncoder
    othersEncoder->DoEncoding(&others[0], 2);
    double featureVector[26]; //12+7+7];
    memcpy(&featureVector, &myEncoder->GetEncoding(), 96); //12*8);
    memcpy(&featureVector[12], &intervalEncoder->GetEncoding(), 56); //7*8);
    memcpy(&featureVector[19], &othersEncoder->GetEncoding(), 56); //7*8);
//    featureVector[19] = (obs > prevObs ? 1 : (obs < prevObs ? 0 : 0.5));
//    featureVector[20] = obs / 48.0;   // which octave we're in!
    OSCSend::getSingleton()->oscSend("/stm", 26, &featureVector[0]);
    
    prevObs = obs;
    
    myArt->ProcessNewObservation(&featureVector[0], 26);    // add it to the ART
    if (fitVector != 0x00)
        delete fitVector;
    fitVector = myArt->GetCategoryChoice(); // get the resonance of each category against this input.
    //        importance = myArt->GetImportance();
    
    chosenCategory = myArt->makeChoice();	// make a choice and learn from it. This modifies the resonances, so the must be received first
    
    inputCount += 1;                        // count up this input
    while (occurrences.size() < chosenCategory+1)
        occurrences.push_back(0);
    occurrences.at(chosenCategory) += 1;
    
    double importSum = 0.0;
//    if (importance != 0x00)                 // now calculate the importance vector
//        delete importance;
    if (occurrences.size() > 0)
    {
//        importance = new double[occurrences.size()];
        for (int i = 0; i < occurrences.size(); i++)
        {
//            importance[i] = fitVector[i]; // * (occurrences.at(i) / (double)inputCount);
            importSum += fitVector[i]; // * (occurrences.at(i) / (double)inputCount); //importance[i];
        }
//        delete importance;
    } else importSum = 0;
//    importSum = importSum;    // try magnitude of import vector
    //        cout << importSum << " residual: " << myArt->GetResidual() << endl;
    
    const double* w = myArt->GetWeights(0);
    OSCSend::getSingleton()->oscSend("/0", 26*2, w);
    delete w;
    
    return importSum * myArt->GetResidual();  // this is the intrinsic reward for observing this input!
}
int ReinforcementLearner::PredictMaximalInput()      // look one step ahead and calculate what input value would be most rewarding
{
    double reward[48]; //, rewardLR[12];      // hold the potential reward for each of our proposals
    for (int i = 0; i < 48; i++)    // try each of the pitches
    {
        reward[i] = CalcPredictedReward(i+36);
        //            cout << "predict cat " << cat << " produces " << res << ", reward: " << reward[i] << endl;
        //            rewardLR[i] = (1.0-importSum) * myArt->GetResidualLR();
    }
    OSCSend::getSingleton()->oscSend("/predictReward", 48, &reward[0]);
    double max = -1;
    int maxInput = -1;
    for (int i = 0; i < 48; i++)
    {
        if (reward[i] > max)
        {
            max = reward[i];
            maxInput = i;
        }
    }
    return maxInput + 36;
}
double ReinforcementLearner::CalcPredictedReward(int test)
{
//    double mImportance[occurrences.size()];
    int pitchClass = test % 12;
    SpatialEncoder tempEncoder(12);
    SpatialEncoder tempIntEncoder(7);
    SpatialEncoder tempOtherEncoder(7);
    
    tempEncoder.Copy(myEncoder);    // copy the 'real' encoder's state
    tempEncoder.AddToken(pitchClass);        // add the proposed input
    tempIntEncoder.Copy(intervalEncoder);
    int interval = abs(test-prevObs) % 12;
    if (interval > 6)
        interval = 12-interval;
    tempIntEncoder.AddToken(interval);
    
    tempOtherEncoder.Copy(othersEncoder);
    int others[2];
    others[0] = (test > prevObs ? 2 : (test < prevObs ? 0 : 1));
    others[1] = (test / 12) + 3;    // which octave + index into othersEncoder
    tempOtherEncoder.DoEncoding(&others[0], 2);

    double featureVector[26]; //12+7+7];
    memcpy(&featureVector, &tempEncoder.GetEncoding(), 96); //12*8);
    memcpy(&featureVector[12], &tempIntEncoder.GetEncoding(), 56); //7*8);
    memcpy(&featureVector[19], &tempOtherEncoder.GetEncoding(), 56); //7*8);
    
    myArt->ProcessNewObservation(&featureVector[0], 26);  // stick it in the ART and let it think about it.
    if (fitVector != 0x00)
        delete fitVector;
    fitVector = myArt->GetCategoryChoice();                         // get the resonance of each category
    
    int cat = myArt->PredictChoice();
    
    double importSum = 0.0;     // now calculate the importance vector, i.e. how boring something is.
    for (int j = 0; j < occurrences.size(); j++)
    {
//        mImportance[j] = fitVector[j] / occurrences.size(); // * (occurrences.at(j) / (double)inputCount);
        importSum += fitVector[j] / occurrences.size(); //mImportance[j];
    }
    importSum = importSum;    // try magnitude of import vector
    delete fitVector;   // it gets assigned just for us, so clear it out
    fitVector = 0x00;
    
    double res = myArt->GetResidual();
    if (res > 1)      // it's creating a new category, so treat it seperately
        return importSum * mySponteneity;
    else
        return res * importSum; //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new
}