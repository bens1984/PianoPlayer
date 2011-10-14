#pragma once
//
//  ART.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "artCategory.h"
#include <vector.h>
#include "OSCSend.h"

using namespace std;

class ART
{
private:
    int mDimensions; // how many dimensions to match data on
    vector<ArtCategory*> mCategories;
//    vector<int> mCount;     // how many times each category has been seen. trying to measure how "confident" we are in the observation
//    int inputCount;  // how many inputs we have seen
    double mChoice, mLearnRate, mVigilance;
    double *input, *choices;
    int recentChoice;	// the most recently chosen category
    double residual;    // how much the chosen category changed with the last input/learning step
    
    void normalizeInput()
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
    inline void complementCode()
    {
        for (int i = 0; i < mDimensions*2; i+=2)	// create complement of input - complement coding
            input[i+1] = 1.0 - input[i];
    }
    void setInput(const double *_in, int size)
    {
        if (size > mDimensions)
        {
            mDimensions = size;
            if (input != 0x00)
                delete input;
            input = new double(size*2);
            for (int i = 0; i < mCategories.size(); i++)
                mCategories.at(i)->resizeCategory(mDimensions);
        }
        for (int i = 0; i < size; i++)
        {
            input[i*2] = _in[i];
            input[i*2+1] = 1; //1.0 - _in[i];
        }
    }
    
    //	set the mVigilance just high enough to reset the chosen category and look again.
    int increaseVigilance()
    {
        if (recentChoice > -1)
        {
            double vig = mCategories.at(recentChoice)->GetVigilance(input,mDimensions*2) + 0.01f;	// increase by a little bit.
            recentChoice = makeChoice(vig);
        }
        return recentChoice;
    }
    void FillCategoryChoice()
    {
        if (choices != 0x00)
            delete choices;
        // check against all existing categories, and 1 empty one
        if (mDimensions > 0)
        {
            choices = new double[mCategories.size()];
            for (int i = 0; i < mCategories.size(); i++)
                choices[i] = mCategories.at(i)->Choose(input, mDimensions*2, mChoice);
        } else
            choices = 0x00; //new double[0];
    }
public:
    ART(double _choice, double _learnRate, double _Vigilance) : mDimensions(19), residual(0)
    {
        mCategories.push_back(new ArtCategory(mDimensions));
//        mCount.push_back(0);
        
        input = new double[mDimensions*2];
        
        mChoice = _choice;
        mLearnRate = _learnRate;
        mVigilance = _Vigilance;
        recentChoice = -1;
    }
    ~ART()
    {
        for (int i = 0; i < mCategories.size(); i++)
            delete mCategories.at(i);
    }
    void ProcessNewObservation(const double *input, int length)
    {
        setInput(input, length);
        normalizeInput();
        complementCode();
        FillCategoryChoice();
    }
    void setVigilance(double v)
    {
        mVigilance = v;
    }
    void setLearnRate(double v)
    {
        mLearnRate = v;
    }
    void setChoice(double v)
    {
        mChoice = v;
    }
    double GetResidual()
    {
        return residual;
    }
    
    const double* GetCategoryChoice()
    {
        double* ret = new double[mCategories.size()];
        memcpy(ret, choices, mCategories.size()*8);
        return ret;
    }
//    const double* GetImportance()
//    {
//        if (inputCount > 0)
//        {
//            double *importance = new double[mCategories.size()];
//            for (int i = 0; i < mCategories.size(); i++)
//                importance[i] = choices[i] * (mCount[i] / (double)inputCount);
//            return importance;
//        } else
//            return 0x00;
//    }
    int makeChoice()
    {
        return makeChoice(mVigilance);
    }
    int makeChoice(double workingVigilance)
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
                    if (maxIndex == mCategories.size()-1)	// committed the previous uncommitted category, so add a new blank one.
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
    int PredictChoice()
    {
        return PredictChoice(mVigilance);
    }
    int PredictChoice(double workingVigilance)
    {
        int maxIndex = -1;
        bool chosen = false;		// check mVigilance stuff here...
        while (!chosen)
        {
            // find largest match value
            double max = 0;
            for (int i = 0; i < mCategories.size()-1; i++)  // -1 to ignore the possibility of creating a new category, for now.
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
    double calcDistance(int cat)	// use set input and calculate distance to center of specified category
    {
        if (cat < mCategories.size())
            return mCategories.at(cat)->distance(input);
        else
            return -1;
    }
    const double *getWeights()	// return all of the weights of all of our categories
    {
        double *weights = new double[mCategories.size()*mDimensions*2];
        for (int i = 0; i < mCategories.size(); i++)
            memcpy(weights+(i*mDimensions*2), mCategories.at(i)->GetWeights(), mDimensions*2*8);
        return weights;
    }
    const double* GetWeights(int index)
    {
        double *weights = new double[mDimensions*2];
        memcpy(weights, mCategories.at(index)->GetWeights(), mDimensions*2*8);
        return weights;
    }
};
