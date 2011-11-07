//
//  fuzzyART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#define UPPERART  // define to use a wide vigilance ART at the first level in addition to the fine/narrow/high vigilance ART
//  #define UPPER_DERIVED_ART

#define IMPORTANCE_FACTOR 1.0       // the exponent for the importance vs residual measure. <1 weights resonance strongly, >1 weights residual strongly

#define FEATURE_SIZE 65             // number of elements in the first level feature vector
#define FEATURE_SIZE_1 0.015384615

#define MAXIMAL_RESIDUAL 0.04        // if the residual = this then the reward = 1!
#define RESIDUAL_CURVE 1.0        // exponent to raise residual amount to

#include "ReinforcementLearner.h"

ReinforcementLearner::ReinforcementLearner()  : fitVector(0x00), importance(0x00), occurrencesTotal(0.0), prevObs(-1), mySponteneity(NEW_THRESHOLD/(double)FEATURE_SIZE), recencyTotal(0.0), useRecency(false), prevFitVector(0x00), prevFitVectorSize(0), fitVectorDistances(0x00) /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/
{
    pitchArt = new ART(0, 0.5, 0.925);    // params: choice, learning rate, vigilance
    intervalArt = new ART(0, 0.5, 0.925);
    othersArt = new ART(0, 0.5, 0.925);
    bigArt = new ART(0, 0.9, 0.8);
//    myArt->AddResonanceGroup(0, 12, 12.0);   // tell it about the pitch group
//    myArt->AddResonanceGroup(12, 7, 7.0);   // tell it about the interval group
//    myArt->AddResonanceGroup(19, 23, 12.0);   // tell it about the interval group
//    myArt->AddResonanceGroup(42, 6, 10.0);   // tell it about the "others" group - direction & octave leap
//    myArt->AddResonanceGroup(48, 5, 3.0);   // tell it about the "others" group - octave number (pitch / 12)
    
    pitchEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    tonalityEncoder = new TonalityEncoder(12); //, 0.025);
    intervalEncoder = new SpatialEncoder(23);   // 11 down, unison, 11 up intervals
    intervalClassEncoder = new TonalityEncoder(7);        // for encoding intervals - 7 ICs followed by 
    othersEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    othersEncoder->SetDecayAmount(0.3);
    
    tempEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    tempTonalityEncoder = new TonalityEncoder(12); //, 0.025);    // for pitch classes as a tonality measure
    tempIntervalEncoder = new SpatialEncoder(23);
    tempIntervalClassEncoder = new TonalityEncoder(7);        // for encoding intervals
    tempOtherEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    tempOtherEncoder->SetDecayAmount(0.3);
    
    thirdSTM = new MappedEncoder();
    tempThirdSTM = new MappedEncoder();
//    thirdSTM->SetDecayAmount(0.8);
    
#if defined UPPERART || defined UPPER_DERIVED_ART
    upperEncoder = new MappedEncoder();
    upperEncoder->SetDecayAmount(0.8);
    upperArt = new ART(0, 0.9, 0.9);
#endif
    thirdArt = new ART(0, 0.9, 0.8);
    
    distanceEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//SampledEncoder(8); //new WaveletEncoder(4);
    tempDistanceEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//new SampledEncoder(8); //new WaveletEncoder(4);
    curvatureEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//new SampledEncoder(8); //new WaveletEncoder(4);
    tempCurvatureEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//SampledEncoder(8); //new WaveletEncoder(4);
    derivedArt = new ART(0, 0.9, 0.95);
    
    featureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    prevFeatureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    std::cout << "ReinforcementLearner -- ©2011 Benjamin Smith\n";
}
ReinforcementLearner::~ReinforcementLearner()
{
    delete pitchArt;
    delete intervalArt;
    delete othersArt;
    delete bigArt;
    delete pitchEncoder;
    delete tonalityEncoder;
    delete intervalEncoder;
    delete intervalClassEncoder;
    delete othersEncoder;
    delete tempEncoder;
    delete tempTonalityEncoder;
    delete tempIntervalEncoder;
    delete tempIntervalClassEncoder;
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
//    double distance = 0.0;
//    for (int i = 0; i < FEATURE_SIZE; i++)
//        distance += pow(featureVector[i] - prevFeatureVector[i], 2.0);
//    cout << "distance : " << distance << endl;
    distanceEncoder->DoEncoding(&featureVector[0], FEATURE_SIZE); //pow(distance, 0.5) * 0.083333); //AddSample( // * FEATURE_SIZE_1
}
double ReinforcementLearner::CalcFitVectorDistance()
{
    double distance = 0.0;
    for (int i = 0; i < prevFitVectorSize; i++)
    {
        fitVectorDistances[i] = fabs(fitVector[i] - prevFitVector[i]);
        distance += pow(fitVectorDistances[i], 2.0);
    }
    distance = sqrt(distance);
    return distance;
}
double ReinforcementLearner::DoFirstLevelDistance(bool retain, int &categoryID)
{
    bigArt->ProcessNewObservation(featureVector, FEATURE_SIZE);
    fitVector = bigArt->GetCategoryChoice();
    int fitSize = bigArt->GetCategoryCount();
//    double distance = 
    CalcFitVectorDistance();
//    if (retain) 
//        distanceEncoder->DoEncoding(distance);
//    else
//        tempDistanceEncoder->DoEncoding(distance);
    if (retain && prevFitVectorSize != fitSize)
    {
        if (prevFitVector != 0x00)
            delete prevFitVector;
        if (fitVectorDistances != 0x00)
            delete fitVectorDistances;
        prevFitVector = (double*)malloc(fitSize*sizeof(double));
        fitVectorDistances = (double*)malloc(fitSize*sizeof(double));
        prevFitVectorSize = fitSize;
    }
    double ret = bigArt->GetImportanceSum();
    if (retain)
    {
        memcpy(prevFitVector, fitVector, fitSize*8);
        categoryID = bigArt->makeChoice();
    } else
        categoryID = bigArt->PredictChoice();
    
    delete fitVector;
    return ret;
}
double ReinforcementLearner::ProcessNewObservation(const int& obs)  // this is the next pitch that is observed
{
    memcpy(prevFeatureVector, featureVector, FEATURE_SIZE*sizeof(double));
    
    int others[3];
    double rewards[11];
    
    int pitchClass = obs % 12;
    pitchEncoder->DoEncoding(pitchClass);       // spatially encode the pitch input
    tonalityEncoder->DoEncoding(pitchClass);
    
    int interval = obs-prevObs;
    if (prevObs != -1)
    {
        int intervalClass = abs(interval) % 12;
        if (intervalClass > 6)
            intervalClass = 12-intervalClass;
//        others[0] = intervalClass;
//        others[1] = (int)((interval / 12.0 - interval / 12) * 12.0) + 18; //11 + 7;   // 11 for the negative(down) intervals and 7 for the ICs
        intervalEncoder->DoEncoding((int)((interval / 12.0 - interval / 12) * 12.0)); //&others[0], 2);
        intervalClassEncoder->DoEncoding(intervalClass);
    }
    others[0] = (obs > prevObs ? 2 : (obs < prevObs ? 0 : 1));
    others[1] = (abs(interval) / 12) + 3;
    if (others[1] > 5) others[1] = 5;   // don't index beyond end of othersEncoder
    others[2] = ((obs-36) / 12) + 6;    // which octave + index into othersEncoder
    othersEncoder->DoEncoding(&others[0], 2);
    memcpy(featureVector, pitchEncoder->GetEncoding(), 96); //12*sizeof(double)); //12*8);
    memcpy(featureVector+12, tonalityEncoder->GetEncoding(), 96);
    memcpy(featureVector+24, intervalClassEncoder->GetEncoding(), 56);
    memcpy(featureVector+31, intervalEncoder->GetEncoding(), 184); //30*sizeof(double));
    memcpy(featureVector+54, othersEncoder->GetEncoding(), 88); //11*sizeof(double));
    featureVector[57] = (abs(interval) > 11);
    featureVector[58] = (abs(interval) > 23);
    featureVector[59] = (obs-36) / 12.0;
    
    OSCSend::getSingleton()->oscSend("/stm", FEATURE_SIZE, featureVector);
    
    prevObs = obs;
    
    pitchArt->ProcessNewObservation(featureVector, 24);    // add it to the ART
    intervalArt->ProcessNewObservation(&featureVector[24], 30); // 7 ICs + 23 intervals
    othersArt->ProcessNewObservation(&featureVector[54], 11);
    
    double bigImport = rewards[5] = DoFirstLevelDistance(true, chosenCategory);
    
    int fitSize = bigArt->GetCategoryCount();
    OSCSend::getSingleton()->oscSend("/derived", fitSize, fitVector);
//    OSCSend::getSingleton()->oscSend("/derived", fitSize, prevFitVector);
    OSCSend::getSingleton()->oscSend("/big", fitSize, fitVectorDistances);
    
//    fitVector = 
//    pitchArt->GetCategoryChoice(); // get the resonance of each category against this input. // if we don't need the vector then this call is supurfluous
//    intervalArt->GetCategoryChoice();
//    othersArt->GetCategoryChoice();
    //int fitSize = pitchArt->GetCategoryCount();    // how long the fitVector is
    //        importance = myArt->GetImportance();
    
    rewards[0] = pitchArt->GetImportanceSum();
    rewards[1] = intervalArt->GetImportanceSum();
    rewards[2] = othersArt->GetImportanceSum();
    double importSum = (rewards[0] * rewards[1] * rewards[2]);// * 0.33334;    // GetImportanceSum must be called before makeChoice, as makeChoice is destructive to the resonance measure
    
//    chosenCategory = pitchArt->makeChoice() << 16;	// make a choice and learn from it. This modifies the resonances, so the must be received first
//    chosenCategory += intervalArt->makeChoice() << 8;
//    chosenCategory += othersArt->makeChoice();
    pitchArt->makeChoice();
    intervalArt->makeChoice();
    othersArt->makeChoice();
    
    // calc inter-observation distance
    //    CalcFeatureVectorDistance();    
    distanceEncoder->DoEncoding(fitVector, prevFitVectorSize); //pow(distance, 0.5) * 0.083333); //AddSample( // * FEATURE_SIZE_1
    derivedArt->ProcessNewObservation(distanceEncoder->GetEncoding(), distanceEncoder->GetDimensions()); //EncoderSize());
    double derivedImport = derivedArt->GetImportanceSum();
    rewards[4] = derivedImport;
    derivedArt->makeChoice();
#if defined UPPERART 
    upperArt->ProcessNewObservation(fitVectorDistances, fitSize);
    fitVector = upperArt->GetCategoryChoice();
    double upperImport = upperArt->GetImportanceSum();
    delete fitVector;
    //chosenCategory = 
    upperArt->makeChoice();
#elif defined UPPER_DERIVED_ART
    upperEncoder->DoEncoding(chosenCategory << 8);
    upperEncoder->AddToken(derivedArt->makeChoice());
    upperArt->ProcessNewObservation(upperEncoder->GetEncoding(), upperEncoder->GetDimensions());
    chosenCategory = upperArt->makeChoice();
#endif    
    thirdSTM->DoEncoding(chosenCategory);
    thirdArt->ProcessNewObservation(thirdSTM->GetEncoding(), thirdSTM->GetDimensions());
    fitVector = thirdArt->GetCategoryChoice();
    double thirdImportSum = thirdArt->GetImportanceSum();
    rewards[3] = thirdImportSum;
//    OSCSend::getSingleton()->oscSend("/3rdSTM", thirdSTM->GetDimensions(), thirdSTM->GetEncoding());
//    OSCSend::getSingleton()->oscSend("/3rd", thirdArt->GetCategoryCount(), fitVector);
//    thirdArt->ProcessNewObservation(fitVector, fitSize);
    thirdArt->makeChoice();
    
    delete fitVector;   // this is assigned just for us, we're responsible for cleaning it up.
    fitVector = 0x00;
    
//    cout << pitchArt->GetResidual() << ", " << intervalArt->GetResidual() << ", " << othersArt->GetResidual() << endl;
    rewards[6] = pitchArt->GetResidual();
    rewards[7] = intervalArt->GetResidual();
    rewards[8] = othersArt->GetResidual();
    double res = rewards[8] + rewards[6] + (rewards[7] * 0.25); //pitchArt->GetResidual() + intervalArt->GetResidual() + othersArt->GetResidual();
//    cout << res;
//    res = (res > 2.0 ? 2.0 : res) * 0.5;
    cout << "----" << res << endl; //", sin: " << sin(powd * 4.7124) << endl;
    if (res != 0)
        res = 0.05 / res;
    res = (res > 1 ? 1.0 / res : res);
//    double powd = pow(res * 0.33334, RESIDUAL_CURVE);
//    return sin(powd * 4.7124) 
    double bigRes = bigArt->GetResidual();
    rewards[9] = bigRes;
    if (bigRes > 0)
        bigRes = 0.1 / bigRes;
    bigRes = (bigRes > 1 ? 1.0 : bigRes); // / bigRes : bigRes);
    double thirdRes = thirdArt->GetResidual();
    rewards[10] = thirdRes;
    if (thirdRes > 0)
        thirdRes = 0.005 / thirdRes;
    thirdRes = (thirdRes > 1 ? 1.0 : thirdRes); // / thirdRes : thirdRes);
    
//    OSCSend::getSingleton()->oscSend("/rewards", 10, &rewards[0]);
    
    return (res * pow(importSum, IMPORTANCE_FACTOR) * 0.5 + bigRes * pow(bigImport, 1.0) + thirdRes * pow(thirdImportSum, 1.0)) * 0.334; // + derivedImport * 1.0) * 0.25
    //+ sin(pow(thirdArt->GetResidual(), 0.5) * 3.1) * 1.0 * pow(thirdImportSum, IMPORTANCE_FACTOR)
#ifdef UPPER_DERIVED_ART
    + sin(upperArt->GetResidual() * M_PI) * pow(upperImport, IMPORTANCE_FACTOR)
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
double ReinforcementLearner::CalcPredictedReward(int test, double* rewards)
{
    int others[3];
    int pitchClass = test % 12;
    
    tempEncoder->Copy(pitchEncoder);    // copy the 'real' encoder's state
    tempEncoder->DoEncoding(pitchClass);        // add the proposed input
    tempTonalityEncoder->Copy(tonalityEncoder);
    tempTonalityEncoder->DoEncoding(pitchClass);
    
    tempIntervalEncoder->Copy(intervalEncoder);
    tempIntervalClassEncoder->Copy(intervalClassEncoder);
    int interval = test-prevObs;
    int IC = abs(interval) % 12;
    if (IC > 6)
        IC = 12-IC;
//    others[0] = IC;
//    others[1] = (int)((interval / 12.0 - interval / 12) * 12.0) + 18; //11 + 7;   // 11 for the negative(down) intervals and 7 for the ICs
    tempIntervalEncoder->DoEncoding((int)((interval / 12.0 - interval / 12) * 12.0)); //&others[0], 2);
    tempIntervalClassEncoder->DoEncoding(IC);
//    tempIntEncoder->DoEncoding(&others[0], 2);
    
    tempOtherEncoder->Copy(othersEncoder);
    others[0] = (test > prevObs ? 2 : (test < prevObs ? 0 : 1));
    others[1] = (abs(test-prevObs) / 12) + 3;
    if (others[1] > 5) others[1] = 5;   // don't index beyond end of othersEncoder
    others[2] = ((test-36) / 12) + 6;    // which octave + index into othersEncoder
    tempOtherEncoder->DoEncoding(&others[0], 2);

    memcpy(featureVector, tempEncoder->GetEncoding(), 96); //12*8);
    memcpy(featureVector+12, tempTonalityEncoder->GetEncoding(), 96); //12*8);
    memcpy(featureVector+24, tempIntervalClassEncoder->GetEncoding(), 56); //7*8);
    memcpy(featureVector+31, tempIntervalEncoder->GetEncoding(), 184);
    memcpy(featureVector+54, tempOtherEncoder->GetEncoding(), 88); //11*8);
    featureVector[57] = (abs(interval) > 11);
    featureVector[58] = (abs(interval) > 23);
    featureVector[59] = (test-36) / 12.0;
//    featureVector[26] = (test-36)/48.0;
    
//    CalcFeatureVectorDistance();
    
    pitchArt->ProcessNewObservation(featureVector, 24);  // stick it in the ART and let it think about it. 
    intervalArt->ProcessNewObservation(&featureVector[24], 30);
    othersArt->ProcessNewObservation(&featureVector[54], 11);
//    fitVector = pitchArt->GetCategoryChoice();                         // get the resonance of each category
//    int fitVectorSize = myArt->GetCategoryCount();
    tempDistanceEncoder->Copy(distanceEncoder);
//    tempDistanceEncoder->DoEncoding(featureVector, FEATURE_SIZE);
    tempDistanceEncoder->DoEncoding(prevFitVector, prevFitVectorSize);
    
    double pitchImport, intervalImport, othersImport;
    int cat;
    double bigImport = DoFirstLevelDistance(false, cat);
    if (rewards != 0x00) {
        rewards[5] = bigImport;
        pitchImport = rewards[0] = pitchArt->GetImportanceSum();
        rewards[1] = intervalImport = intervalArt->GetImportanceSum();
        rewards[2] = othersImport = othersArt->GetImportanceSum();
        //importSum = (rewards[0] * rewards[1] * rewards[2]); // * 0.33334;
    } else {
        pitchImport = pitchArt->GetImportanceSum();
        intervalImport = intervalArt->GetImportanceSum();
        othersImport = othersArt->GetImportanceSum(); // * 0.33334;
    }
        
//    int cat = pitchArt->PredictChoice() << 16;
//    cat += intervalArt->PredictChoice() << 8;
//    cat += othersArt->PredictChoice();
    pitchArt->PredictChoice();
    intervalArt->PredictChoice();
    othersArt->PredictChoice();
    
    derivedArt->ProcessNewObservation(tempDistanceEncoder->GetEncoding(), tempDistanceEncoder->GetDimensions());
    double derivedImport = derivedArt->GetImportanceSum();
    if (rewards != 0x00) {
        OSCSend::getSingleton()->oscSend("/distance", distanceEncoder->GetDimensions(), distanceEncoder->GetEncoding());
        rewards[4] = derivedImport;
    }
    derivedArt->PredictChoice();
#if defined UPPERART 
    upperArt->ProcessNewObservation(fitVectorDistances, prevFitVectorSize);
    OSCSend::getSingleton()->oscSend("/upper", prevFitVectorSize, prevFitVector);
    double upperImport = upperArt->GetImportanceSum();
    //cat = 
    upperArt->PredictChoice();
#elif defined UPPER_DERIVED_ART
    upperEncoder->DoEncoding(chosenCategory << 8);
    upperEncoder->AddToken(derivedArt->makeChoice());
    upperArt->ProcessNewObservation(upperEncoder->GetEncoding(), upperEncoder->GetDimensions());
    double upperImport = upperArt->GetImportanceSum();
    cat = upperArt->PredictChoice();
#endif 
    
    tempThirdSTM->Copy(thirdSTM);
    tempThirdSTM->DoEncoding(cat);
    thirdArt->ProcessNewObservation(tempThirdSTM->GetEncoding(), tempThirdSTM->GetDimensions());
    double thirdImportSum = thirdArt->GetImportanceSum();   // must be called before make/predictChoice as those function destroy the choice vector
    if (rewards != 0x00) {
        rewards[3] = thirdImportSum;
        OSCSend::getSingleton()->oscSend("/3rdSTM", thirdSTM->GetDimensions(), thirdSTM->GetEncoding());
        OSCSend::getSingleton()->oscSend("/3rd", thirdArt->GetCategoryCount(), fitVector);
    }
    thirdArt->PredictChoice();
    
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
//    if (test == 36)
////        cout << thirdArt->GetResidual() << "--" << thirdImportSum << "++" << sin(pow(thirdArt->GetResidual(), 0.125) * 3.1) << endl;
//        cout << pitchArt->GetResidual() << ", " << intervalArt->GetResidual() << ", " << othersArt->GetResidual() << ", " << importSum << endl;
    double res;
    if (rewards != 0x00) {
        rewards[6] = pitchArt->GetResidual();
        rewards[7] = intervalArt->GetResidual();
        rewards[8] = othersArt->GetResidual();
        res = (rewards[6] + rewards[7] + (rewards[8] * 0.25));
        res = (res > MAXIMAL_RESIDUAL);
    } else {
        res = (pitchArt->GetResidual() + intervalArt->GetResidual() + othersArt->GetResidual());
        res = (res > MAXIMAL_RESIDUAL);
    }
    //    res = (res > 2.0 ? 2.0 : res) * 0.5;
    if (res != 0)
        res = 0.01 / res;
    res = (res > 1 && res != 0 ? 1.0 / res : res);
    
    double bigRes = bigArt->GetResidual();
    if (rewards != 0x00)
        rewards[9] = bigRes;
    bigRes = (bigRes > MAXIMAL_RESIDUAL);
//    if (bigRes > 0)
//        bigRes = 0.1 / bigRes;
//    bigRes = (bigRes > 1 ? 1.0 / bigRes : bigRes);
    double thirdRes = thirdArt->GetResidual();
    if (rewards != 0x00)
        rewards[10] = thirdRes;
    thirdRes = (thirdRes > MAXIMAL_RESIDUAL);
//    if (thirdRes > 0)
//        thirdRes = 0.005 / thirdRes;
//    thirdRes = (thirdRes > 1 ? 1.0 / thirdRes : thirdRes);
    
    return (res * pow((pitchImport * intervalImport * othersImport), IMPORTANCE_FACTOR) * 0.5 + bigRes * pow(bigImport, 1.0) + thirdRes * pow(thirdImportSum, 1.0)) * 0.334 // + derivedImport * 1.0
#ifdef UPPERART
        + upperImport * (upperArt->GetResidual() > MAXIMAL_RESIDUAL)
#endif
#ifdef UPPER_DERIVED_ART
        + sin(upperArt->GetResidual() * M_PI) * pow(upperImport, IMPORTANCE_FACTOR)
#endif
        ; //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new
//    return sin(pow((pitchArt->GetResidual() + intervalArt->GetResidual() + othersArt->GetResidual()) * 0.66, 0.5) * 3.1) * pow(importSum, IMPORTANCE_FACTOR) + 
//    sin(pow(thirdArt->GetResidual(), 0.5) * 3.1) * 4.0 * pow(thirdImportSum, IMPORTANCE_FACTOR)
//#ifdef UPPER_DERIVED_ART
//    + sin(upperArt->GetResidual() * M_PI) * pow(upperImport, IMPORTANCE_FACTOR)
//#endif
//    ; //1.0 - fabs(0.07 - res); // * importSum;               // here we want a lot of change * something boring, or minimal change * something new

//        else
//            return res * pow(importSum, IMPORTANCE_FACTOR) * (1.0 - recency.at(cat) / recencyTotal);    // here we want a lot of change * something boring, or minimal change * something new
}