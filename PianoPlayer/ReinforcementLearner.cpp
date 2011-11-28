//
//  fuzzyART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
//#define UPPERART  // define to use a wide vigilance ART at the first level in addition to the fine/narrow/high vigilance ART
//  #define UPPER_DERIVED_ART

#define IMPORTANCE_FACTOR 1.0       // the exponent for the importance vs residual measure. <1 weights resonance strongly, >1 weights residual strongly

#define FEATURE_SIZE 65             // number of elements in the first level feature vector
#define FEATURE_SIZE_1 0.015384615

#define MAXIMAL_RESIDUAL 0.01        // if the residual = this then the reward = 1!
#define MAXIMAL_RESIDUAL2 0.25        // maximum for L2 & L3 levels
#define RESIDUAL_CURVE 1.0        // exponent to raise residual amount to

#include "ReinforcementLearner.h"

ReinforcementLearner::ReinforcementLearner()  : fitVector(0x00), importance(0x00), occurrencesTotal(0.0), prevObs(-1), recencyTotal(0.0), useRecency(false), prevFitVector(0x00), prevFitVectorSize(0), fitVectorDistances(0x00), prevL1cat(-1), prevL2cat(-1) /*int dimensions, double _choice, double _learnRate, double _Vigilance)*/
{
    L1Art = new ART(0, 0.1, 0.975);    // params: choice, learning rate, vigilance
    
    L2STM = new MappedEncoder();
    L2STM->SetDecayAmount(0.2);
    L2Art = new ART(0, 0.05, 0.95);
    
    L3STM = new MappedEncoder();
    L3STM->SetDecayAmount(0.2);
    L3Art = new ART(0, 0.25, 0.925);
    
    distCurvEncoder = new WindowEncoder(7); // for distance and curvature
    L1DistanceArt = new ART(0, 0.2, 0.95);
    
    L2DistCurvEncoder = new WindowEncoder(7); //new WaveletEncoder(4);
    L2DistanceArt = new ART(0, 0.2, 0.95);
    
    pitchEncoder = new SpatialEncoder(12);     // for encoding pitch class inputs
    pitchEncoder->SetDecayAmount(0.4);
    //    tonalityEncoder = new TonalityEncoder(12); //, 0.025);
    intervalEncoder = new SpatialEncoder(25);   // 11 down, unison, 11 up intervals
    intervalEncoder->SetDecayAmount(0.2);
    //    intervalClassEncoder = new TonalityEncoder(7);        // for encoding intervals - 7 ICs followed by 
    //    intervalClassEncoder->SetDecayAmount(0.2);
    othersEncoder = new SpatialEncoder(11);          // for other measures of the token sequence
    othersEncoder->SetDecayAmount(0.4);
    shapeEncoder = new WindowEncoder(7);
////    tempDistanceEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//new SampledEncoder(8); //new WaveletEncoder(4);
//    curvatureEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//new SampledEncoder(8); //new WaveletEncoder(4);
////    tempCurvatureEncoder = new FeatureDistanceEncoder(FEATURE_SIZE);//SampledEncoder(8); //new WaveletEncoder(4);
//    derivedArt = new ART(0, 0.9, 0.95);
    
//    featureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    prevFeatureVector = (double*)malloc(sizeof(double)*FEATURE_SIZE); //new double(27);
    std::cout << "ReinforcementLearner -- ©2011 Benjamin Smith\n";
}
ReinforcementLearner::~ReinforcementLearner()
{
    delete L1Art;
//    delete othersArt;
//    delete bigArt;
//    delete secondArt;
    delete pitchEncoder;
//    delete tonalityEncoder;
    delete intervalEncoder;
//    delete intervalClassEncoder;
    delete othersEncoder;
    delete distCurvEncoder;
    delete shapeEncoder;
    delete L1DistanceArt;
//    delete tempEncoder;
//    delete tempTonalityEncoder;
//    delete tempIntervalEncoder;
//    delete tempIntervalClassEncoder;
//    delete tempOtherEncoder;
//    delete upperEncoder;
//    delete upperArt;
    delete L2STM;
//    delete tempThirdSTM;
    delete L2Art;
    delete L2DistCurvEncoder;
    delete L2DistanceArt;
    
    delete L3STM;
    delete L3Art;
////    delete tempDistanceEncoder;
//    delete curvatureEncoder;
////    delete tempCurvatureEncoder;
//    delete derivedArt;
    if (importance != 0x00)
        delete importance;
    if (fitVector != 0x00)
        delete fitVector;
    delete prevFeatureVector;
}

//void ReinforcementLearner::CalcFeatureVectorDistance(const double * featureVector)
//{
////    double distance = 0.0;
////    for (int i = 0; i < FEATURE_SIZE; i++)
////        distance += pow(featureVector[i] - prevFeatureVector[i], 2.0);
////    cout << "distance : " << distance << endl;
//    distanceEncoder->DoEncoding(&featureVector[0], FEATURE_SIZE); //pow(distance, 0.5) * 0.083333); //AddSample( // * FEATURE_SIZE_1
//}
double ReinforcementLearner::CalcFitVectorDistance(const double* fit)
{
    double distance = 0.0;
    for (int i = 0; i < prevFitVectorSize; i++)
    {
        fitVectorDistances[i] = fabs(fit[i] - prevFitVector[i]);
        distance += pow(fitVectorDistances[i], 2.0);
    }
    distance = sqrt(distance);
    return distance;
}
double ReinforcementLearner::DoFirstLevelDistance(bool retain, int &categoryID, const double* featureVector)
{
    L1Art->ProcessNewObservation(featureVector, FEATURE_SIZE);
    const double* fit = L1Art->GetCategoryChoice();
    int fitSize = L1Art->GetCategoryCount();
    
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
//    double distance = 
    CalcFitVectorDistance(fit);
    
    double ret = L1Art->GetImportanceSum();
    if (retain)
    {
        memcpy(prevFitVector, fit, fitSize*8);
        categoryID = L1Art->makeChoice();
    } else
        categoryID = L1Art->PredictChoice();
    
    delete fit;
    return ret;
}
double ReinforcementLearner::ProcessNewObservation(const int& obs, const float& duration)  // this is the next pitch that is observed
{    
//    int others[3];
    double rewards[11];
    
    int pitchClass = obs % 12;
    pitchEncoder->DoEncoding(pitchClass);       // spatially encode the pitch input
//    tonalityEncoder->DoEncoding(pitchClass);
    
    double * featureVector = (double*)malloc(FEATURE_SIZE*8);
    for (int i = 0; i < FEATURE_SIZE; i++)
        featureVector[i] = 0.0;
    
    int interval = obs-prevObs;
    if (prevObs != -1)
    {
        int intervalClass = abs(interval) % 12;
        if (intervalClass > 6)
            intervalClass = 12-intervalClass;
        int floorInt = (interval >= 0 ? floor(interval / 12.0) : ceil((interval-1)/12.0));
        intervalEncoder->DoEncoding((int)((interval / 12.0 - floorInt) * 12.0) + 11); //&others[0], 2);
//        intervalClassEncoder->DoEncoding(intervalClass);
        
        featureVector[(obs > prevObs ? 56 : (obs < prevObs ? 54 : 55))] = 1;
        featureVector[(abs(obs-prevObs) / 12 )+57] = 1;    // encode which octave we're in
        
        shapeEncoder->DoEncoding(min(max(interval / 12.0, -1.0), 1.0));
    }
    memcpy(featureVector, pitchEncoder->GetEncoding(), 96); //12*sizeof(double)); //12*8);
    memcpy(&featureVector[12], intervalEncoder->GetEncoding(), 200); //30*sizeof(double));
//    memcpy(&featureVector[35], tonalityEncoder->GetEncoding(), 96);
//    memcpy(&featureVector[47], intervalClassEncoder->GetEncoding(), 56);
//    featureVector[57] = (abs(interval) > 11);
//    featureVector[58] = (abs(interval) > 23);
    memcpy(&featureVector[37], shapeEncoder->GetEncoding(), 112);
    //    featureVector[59] = (obs-36) / 48.0;
    featureVector[FEATURE_SIZE-1] = (abs(interval) < 12);
    featureVector[FEATURE_SIZE-2] = (abs(interval) < 24);
    featureVector[FEATURE_SIZE-3] = (abs(interval) < 36);
    
    prevObs = obs;
    
//    pitchArt->ProcessNewObservation(featureVector, FEATURE_SIZE); //24);    // add it to the ART
//    intervalArt->ProcessNewObservation(&featureVector[35], FEATURE_SIZE-35); // 7 ICs + 23 intervals
//    othersArt->ProcessNewObservation(&featureVector[54], 11);
    
    rewards[5] = DoFirstLevelDistance(true, chosenCategory, featureVector);
    
    double L1distance = L1Art->calcDistance(chosenCategory, prevL1cat);
    double L1curvature = L1Art->calcCurvature(chosenCategory, prevL1cat);
//    cout << L1curvature << endl;
    prevL1cat = chosenCategory;
    distCurvEncoder->DoEncoding(L1distance, L1curvature);
    L1DistanceArt->ProcessNewObservation(distCurvEncoder->GetEncoding(), distCurvEncoder->GetDimensions());
    L1DistanceArt->makeChoice();
    
    int fitSize = L1Art->GetCategoryCount();
//    OSCSend::getSingleton()->oscSend("/derived", fitSize, fitVector);
//    OSCSend::getSingleton()->oscSend("/derived", fitSize, prevFitVector);
    OSCSend::getSingleton()->oscSend("/big", fitSize, fitVectorDistances);
    
//    fitVector = 
//    pitchArt->GetCategoryChoice(); // get the resonance of each category against this input. // if we don't need the vector then this call is supurfluous
//    intervalArt->GetCategoryChoice();
//    othersArt->GetCategoryChoice();
    //int fitSize = pitchArt->GetCategoryCount();    // how long the fitVector is
    //        importance = myArt->GetImportance();
    
//    rewards[0] = pitchArt->GetImportanceSum();
//    rewards[1] = intervalArt->GetImportanceSum();
//    rewards[2] = othersArt->GetImportanceSum();
//    double importSum = (rewards[0] * rewards[1] * rewards[2]);// * 0.33334;    // GetImportanceSum must be called before makeChoice, as makeChoice is destructive to the resonance measure
    
//    pitchArt->makeChoice();
//    intervalArt->makeChoice();
//    othersArt->makeChoice();
    
    // calc inter-observation distance
    //    CalcFeatureVectorDistance();    
//    distanceEncoder->DoEncoding(prevFitVector, prevFitVectorSize); //pow(distance, 0.5) * 0.083333); //AddSample( // * FEATURE_SIZE_1
//    derivedArt->ProcessNewObservation(distanceEncoder->GetEncoding(), distanceEncoder->GetDimensions()); //EncoderSize());
//    double derivedImport = derivedArt->GetImportanceSum();
//    rewards[4] = derivedImport;
//    derivedArt->makeChoice();
//#if defined UPPERART 
//    upperArt->ProcessNewObservation(fitVectorDistances, fitSize);
//    fitVector = upperArt->GetCategoryChoice();
//    double upperImport = upperArt->GetImportanceSum();
//    delete fitVector;
//    //chosenCategory = 
//    upperArt->makeChoice();
//#elif defined UPPER_DERIVED_ART
//    upperEncoder->DoEncoding(chosenCategory << 16);
//    upperEncoder->AddToken(derivedArt->makeChoice());
//    upperArt->ProcessNewObservation(upperEncoder->GetEncoding(), upperEncoder->GetDimensions());
//    chosenCategory = upperArt->makeChoice();
//#endif    
//    secondArt->ProcessNewObservation(prevFitVector, prevFitVectorSize);
//    secondArt->makeChoice();
    
//    others[0] = pitchArt->GetChosenCategoryID();
//    others[1] = intervalArt->GetChosenCategoryID() << 16;
    L2STM->DoEncoding(L1Art->GetChosenCategoryID()); //secondArt->GetChosenCategoryID());
    L2Art->ProcessNewObservation(L2STM->GetEncoding(), L2STM->GetDimensions());
    fitVector = L2Art->GetCategoryChoice();
    double thirdImportSum = L2Art->GetImportanceSum();
    rewards[3] = thirdImportSum;
    
    chosenCategory = L2Art->GetChosenCategoryID();
    double L2distance = L2Art->calcDistance(chosenCategory, prevL2cat);
    double L2curvature = L2Art->calcCurvature(chosenCategory, prevL2cat);
    prevL2cat = chosenCategory;
    L2DistCurvEncoder->DoEncoding(L2distance, L2curvature);
    L2DistanceArt->ProcessNewObservation(L2DistCurvEncoder->GetEncoding(), L2DistCurvEncoder->GetDimensions());
    L2DistanceArt->makeChoice();
    
    OSCSend::getSingleton()->oscSend("/3rdSTM", L2STM->GetDimensions(), L2STM->GetEncoding());
    OSCSend::getSingleton()->oscSend("/3rd", L2Art->GetCategoryCount(), fitVector);
//    thirdArt->ProcessNewObservation(fitVector, fitSize);
    L2Art->makeChoice();
    
    L3STM->DoEncoding(L2Art->GetChosenCategoryID());
    L3Art->ProcessNewObservation(L3STM->GetEncoding(), L3STM->GetDimensions());
    L3Art->makeChoice();
    
    delete fitVector;   // this is assigned just for us, we're responsible for cleaning it up.
    fitVector = 0x00;
    
    memcpy(prevFeatureVector, featureVector, FEATURE_SIZE*sizeof(double));
    delete featureVector;
    
    int cats[5];
    cats[0] = L1Art->GetChosenCategoryID();
    cats[1] = L1DistanceArt->GetChosenCategoryID();
    cats[2] = L2Art->GetChosenCategoryID();
    cats[3] = L2DistanceArt->GetChosenCategoryID();
    cats[4] = L3Art->GetChosenCategoryID();
    OSCSend::getSingleton()->oscSend("/cats", 5, &cats[0]);
    
    return 1.0;
}
int ReinforcementLearner::PredictMaximalInput()      // look one step ahead and calculate what input value would be most rewarding
{
    __block double* reward = (double*)malloc(48*8); //[48]; //, rewardLR[12];      // hold the potential reward for each of our proposals
//    dispatch_apply(48, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(size_t i){ reward[i] = 0; reward[i] = CalcPredictedReward(i+36);});
    
//    dispatch_queue_t queue = dispatch_queue_create("com.app.task",NULL);
    for (int i = 0; i < 48; i++)    // try each of the pitches
    {
        reward[i] = CalcPredictedReward(i+36, 0, false);
        //            cout << "predict cat " << cat << " produces " << res << ", reward: " << reward[i] << endl;
        //            rewardLR[i] = (1.0-importSum) * myArt->GetResidualLR();
    }
    OSCSend::getSingleton()->oscSend("/predictReward", 48, &reward[0]);
//    OSCSend::getSingleton()->oscSend("/recency", recency.size(), &recency[0]);
    double max = -1;
    int maxInput = -1;
    for (int i = 47; i >= 0; i--)
    {
        if (reward[i] > max)
        {
            max = reward[i];
            maxInput = i;
        }
    }
    
    free(reward);
    
    return maxInput + 36;
}
double ReinforcementLearner::CalcPredictedReward(int test, const float& duration, bool store, double* rewards)
{
    int others[3];
    WindowEncoder tempDCEncoder(7);
    int pitchClass = test % 12;
    
    double featureVector[FEATURE_SIZE]; // = (double*)malloc(FEATURE_SIZE*8);
    for (int i = 0; i < FEATURE_SIZE; i++)
        featureVector[i] = 0.0;
    
    if (!store) {
        SpatialEncoder tempEncoder(12);
        tempEncoder.Copy(pitchEncoder);    // copy the 'real' encoder's state
        tempEncoder.DoEncoding(pitchClass);        // add the proposed input
        memcpy(&featureVector, tempEncoder.GetEncoding(), 96); //12*8);
    } else {
        pitchEncoder->DoEncoding(pitchClass);
        memcpy(&featureVector, pitchEncoder->GetEncoding(), 96); //12*8);
    }
    
//    TonalityEncoder tempTonalityEncoder(12);
//    tempTonalityEncoder.Copy(tonalityEncoder);
//    tempTonalityEncoder.DoEncoding(pitchClass);
    
    //    TonalityEncoder tempIntervalClassEncoder(7);
    //    tempIntervalClassEncoder.Copy(intervalClassEncoder);
    int interval = 0;
    if (prevObs != -1) {
        interval = test-prevObs;
        int IC = abs(interval) % 12;
        if (IC > 6)
            IC = 12-IC;
    //    others[0] = IC;
        //    others[1] = (int)((interval / 12.0 - interval / 12) * 12.0) + 18; //11 + 7;   // 11 for the negative(down) intervals and 7 for the ICs
//        if (interval > 0)
//            interval = (interval-1) % 12 + 1 + 11;
//        else if (interval < 0)
//            interval = -((abs(interval)-1) % 12 + 1) + 11; //((interval + 1) / 12.0 - (interval + 1) / 12) * 12.0 - 1;
//        else interval = 12;
        //        tempIntervalEncoder.DoEncoding((int)interval); //((interval / 12.0 - interval / 12) * 12.0) + 11); //&others[0], 2);
        int floorInt = (interval >= 0 ? floor(interval / 12.0) : ceil((interval-1)/12.0));
        floorInt = (int)((interval / 12.0 - floorInt) * 12.0);
        if (!store) {
            SpatialEncoder tempIntervalEncoder(23);
            tempIntervalEncoder.Copy(intervalEncoder);
            tempIntervalEncoder.DoEncoding(floorInt + 11); //&others[0], 2);
            memcpy(&featureVector[12], tempIntervalEncoder.GetEncoding(), 200);
        } else {
            intervalEncoder->DoEncoding(floorInt + 11);
            memcpy(&featureVector[12], intervalEncoder->GetEncoding(), 200);
        }
//        tempIntervalClassEncoder.DoEncoding(IC);
    //    tempIntEncoder->DoEncoding(&others[0], 2);
        
        featureVector[(test > prevObs ? 56 : (test < prevObs ? 54 : 55))] = 1;
        featureVector[(abs(test-prevObs) / 12 )+57] = 1;    // encode which octave we're in
        
        if (store) {
            shapeEncoder->DoEncoding(min(max(interval / 12.0, -1.0), 1.0));
            memcpy(&featureVector[37], shapeEncoder->GetEncoding(), 112);
        } else {
            WindowEncoder tempShapeEncoder(7);
            tempShapeEncoder.Copy(shapeEncoder);
            tempShapeEncoder.DoEncoding(min(max(interval / 12.0, -1.0), 1.0));
            memcpy(&featureVector[37], tempShapeEncoder.GetEncoding(), 112);
        }
    }

//    memcpy(&featureVector[35], tempTonalityEncoder.GetEncoding(), 96); //12*8);
//    memcpy(&featureVector[47], tempIntervalClassEncoder.GetEncoding(), 56); //7*8);
//    featureVector[57] = (abs(interval) > 11);
//    featureVector[58] = (abs(interval) > 23);
//    featureVector[59] = (test-36) / 48.0;
    featureVector[FEATURE_SIZE-1] = (abs(interval) < 12);
    featureVector[FEATURE_SIZE-2] = (abs(interval) < 24);
    featureVector[FEATURE_SIZE-3] = (abs(interval) < 36);
    
    if (store)
        OSCSend::getSingleton()->oscSend("/stm", FEATURE_SIZE, &featureVector[0]);
//    CalcFeatureVectorDistance();
    
//    pitchArt->ProcessNewObservation(featureVector, FEATURE_SIZE); //24);  // stick it in the ART and let it think about it. 
//    intervalArt->ProcessNewObservation(&featureVector[35], FEATURE_SIZE-35);
////    othersArt->ProcessNewObservation(&featureVector[54], 11);
////    fitVector = pitchArt->GetCategoryChoice();                         // get the resonance of each category
////    int fitVectorSize = myArt->GetCategoryCount();
//    FeatureDistanceEncoder tempDistanceEncoder(FEATURE_SIZE);
//    tempDistanceEncoder.Copy(distanceEncoder);
////    tempDistanceEncoder->DoEncoding(featureVector, FEATURE_SIZE);
//    tempDistanceEncoder.DoEncoding(prevFitVector, prevFitVectorSize);
//    
//    double pitchImport, intervalImport, othersImport;
    int cat;
//    double bigImport = 
    DoFirstLevelDistance(store, cat, &featureVector[0]);
//    if (rewards != 0x00)
//        rewards[5] = bigImport;
    
    if (store) {
        prevObs = test;
        memcpy(prevFeatureVector, &featureVector[0], FEATURE_SIZE*sizeof(double));
    }
    
    double L1distance = L1Art->calcDistance(cat, prevL1cat);
    double L1curvature = L1Art->calcCurvature(cat, prevL1cat);
    if (!store) {
        tempDCEncoder.Copy(distCurvEncoder);
        tempDCEncoder.DoEncoding(L1distance, L1curvature);
        L1DistanceArt->ProcessNewObservation(tempDCEncoder.GetEncoding(), tempDCEncoder.GetDimensions());
        L1DistanceArt->PredictChoice();
    } else {
        prevL1cat = cat;
        distCurvEncoder->DoEncoding(L1distance, L1curvature);
        L1DistanceArt->ProcessNewObservation(distCurvEncoder->GetEncoding(), distCurvEncoder->GetDimensions());
        if (rewards != 0x00) {
            OSCSend::getSingleton()->oscSend("/distance", distCurvEncoder->GetDimensions(), distCurvEncoder->GetEncoding());
            rewards[4] = L1DistanceArt->makeChoice();
        } else
            L1DistanceArt->makeChoice();
    }
    
    others[0] = L1Art->GetChosenCategoryID();
//    others[1] = L1DistanceArt->GetChosenCategoryID() << 16;
    if (!store) {
        MappedEncoder tempL2STM;
        tempL2STM.Copy(L2STM);
        tempL2STM.DoEncoding(&others[0], 1); //secondArt->GetChosenCategoryID());
        L2Art->ProcessNewObservation(tempL2STM.GetEncoding(), tempL2STM.GetDimensions());
    } else {
        L2STM->DoEncoding(&others[0], 1); //secondArt->GetChosenCategoryID());
        L2Art->ProcessNewObservation(L2STM->GetEncoding(), L2STM->GetDimensions());
        
        const double * fitVector = L2Art->GetCategoryChoice();
        OSCSend::getSingleton()->oscSend("/3rdSTM", L2STM->GetDimensions(), L2STM->GetEncoding());
        OSCSend::getSingleton()->oscSend("/3rd", L2Art->GetCategoryCount(), fitVector);
        delete fitVector;
    }

    cat = L2Art->GetChosenCategoryID();
    double L2distance = L2Art->calcDistance(cat, prevL2cat);    
    double L2curvature = L2Art->calcCurvature(cat, prevL2cat);
    if (!store) {
        tempDCEncoder.Copy(L2DistCurvEncoder);
        tempDCEncoder.DoEncoding(L2distance, L2curvature);
        L2DistanceArt->ProcessNewObservation(tempDCEncoder.GetEncoding(), tempDCEncoder.GetDimensions());
        L2DistanceArt->PredictChoice();
        L2Art->PredictChoice();
    } else {
        L2DistCurvEncoder->DoEncoding(L2distance, L2curvature);
        L2DistanceArt->ProcessNewObservation(L2DistCurvEncoder->GetEncoding(), L2DistCurvEncoder->GetDimensions());
        L2DistanceArt->makeChoice();
        L2Art->makeChoice();
    }
    
    others[0] = L2Art->GetChosenCategoryID();
//    others[1] = L2DistanceArt->GetChosenCategoryID() << 16;
    if (!store) {
        MappedEncoder tempL3STM;
        tempL3STM.Copy(L3STM);
        tempL3STM.DoEncoding(&others[0], 1); //secondArt->GetChosenCategoryID());
    //    tempL3STM.DoEncoding(L2Art->GetChosenCategoryID());
        L3Art->ProcessNewObservation(tempL3STM.GetEncoding(), tempL3STM.GetDimensions());
        L3Art->PredictChoice();
    } else {
        L3STM->DoEncoding(&others[0], 1); //secondArt->GetChosenCategoryID());
        //    tempL3STM.DoEncoding(L2Art->GetChosenCategoryID());
        L3Art->ProcessNewObservation(L3STM->GetEncoding(), L3STM->GetDimensions());
        L3Art->makeChoice();
        
        int cats[5];
        cats[0] = L1Art->GetChosenCategoryID();
        cats[1] = L1DistanceArt->GetChosenCategoryID();
        cats[2] = L2Art->GetChosenCategoryID();
        cats[3] = L2DistanceArt->GetChosenCategoryID();
        cats[4] = L3Art->GetChosenCategoryID();
        OSCSend::getSingleton()->oscSend("/cats", 5, &cats[0]);
    }
    
    return CalcReward(rewards);
}
double ReinforcementLearner::CalcReward(double* rewards)
{
    double bigRes = L1Art->GetResidual();
    if (rewards != 0x00)
        rewards[6] = bigRes;
    if (bigRes >= MAXIMAL_RESIDUAL)
        bigRes = MAXIMAL_RESIDUAL / bigRes;
    else
        bigRes = bigRes / MAXIMAL_RESIDUAL;
    
    double L1distRes = L1DistanceArt->GetResidual();
    if (rewards != 0x00)
        rewards[7] = L1distRes;
    if (L1distRes >= MAXIMAL_RESIDUAL)
        L1distRes = MAXIMAL_RESIDUAL / L1distRes;
    else
        L1distRes = L1distRes / MAXIMAL_RESIDUAL, 2.0;
    double L2Res = L2Art->GetResidual();
    if (rewards != 0x00)
        rewards[8] = L2Res;
    if (L2Res >= MAXIMAL_RESIDUAL2)
        L2Res = MAXIMAL_RESIDUAL2 / L2Res;
    else
        L2Res = pow(L2Res / MAXIMAL_RESIDUAL2, 2.0);
    
    double L2distRes = L2DistanceArt->GetResidual();
    if (rewards != 0x00)
        rewards[9] = L2distRes;
    if (L2distRes >= MAXIMAL_RESIDUAL)
        L2distRes = MAXIMAL_RESIDUAL / L2distRes;
    else
        L2distRes = L2distRes / MAXIMAL_RESIDUAL;
    double thirdRes = L3Art->GetResidual();
    if (rewards != 0x00)
        rewards[10] = thirdRes;
    if (thirdRes > MAXIMAL_RESIDUAL2)
        thirdRes = MAXIMAL_RESIDUAL2 / thirdRes;
    else
        thirdRes = thirdRes / MAXIMAL_RESIDUAL2;
//    delete featureVector;
    
    return //(intervalArt->GetResidual() > MAXIMAL_RESIDUAL) * intervalImport * 0.5 + 
//        res * 0.5 + intRes * 0.5 //(pitchArt->GetResidual() > MAXIMAL_RESIDUAL)
//    return (1.0 - intervalArt->GetResidual()) * intervalImport + (1.0 - pitchArt->GetResidual()) * pow(pitchImport, 0.5)
//    return ((pitchArt->GetResidual() > 0.01) * pitchImport * 0.3 + (intervalArt->GetResidual() > 0.001) * intervalImport * 25.0 +
    //            (othersArt->GetResidual() > 0.01) * othersImport * 0.1 +
//    (bigRes + L2Res + thirdRes)
    bigRes + L2Res + thirdRes // + L1distRes * 0.25 + L2distRes)
//            + (secondArt->GetResidual() > MAXIMAL_RESIDUAL) * secondImport // + derivedImport * 1.0
#ifdef UPPERART
//        + upperImport * (upperArt->GetResidual() > 0.03)) * 0.13
#else
//        ) * 0.165
#endif
#ifdef UPPER_DERIVED_ART
//        + sin(upperArt->GetResidual() * M_PI) * pow(upperImport, IMPORTANCE_FACTOR)
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


void ReinforcementLearner::Save(string filename) {
    
}
void ReinforcementLearner::Load(string filename) {
    
}