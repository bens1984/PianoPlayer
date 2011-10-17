//
//  ART.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ART.h"

ART::ART(double _choice, double _learnRate, double _Vigilance) : mDimensions(19), residual(0), choices(0x00)
{
    mCategories.clear();
    mCategories.push_back(new ArtCategory(mDimensions));
    //        mCount.push_back(0);
    
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
    for (int i = 0; i < mCategories.size(); i++)
        delete mCategories.at(i);
    mCategories.clear();
    if (input != 0x00)
        delete input;
    if (choiceSize > 0)
        delete choices;
    choiceSize = 0;
}
void ART::ProcessNewObservation(double *&in, int length)
{
    setInput(in, length);
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
void ART::setInput(double *&_in, int size)
{
    if (size > 0 && size > mDimensions)
    {
        mDimensions = size;
        if (input != 0x00)
            delete input;
        input = (double*)malloc(sizeof(double)*size*2); //new double(size*2);
        for (int i = 0; i < mCategories.size(); i++)
            mCategories.at(i)->resizeCategory(mDimensions);
    }
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
    if (choiceSize < mCategories.size())
    {
        delete choices;
        choices = new double[mCategories.size()];
        choiceSize = mCategories.size();
    }
    // check against all existing categories, and 1 empty one
    if (mDimensions > 0)
    {
        for (int i = 0; i < mCategories.size(); i++)
            choices[i] = mCategories.at(i)->Choose(input, mDimensions*2, mChoice); //, mResonanceWeights);  // pass in a descriptor for the feature vector
    }
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
                OSCSend::getSingleton()->oscSend("/in", mDimensions*2, input);
                residual = mCategories.at(maxIndex)->Learn(input,mDimensions*2,mLearnRate); //learn
                while (maxIndex >= mCategories.size()-1)	// committed the previous uncommitted category, so add a new blank one.
                    mCategories.push_back(new ArtCategory(mDimensions));
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
    //        if (maxIndex > -1)
    //        {
    //            inputCount++;
    //            mCount.at(maxIndex) += 1;
    //        }
    return maxIndex;
}
int ART::PredictChoice()
{
    return PredictChoice(mVigilance);
}
int ART::PredictChoice(double workingVigilance)
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
            if (mCategories.at(maxIndex)->mVigilance(input,mDimensions*2,workingVigilance) || mCategories.size() == 1)		// this is the match!
            {
                if (maxIndex == mCategories.size()-1)   // it would be a new category
                    residual = mDimensions;   // new categories are too chaotic for us to privilege
                else
                    residual = mCategories.at(maxIndex)->GetResidual(input,mDimensions*2,1.0); //mLearnRate); // <- figure out how much residual would occur
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
    //        if (maxIndex > -1)
    //        {
    //            inputCount++;
    //            mCount.at(maxIndex) += 1;
    //        }
    return maxIndex;
}
double ART::calcDistance(int cat)	// use set input and calculate distance to center of specified category
{
    if (cat < mCategories.size())
        return mCategories.at(cat)->distance(input);
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