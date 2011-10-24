//
//  fuzzyART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#define IMPORTANCE_FACTOR 0.5       // the exponent for the importance vs residual measure. <1 weights resonance strongly, >1 weights residual strongly

#define RECENCY_DECAY_RATE  0.99     // how quickly the recency vector decays. This is how quickly ideas become familiar and no longer fresh

#include "ReinforcementLearner.h"

ReinforcementLearner::ReinforcementLearner()  : fitVector(0x00), importance(0x00), occurrencesTotal(0.0), prevObs(-1), mySponteneity(NEW_THRESHOLD/28.0), recencyTotal(0.0), useRecency(false) /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/
{
    myArt = new ART(0, 0.2, 0.95);    // params: choice, learning rate, vigilance
    myArt->AddResonanceGroup(0, 12, 12.0);   // tell it about the pitch group
    myArt->AddResonanceGroup(12, 7, 7.0);   // tell it about the interval group
    myArt->AddResonanceGroup(19, 11, 5.0);   // tell it about the "others" group
    myEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    intervalEncoder = new SpatialEncoder(7);        // for encoding intervals
    othersEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    othersEncoder->SetDecayAmount(0.4);
    
    tempEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    tempIntEncoder = new SpatialEncoder(7);        // for encoding intervals
    tempOtherEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    tempOtherEncoder->SetDecayAmount(0.4);
    
    upperArt = new ART(0, 0.2, 0.6);
    thirdArt = new ART(0, 0.2, 0.8);
    
    featureVector = (double*)malloc(sizeof(double)*30); //new double(27);
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
    int interval = obs-prevObs;
    if (prevObs != -1)
    {
        int intervalClass = abs(interval) % 12;
        if (intervalClass > 6)
            intervalClass = 12-intervalClass;
        intervalEncoder->DoEncoding(intervalClass);
    }
    int others[3];
    others[0] = (obs > prevObs ? 2 : (obs < prevObs ? 0 : 1));
    others[2] = ((obs-36) / 12) + 3;    // which octave + index into othersEncoder
    others[1] = (abs(interval) / 12) + 8;
    if (others[1] > 10) others[1] = 10;   // don't index beyond end of othersEncoder
    othersEncoder->DoEncoding(&others[0], 3);
    double * enc = myEncoder->GetEncoding();
    memcpy(featureVector, myEncoder->GetEncoding(), 12*sizeof(double)); //12*8);
    memcpy(featureVector+12, intervalEncoder->GetEncoding(), 7*sizeof(double)); //7*8);
    memcpy(featureVector+19, othersEncoder->GetEncoding(), 11*sizeof(double)); //8*8);
//    featureVector[26] = (obs-36) / 48.0;
//    featureVector[19] = (obs > prevObs ? 1 : (obs < prevObs ? 0 : 0.5));
//    featureVector[20] = obs / 48.0;   // which octave we're in!
    OSCSend::getSingleton()->oscSend("/stm", 30, featureVector);
    
    prevObs = obs;
    
    myArt->ProcessNewObservation(featureVector, 30);    // add it to the ART
    upperArt->ProcessNewObservation(featureVector, 30);
//    if (fitVector != 0x00)
//        delete fitVector;
    fitVector = myArt->GetCategoryChoice(); // get the resonance of each category against this input.
    int fitSize = myArt->GetCategoryCount();    // how long the fitVector is
    //        importance = myArt->GetImportance();
    thirdArt->ProcessNewObservation(fitVector, fitSize);
    
    chosenCategory = myArt->makeChoice();	// make a choice and learn from it. This modifies the resonances, so the must be received first
    upperArt->makeChoice();
    
    while (occurrences.size() < fitSize)
        occurrences.push_back(0.0);
    while (recency.size() < fitSize)
        recency.push_back(0.0);
    recencyTotal = 0.0;
    for (int i = 0; i < fitSize; i++)
    {
//        recency.at(i) += fitVector[i];
        recency.at(i) *= RECENCY_DECAY_RATE;
        if (recency.at(i) > recencyTotal)
            recencyTotal = recency.at(i);
//        recencyTotal += recency.at(i);      // could also consider recencyMax here, to get a vector with max dimension of 1 rather than Unity vector...
    }
    recency.at(chosenCategory) += 0.1;
    recencyTotal = 1;
    if (recency.at(chosenCategory) > recencyTotal)
        recencyTotal = recency.at(chosenCategory);
//    recencyTotal += 1;
    occurrences.at(chosenCategory) += 1; //fitVector[i];
    occurrencesTotal += 1; //fitVector[i];
    
    double importSum = 0.0;
    if (occurrences.size() > 0)
    {
        for (int i = 0; i < occurrences.size(); i++)
        {
//            importance[i] = fitVector[i]; // * (occurrences.at(i) / (double)inputCount);
// 10/19/2011 version:            
            if (!useRecency)
                importSum += fitVector[i] * (occurrences.at(i) / occurrencesTotal); //occurrences.size();
            else
                importSum += fitVector[i] * ((occurrences.at(i) / occurrencesTotal) * (1.0 - recency.at(i) / recencyTotal));
        }
    } else importSum = 0;
    delete fitVector;   // this is assigned just for us, we're responsible for cleaning it up.
    fitVector = 0x00;
    
    return pow(importSum, IMPORTANCE_FACTOR) * myArt->GetResidual() * upperArt->GetResidual();  // this is the intrinsic reward for observing this input!
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
    OSCSend::getSingleton()->oscSend("/recency", recency.size(), &recency[0]);
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
    int pitchClass = test % 12;
    
    tempEncoder->Copy(myEncoder);    // copy the 'real' encoder's state
    tempEncoder->DoEncoding(pitchClass);        // add the proposed input
    tempIntEncoder->Copy(intervalEncoder);
    int interval = abs(test-prevObs) % 12;
    if (interval > 6)
        interval = 12-interval;
    tempIntEncoder->DoEncoding(interval);
    
    tempOtherEncoder->Copy(othersEncoder);
    int others[3];
    others[0] = (test > prevObs ? 2 : (test < prevObs ? 0 : 1));
    others[2] = ((test-36) / 12) + 3;    // which octave + index into othersEncoder
    others[1] = (abs(test-prevObs) / 12) + 8;
    if (others[1] > 10) others[1] = 10;   // don't index beyond end of othersEncoder
    tempOtherEncoder->DoEncoding(&others[0], 3);

    memcpy(featureVector, tempEncoder->GetEncoding(), 96); //12*8);
    memcpy(featureVector+12, tempIntEncoder->GetEncoding(), 56); //7*8);
    memcpy(featureVector+19, tempOtherEncoder->GetEncoding(), 88); //11*8);
//    featureVector[26] = (test-36)/48.0;
    
    myArt->ProcessNewObservation(featureVector, 30);  // stick it in the ART and let it think about it.
    upperArt->ProcessNewObservation(featureVector, 30);

    fitVector = myArt->GetCategoryChoice();                         // get the resonance of each category
    int fitVectorSize = myArt->GetCategoryCount();
    
    int cat = myArt->PredictChoice();
    upperArt->PredictChoice();
    
    thirdArt->ProcessNewObservation(fitVector, fitVectorSize);
    thirdArt->PredictChoice();
    
    while (occurrences.size() < fitVectorSize)
        occurrences.push_back(0.0);
    while (recency.size() < fitVectorSize)
        recency.push_back(0.0);
    
    double importSum = 0.0;
    if (occurrences.size() > 0 && recency.size() > 0 && fitVectorSize > 0 && recencyTotal > 0 && occurrencesTotal > 0)
    {
        for (int i = 0; i < fitVectorSize; i++)
        {
            // 10/19/2011 version:            
            if (!useRecency)
                importSum += fitVector[i] * (occurrences.at(i) / occurrencesTotal);
            else
                importSum += fitVector[i] * ((occurrences.at(i) / occurrencesTotal) * (1.0 - recency.at(i) / recencyTotal));
        }
    } else importSum = 0;
    
//    importSum = importSum;    // try magnitude of import vector??
    delete fitVector;   // it gets assigned just for us, so clear it out
    fitVector = 0x00;
    
    double res = myArt->GetResidual() * upperArt->GetResidual() * thirdArt->GetResidual();
    if (myArt->GetResidual() == 1 || upperArt->GetResidual() == 1)      // it's creating a new category, so treat it seperately
        return importSum * mySponteneity * (1.0 / recencyTotal);
    else
        if (!useRecency)
            return res * pow(importSum, IMPORTANCE_FACTOR); //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new
        else
            return res * pow(importSum, IMPORTANCE_FACTOR) * (1.0 - recency.at(cat) / recencyTotal);    // here we want a lot of change * something boring, or minimal change * something new
}