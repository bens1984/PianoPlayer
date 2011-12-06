//
//  ART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <dispatch/dispatch.h>
#include "ART.h"

ART::ART(double _choice, double _learnRate, double _Vigilance) : mDimensions(19), residual(0), choices(0x00), inputCount(0), maxRecency(0)
{
    mCategories.clear();
    mCategories.push_back(new ArtCategory(mDimensions));
    mObservations.push_back(0);
    mRecency.push_back(0);
    
    input = new double[mDimensions*2];
    choices = new double[1];    // size of category vector
    choiceSize = 1;
    
    mChoice = _choice;
    mLearnRate = _learnRate;
    mVigilance = _Vigilance;
    recentChoice = -1;
}
ART::~ART()
{
//    for (int i = 0; i < mCategories.size(); i++)
//        delete mCategories.at(i);
    mCategories.clear();
    if (input != 0x00)
        delete input;
    if (choiceSize > 0)
        delete choices;
    choiceSize = 0;
}
void ART::ProcessNewObservation(const double *in, int length)
{
    setInput(in, length);
#ifdef USING_RECENCY
    DecayRecency();
#endif
    normalizeInput();
    complementCode();
    FillCategoryChoice();
}
void ART::setVigilance(double v)
{
    mVigilance = v;
}
void ART::setLearnRate(double v)
{
    mLearnRate = v;
}
void ART::setChoice(double v)
{
    mChoice = v;
}
double ART::GetResidual()
{
    return residual;
}

const double* ART::GetCategoryChoice()
{
    if (mCategories.size() > 0)
    {
        double* ret = new double[mCategories.size()];
        memcpy(ret, choices, mCategories.size()*sizeof(double));
        return ret;
    } else return 0x00;
}

int ART::GetCategoryCount() // how many categories?
{
    return mCategories.size();
}

void ART::normalizeInput()
{			
    // limit input to [0,1] - normalize the input vector
    double max = 0;
    for (int i = 0; i < mDimensions; i++)
        max = (input[i] > max ? input[i] : max);
    if (max > 1)
    {
        for (int i = 0; i < mDimensions; i++)
            input[i] /= max;
    }
}
inline void ART::complementCode()
{
    for (int i = 0; i < mDimensions*2; i+=2)	// create complement of input - complement coding
        input[i+1] = 1.0 - input[i];
}
void ART::setInput(const double *_in, int size)
{
//    if (size > 0 && size > mDimensions)
//    {
        mDimensions = size;
        if (input != 0x00)
            delete input;
        input = (double*)malloc(sizeof(double)*size*2); //new double(size*2);
        for (int i = 0; i < mCategories.size(); i++)
            mCategories.at(i)->resizeCategory(mDimensions);
//    }
    for (int i = 0; i < size; i++)
    {
        input[i*2] = _in[i];
        input[i*2+1] = 1.0 - _in[i];
    }
}
void ART::AddResonanceGroup(int startIndex, int groupSize, double weight)
{
    mResonanceWeights.push_back(ResonanceGroup(startIndex, groupSize, weight));
}

//	set the mVigilance just high enough to reset the chosen category and look again.
int ART::increaseVigilance()
{
    if (recentChoice > -1)
    {
        double vig = mCategories.at(recentChoice)->GetVigilance(input,mDimensions*2) + 0.01f;	// increase by a little bit.
        recentChoice = makeChoice(vig);
    }
    return recentChoice;
}
void ART::FillCategoryChoice()
{
//    if (choiceSize < mCategories.size())
//    {
    if (choices != 0x00)
        delete choices;
    choices = (double*)malloc(sizeof(double) * mCategories.size()); //new double[mCategories.size()];
    choiceSize = mCategories.size();
//    }
    // check against all existing categories, and 1 empty one
    if (mDimensions > 0)
    {
        if (mResonanceWeights.size() == 0)
            mResonanceWeights.push_back(ResonanceGroup(0, mDimensions, mDimensions));
        dispatch_apply(mCategories.size(), dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), 
                       ^(size_t i){ choices[i] = mCategories.at(i)->Choose(input, mDimensions*2, mChoice, mResonanceWeights);});
//        for (int i = 0; i < mCategories.size(); i++)
//            choices[i] = mCategories.at(i)->Choose(input, mDimensions*2, mChoice, mResonanceWeights);  // pass in a descriptor for the feature vector
    }
}
void ART::DecayRecency()
{
    for (int i = 0; i < mRecency.size(); i++)
        mRecency.at(i) *= RECENCY_DECAY_RATE;
}
int ART::makeChoice()
{
    return makeChoice(mVigilance);
}
int ART::makeChoice(double workingVigilance)
{
    int maxIndex = -1;
    bool chosen = false;		// check mVigilance stuff here...
    while (!chosen)
    {
        // find largest match value
        double max = 0;
        for (int i = 0; i < mCategories.size(); i++)
            if (choices[i] > max)
            {
                max = choices[i];
                maxIndex = i;
            }
        if (maxIndex != -1)
        {          // if above vigilence then learn from it
            if (mCategories.at(maxIndex)->mVigilance(input,mDimensions*2,workingVigilance) || mCategories.size() == 1)		// learn!
            {
//                OSCSend::getSingleton()->oscSend("/in", mDimensions*2, input);
                residual = mCategories.at(maxIndex)->Learn(input,mDimensions*2,mLearnRate); //learn
                while (maxIndex >= mCategories.size()-1)	// committed the previous uncommitted category, so add a new blank one.
                {
                    mCategories.push_back(new ArtCategory(mDimensions));
                    mObservations.push_back(0);
                    mRecency.push_back(0);
                    //residual = 1;
                }
                chosen = true;
                recentChoice = maxIndex;
            }
            else	// failed the mVigilance test.
            {
                choices[maxIndex] = -1; // reset, try again
                maxIndex = -1;
            }
        } else
            chosen = true;
    }	// otherwise look again.
    if (maxIndex > -1)
    {
        inputCount++;
        mObservations.at(maxIndex) = min(1.0, mObservations.at(maxIndex)+OBSERVATION_VALUE);
#ifdef USING_RECENCY
        mRecency.at(maxIndex) += 0.1;
#endif
    }
    return maxIndex;
}
double ART::PredictChoice()
{
    return PredictChoice(mVigilance);
}
double ART::PredictChoice(double workingVigilance)
{
    int maxIndex = -1;
    bool chosen = false;		// check mVigilance stuff here...
    while (!chosen)
    {
        // find largest match value
        double max = 0;
        for (int i = 0; i < mCategories.size(); i++)
            if (choices[i] > max)
            {
                max = choices[i];
                maxIndex = i;
            }
        if (maxIndex != -1) // we've exhausted the search and no match was found!
        {          // if above vigilence then learn from it
//            if (mCategories.at(maxIndex)->mVigilance(input,mDimensions*2,workingVigilance) || mCategories.size() == 1)		// this is the match!
//            {
//                if (maxIndex == mCategories.size()-1)   // it would be a new category
//                    residual = mDimensions; //1.0-workingVigilance; //1.0; //mDimensions;   // new categories are too chaotic for us to privilege
//                else
                    residual = mCategories.at(maxIndex)->GetResidual(input,mDimensions*2,1.0); //mLearnRate); // <- figure out how much residual would occur
                chosen = true;
                recentChoice = maxIndex;
//            }
//            else	// failed the mVigilance test.
//            {
//                choices[maxIndex] = -1; // reset, try again
//                maxIndex = -1;
//            }
        } else
            chosen = true;
    }	// otherwise look again.
    if (maxIndex > -1)
        return choices[maxIndex];
    else
        return -1;
}
int ART::GetChosenCategoryID() {
    return recentChoice;
}
double ART::calcDistance(int cat)	// use set input and calculate distance to center of specified category
{
    if (cat < mCategories.size())
        return mCategories.at(cat)->distance(input);
    else
        return -1;
}
double ART::calcDistance(int thatCategory, int thisCategory)    // calculate the distance between the two IDd categories
{
    if (thatCategory > -1 && thatCategory < mCategories.size() && thisCategory > -1 && thisCategory < mCategories.size())
        return mCategories.at(thatCategory)->distance(mCategories.at(thisCategory)->GetWeights());
    else
        return -1;
}
double ART::calcCurvature(int thatCategory, int thisCategory)    // calculate the angle between the two IDd categories
{
    if (thatCategory > -1 && thatCategory < mCategories.size() && thisCategory > -1 && thisCategory < mCategories.size())
        return mCategories.at(thatCategory)->curvature(mCategories.at(thisCategory)->GetWeights());
    else
        return -1;
}
const double* ART::getWeights()	// return all of the weights of all of our categories
{
    double *weights = (double*)malloc(mCategories.size()*mDimensions*2*sizeof(double));
    for (int i = 0; i < mCategories.size(); i++)
        memcpy(weights+(i*mDimensions*2), mCategories.at(i)->GetWeights(), mDimensions*2*sizeof(double));
    return weights;
}
const double* ART::GetWeights(int index)
{
    if (mDimensions > 0)
    {
        double *weights = (double*)malloc(mDimensions*2*sizeof(double));
        memcpy(weights, mCategories.at(index)->GetWeights(), mDimensions*2*sizeof(double));
        return weights;
    } else return 0x00;
}

double ART::GetImportanceSum()
{
    double importance = 0.0;
    if (inputCount > 0) {   
#ifdef USING_RECENCY
        double recencyMax = 1.0;
        for (int i = 0; i < mRecency.size(); i++)
        {
            recencyMax = (mRecency.at(i) > recencyMax ? mRecency.at(i) : recencyMax);
        }
#endif
        for (int i = 0; i < mCategories.size(); i++)
        {
#ifdef USING_RECENCY
            importance += choices[i] * (mObservations.at(i) / (double)inputCount) * (1.0 - (mRecency.at(i) / recencyMax));
#else
            importance += choices[i]; // * mObservations.at(i); // / (double)inputCount);
#endif
        }
    }
    return importance / mCategories.size();
}

char* ART::Serialize(int &size) {
    int categorySize;
    char* categoryData;
    
    if (mCategories.size() > 0) {   // we always have 1 category, allocated in our constructor
        categoryData = mCategories.at(0)->Serialize(categorySize);  // all categories SHOULD be the same size
        
        size = sizeof(int) * 3 + sizeof(double) * 3 + categorySize * mCategories.size();
        char* data = (char*)malloc(size);
        int index = 0;
        
        memcpy(data, &mDimensions, sizeof(int));
        index += sizeof(int);
        memcpy(data+index, &mChoice, sizeof(double));
        index += sizeof(double);
        memcpy(data+index, &mLearnRate, sizeof(double));
        index += sizeof(double);
        memcpy(data+index, &mVigilance, sizeof(double));
        index += sizeof(double);
        
        memcpy(data+index, &categorySize, sizeof(int));     // size of each category
        index += sizeof(int);
        categorySize = mCategories.size();
        memcpy(data+index, &categorySize, sizeof(int));     // how many categories
        index += sizeof(int);
        memcpy(data+index, categoryData, categorySize);     // the first one, since we already got it
        index += categorySize;
        
        for (int i = 1; i < mCategories.size(); i++) {      // all the other categories
            categoryData = mCategories.at(i)->Serialize(categorySize);
            memcpy(data+index, categoryData, categorySize);
            index += categorySize;
        }
        
    //    vector<ResonanceGroup> mResonanceWeights;
    //    vector<double> mObservations;     // how many times each category has been seen. trying to measure how "confident" we are in the observation
    //    int inputCount;  // how many inputs we have seen
    //    vector<double> mRecency;
    //    double maxRecency;
    //    double *input, *choices;
    //    int recentChoice, choiceSize;	// the most recently chosen category, the size of the choices array
    //    double residual;    // how much the chosen category changed with the last input/learning step

        return data;
    } else
        return 0x00;
}
void ART::Deserialize(char* data, int size) {
    int index = 0;
    memcpy(&mDimensions, data, sizeof(int));
    index += sizeof(int);
    memcpy(&mChoice, data+index, sizeof(double));
    index += sizeof(double);
    memcpy(&mLearnRate, data+index, sizeof(double));
    index += sizeof(double);
    memcpy(&mVigilance, data+index, sizeof(double));
    index += sizeof(double);
    
    int categorySize, categoryCount;
    memcpy(&categorySize, data+index, sizeof(int));     // size of each category
    index += sizeof(int);
    memcpy(&categoryCount, data+index, sizeof(int));     // how many categories
    index += sizeof(int);
    
    mCategories.clear();
    for (int i = 0; i < categoryCount; i++)
        mCategories.push_back(new ArtCategory(mDimensions));
    
    for (int i = 0; i < categoryCount; i++) {      // all the other categories
        if (index+categorySize < size)
            mCategories.at(i)->Deserialize(data+index, categorySize);
        else
            break;  // error!
        index += categorySize;
    }
    // done! ... without any error checking.
}