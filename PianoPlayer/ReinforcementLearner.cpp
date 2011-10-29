//
//  fuzzyART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
//#define UPPERART  // define to use a wide vigilance ART at the first level in addition to the fine/narrow/high vigilance ART
//#define UPPER_DERIVED_ART

#define IMPORTANCE_FACTOR 4.0       // the exponent for the importance vs residual measure. <1 weights resonance strongly, >1 weights residual strongly

#define FEATURE_SIZE 53             // number of elements in the first level feature vector
#define FEATURE_SIZE_1 0.018867925

#include "ReinforcementLearner.h"

ReinforcementLearner::ReinforcementLearner()  : fitVector(0x00), importance(0x00), occurrencesTotal(0.0), prevObs(-1), mySponteneity(NEW_THRESHOLD/(double)FEATURE_SIZE), recencyTotal(0.0), useRecency(false) /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/
{
    myArt = new ART(0, 0.5, 0.925);    // params: choice, learning rate, vigilance
    myArt->AddResonanceGroup(0, 12, 12.0);   // tell it about the pitch group
    myArt->AddResonanceGroup(12, 7, 7.0);   // tell it about the interval group
    myArt->AddResonanceGroup(19, 23, 12.0);   // tell it about the interval group
    myArt->AddResonanceGroup(42, 6, 10.0);   // tell it about the "others" group - direction & octave leap
    myArt->AddResonanceGroup(48, 5, 3.0);   // tell it about the "others" group - octave number (pitch / 12)
    
    myEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    intervalEncoder = new SpatialEncoder(30);        // for encoding intervals - 7 ICs followed by 11 down, unison, 11 up
    othersEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    othersEncoder->SetDecayAmount(0.5);
    
    tempEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    tempIntEncoder = new SpatialEncoder(30);        // for encoding intervals
    tempOtherEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    tempOtherEncoder->SetDecayAmount(0.5);
    
    thirdSTM = new SpatialEncoder(32, true);
    tempThirdSTM = new SpatialEncoder(32, true);
    thirdSTM->SetDecayAmount(0.7);
    
    upperEncoder = new MappedEncoder();
    upperArt = new ART(0, 0.2, 0.6);
    thirdArt = new ART(0, 0.5, 0.85);
    
    distanceEncoder = new WaveletEncoder(4);
    tempDistanceEncoder = new WaveletEncoder(4);
    curvatureEncoder = new WaveletEncoder(4);
    tempCurvatureEncoder = new WaveletEncoder(4);
    derivedArt = new ART(0, 0.5, 0.99);
    
    featureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    prevFeatureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    std::cout << "ReinforcementLearner -- ©2011 Benjamin Smith\n";
}
ReinforcementLearner::~ReinforcementLearner()
{
    delete myArt;
    delete myEncoder;
    delete intervalEncoder;
    delete othersEncoder;
    delete tempEncoder;
    delete tempIntEncoder;
    delete tempOtherEncoder;
    delete upperEncoder;
    delete upperArt;
    delete thirdSTM;
    delete tempThirdSTM;
    delete thirdArt;
    delete distanceEncoder;
    delete tempDistanceEncoder;
    delete curvatureEncoder;
    delete tempCurvatureEncoder;
    delete derivedArt;
    if (importance != 0x00)
        delete importance;
    if (fitVector != 0x00)
        delete fitVector;
    delete prevFeatureVector;
}

void ReinforcementLearner::CalcFeatureVectorDistance()
{
    double distance = 0.0;
    for (int i = 0; i < FEATURE_SIZE; i++)
        distance += pow(featureVector[i] - prevFeatureVector[i], 2.0);
    distanceEncoder->AddSample(pow(distance * FEATURE_SIZE_1, 0.1));
}
double ReinforcementLearner::ProcessNewObservation(const int& obs)  // this is the next pitch that is observed
{
    memcpy(prevFeatureVector, featureVector, FEATURE_SIZE*sizeof(double));
    
    int others[3];
    
    myEncoder->DoEncoding(obs % 12);       // spatially encode the pitch input
    
    int interval = obs-prevObs;
    if (prevObs != -1)
    {
        int intervalClass = abs(interval) % 12;
        if (intervalClass > 6)
            intervalClass = 12-intervalClass;
        others[0] = intervalClass;
        others[1] = (int)((interval / 12.0 - interval / 12) * 12.0) + 18; //11 + 7;   // 11 for the negative(down) intervals and 7 for the ICs
        intervalEncoder->DoEncoding(&others[0], 2);
    }
    others[0] = (obs > prevObs ? 2 : (obs < prevObs ? 0 : 1));
    others[1] = (abs(interval) / 12) + 3;
    if (others[1] > 5) others[1] = 5;   // don't index beyond end of othersEncoder
    others[2] = ((obs-36) / 12) + 6;    // which octave + index into othersEncoder
    othersEncoder->DoEncoding(&others[0], 3);
    memcpy(featureVector, myEncoder->GetEncoding(), 96); //12*sizeof(double)); //12*8);
    memcpy(featureVector+12, intervalEncoder->GetEncoding(), 240); //30*sizeof(double)); //7*8);
    memcpy(featureVector+42, othersEncoder->GetEncoding(), 88); //11*sizeof(double)); //8*8);
//    featureVector[26] = (obs-36) / 48.0;
//    featureVector[19] = (obs > prevObs ? 1 : (obs < prevObs ? 0 : 0.5));
//    featureVector[20] = obs / 48.0;   // which octave we're in!
    OSCSend::getSingleton()->oscSend("/stm", FEATURE_SIZE, featureVector);
    
    prevObs = obs;
    
    // calc inter-observation distance
    CalcFeatureVectorDistance();
    
    myArt->ProcessNewObservation(featureVector, FEATURE_SIZE);    // add it to the ART

    fitVector = myArt->GetCategoryChoice(); // get the resonance of each category against this input.
    //int fitSize = 
    myArt->GetCategoryCount();    // how long the fitVector is
    //        importance = myArt->GetImportance();
    
    double importSum = myArt->GetImportanceSum();
    
    chosenCategory = myArt->makeChoice();	// make a choice and learn from it. This modifies the resonances, so the must be received first
#if defined UPPERART 
    upperArt->ProcessNewObservation(featureVector, FEATURE_SIZE);
    upperArt->makeChoice();
#elif defined UPPER_DERIVED_ART
    derivedArt->ProcessNewObservation(distanceEncoder->GetEncoding(), distanceEncoder->GetEncoderSize());
    upperEncoder->DoEncoding(chosenCategory << 8);
    upperEncoder->AddToken(derivedArt->makeChoice());
    OSCSend::getSingleton()->oscSend("/distance", distanceEncoder->GetDimensions(), distanceEncoder->GetEncoding());
    OSCSend::getSingleton()->oscSend("/derived", upperEncoder->GetDimensions(), upperEncoder->GetEncoding());
    upperArt->ProcessNewObservation(upperEncoder->GetEncoding(), upperEncoder->GetDimensions());
    chosenCategory = upperArt->makeChoice();
#endif    
    thirdSTM->DoEncoding(chosenCategory);
    thirdArt->ProcessNewObservation(thirdSTM->GetEncoding(), thirdSTM->GetDimensions());
    fitVector = thirdArt->GetCategoryChoice();
    OSCSend::getSingleton()->oscSend("/3rdSTM", thirdSTM->GetDimensions(), thirdSTM->GetEncoding());
    OSCSend::getSingleton()->oscSend("/3rd", thirdArt->GetCategoryCount(), fitVector);
//    thirdArt->ProcessNewObservation(fitVector, fitSize);
    thirdArt->makeChoice();
//    while (occurrences.size() < fitSize)
//        occurrences.push_back(0.0);
//    while (recency.size() < fitSize)
//        recency.push_back(0.0);
//    recencyTotal = 0.0;
//    for (int i = 0; i < fitSize; i++)
//    {
////        recency.at(i) += fitVector[i];
//        recency.at(i) *= RECENCY_DECAY_RATE;
//        if (recency.at(i) > recencyTotal)
//            recencyTotal = recency.at(i);
////        recencyTotal += recency.at(i);      // could also consider recencyMax here, to get a vector with max dimension of 1 rather than Unity vector...
//    }
//    recency.at(chosenCategory) += 0.1;
//    recencyTotal = 1;
//    if (recency.at(chosenCategory) > recencyTotal)
//        recencyTotal = recency.at(chosenCategory);
////    recencyTotal += 1;
//    occurrences.at(chosenCategory) += 1; //fitVector[i];
//    occurrencesTotal += 1; //fitVector[i];
//    
//    double importSum = 0.0; //myArt->GetImportanceSum();
//    if (occurrences.size() > 0)
//    {
//        for (int i = 0; i < occurrences.size(); i++)
//        {
////            importance[i] = fitVector[i]; // * (occurrences.at(i) / (double)inputCount);
//// 10/19/2011 version:            
//            if (!useRecency)
//                importSum += fitVector[i] * (occurrences.at(i) / occurrencesTotal); //occurrences.size();
//            else
//                importSum += fitVector[i] * ((occurrences.at(i) / occurrencesTotal) * (1.0 - recency.at(i) / recencyTotal));
//        }
//    } else importSum = 0;
    delete fitVector;   // this is assigned just for us, we're responsible for cleaning it up.
    fitVector = 0x00;
    
    return pow(importSum, IMPORTANCE_FACTOR) * myArt->GetResidual() * thirdArt->GetResidual()
#if defined UPPERART || defined UPPER_DERIVED_ART
    * upperArt->GetResidual()
#endif
    ;  // this is the intrinsic reward for observing this input!
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
//    OSCSend::getSingleton()->oscSend("/recency", recency.size(), &recency[0]);
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
    int others[3];
    int pitchClass = test % 12;
    
    tempEncoder->Copy(myEncoder);    // copy the 'real' encoder's state
    tempEncoder->DoEncoding(pitchClass);        // add the proposed input
    
    tempIntEncoder->Copy(intervalEncoder);
    int interval = test-prevObs;
    int IC = abs(interval) % 12;
    if (IC > 6)
        IC = 12-IC;
    others[0] = IC;
    others[1] = (int)((interval / 12.0 - interval / 12) * 12.0) + 18; //11 + 7;   // 11 for the negative(down) intervals and 7 for the ICs
    tempIntEncoder->DoEncoding(&others[0], 2);
    
    tempOtherEncoder->Copy(othersEncoder);
    others[0] = (test > prevObs ? 2 : (test < prevObs ? 0 : 1));
    others[1] = (abs(test-prevObs) / 12) + 3;
    if (others[1] > 5) others[1] = 5;   // don't index beyond end of othersEncoder
    others[2] = ((test-36) / 12) + 6;    // which octave + index into othersEncoder
    tempOtherEncoder->DoEncoding(&others[0], 3);

    memcpy(featureVector, tempEncoder->GetEncoding(), 96); //12*8);
    memcpy(featureVector+12, tempIntEncoder->GetEncoding(), 240); //7*8);
    memcpy(featureVector+42, tempOtherEncoder->GetEncoding(), 88); //11*8);
//    featureVector[26] = (test-36)/48.0;
    
    CalcFeatureVectorDistance();
    
    myArt->ProcessNewObservation(featureVector, FEATURE_SIZE);  // stick it in the ART and let it think about it.  
    fitVector = myArt->GetCategoryChoice();                         // get the resonance of each category
//    int fitVectorSize = myArt->GetCategoryCount();
    
//    while (occurrences.size() < fitVectorSize)
//        occurrences.push_back(0.0);
//    while (recency.size() < fitVectorSize)
//        recency.push_back(0.0);
//    double importSum = 0.0;
//    if (occurrences.size() > 0 && recency.size() > 0 && fitVectorSize > 0 && recencyTotal > 0 && occurrencesTotal > 0)
//    {
//        for (int i = 0; i < fitVectorSize; i++)
//        {
//            // 10/19/2011 version:            
//            if (!useRecency)
//                importSum += fitVector[i] * (occurrences.at(i) / occurrencesTotal);
//            else
//                importSum += fitVector[i] * ((occurrences.at(i) / occurrencesTotal) * (1.0 - recency.at(i) / recencyTotal));
//        }
    //    } else importSum = 0;
    double importSum = myArt->GetImportanceSum(); //0.0;
    
    int cat = myArt->PredictChoice();
#if defined UPPERART 
    upperArt->ProcessNewObservation(featureVector, FEATURE_SIZE);
    upperArt->PredictChoice();
#elif defined UPPER_DERIVED_ART
    derivedArt->ProcessNewObservation(distanceEncoder->GetEncoding(), distanceEncoder->GetEncoderSize());
    upperEncoder->DoEncoding(chosenCategory << 8);
    upperEncoder->AddToken(derivedArt->makeChoice());
    upperArt->ProcessNewObservation(upperEncoder->GetEncoding(), upperEncoder->GetDimensions());
    double upperImport = upperArt->GetImportanceSum();
    cat = upperArt->PredictChoice();
#endif 
    
    tempThirdSTM->Copy(thirdSTM);
    tempThirdSTM->DoEncoding(cat);
    thirdArt->ProcessNewObservation(tempThirdSTM->GetEncoding(), tempThirdSTM->GetDimensions());
    //    thirdArt->ProcessNewObservation(fitVector, fitVectorSize);
    double thirdImportSum = thirdArt->GetImportanceSum();   // must be called before make/predictChoice as those function destroy the choice vector
    thirdArt->PredictChoice();
//    importSum += thirdArt->GetImportanceSum();
    
    delete fitVector;   // it gets assigned just for us, so clear it out
    fitVector = 0x00;
    
//    double res = myArt->GetResidual() 
//#ifdef UPPERART 
//    * upperArt->GetResidual()
//#endif
//    * thirdArt->GetResidual();
//    if (res > 0.05)
//        cout << myArt->GetResidual() << "::" << thirdArt->GetResidual() << endl;
////    res = (res > 0.05 ? 0.05 : res);
//    res = pow(res * 100.0, 2.0) * M_PI_2;
//    res = sin(res);   // TODO: this is scaled based on the observation that the residual tends to max out around 0.05.
//    if (myArt->GetResidual() == 1 || upperArt->GetResidual() == 1)      // it's creating a new category, so treat it seperately
//        return importSum * mySponteneity; // + thirdArt->GetImportanceSum() * mySponteneity * 10.0; // * (1.0 / recencyTotal);
//    else
//        if (!useRecency)
//    if (test == 0)
//        cout << thirdArt->GetResidual() << "--" << thirdImportSum << "++" << sin(pow(thirdArt->GetResidual(), 0.125) * 3.1) << endl;
    return sin(pow(myArt->GetResidual(), 0.5) * 3.1) * pow(importSum, IMPORTANCE_FACTOR) + 
        sin(pow(thirdArt->GetResidual(), 0.5) * 3.1) * 4.0 * pow(thirdImportSum, IMPORTANCE_FACTOR)
#ifdef UPPER_DERIVED_ART
        + sin(upperArt->GetResidual() * M_PI) * pow(upperImport, IMPORTANCE_FACTOR)
#endif
        ; //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new
//        else
//            return res * pow(importSum, IMPORTANCE_FACTOR) * (1.0 - recency.at(cat) / recencyTotal);    // here we want a lot of change * something boring, or minimal change * something new
}