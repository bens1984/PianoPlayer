//
//  ART.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "artCategory.h"
#include <vector>

using namespace std;

class ART
{
private:
    int mDimensions; // how many dimensions to match data on
    vector<artCategory*> mCategories;
    int categoryCount;
    double mChoice, mLearnRate, mVigilance;
    double *input, *choices;
    int recentChoice;	// the most recently chosen category
    
public:
    ART(int dimensions, double _choice, double _learnRate, double _Vigilance) : categoryCount(0), mDimensions(dimensions)
    {
        mCategories.push_back(new artCategory(mDimensions));
        categoryCount = 1;
        
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
    
    void setInput(double *_in, int size)
    {
        memcpy(input, _in, size);
//        System.arraycopy(in, 0, input, 0, input.length);
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
    
    void complementCode()
    {
        for (int i = 0; i < mDimensions; i++)	// create complement of input - complement coding
            input[i+mDimensions] = 1.0f - input[i];
    }
    
    double* getCategoryChoice()
    {
        // check against all existing categories, and 1 empty one
        if (mDimensions > 0)
        {
            choices = new double[categoryCount];
            for (int i = 0; i < categoryCount; i++)
                choices[i] = mCategories.at(i)->Choose(input, mDimensions*2, mChoice);
        } else
            choices = new double[0];
        return choices;
    }
    int makeChoice()
    {
        return makeChoice(mVigilance);
    }
    int makeChoice(double workingVigilance)
    {
        int maxIndex = -1;
        int iter = 0;
        bool chosen = false;		// check mVigilance stuff here...
        while (!chosen)
        {
            // find largest match value
            double max = 0;
            for (int i = 0; i < categoryCount; i++)
                if (choices[i] > max)
                {
                    max = choices[i];
                    maxIndex = i;
                }
            if (maxIndex != -1)
            {
                //					outputChoices(iter++, choices);	// should really only do this if debug is on, or something
                //					post("checking index: " + maxIndex);
                // if above vigilence then learn from it
                if (mCategories.at(maxIndex)->mVigilance(input,mDimensions*2,workingVigilance) || categoryCount == 1)		// learn!
                {
                    mCategories.at(maxIndex)->Learn(input,mDimensions*2,mLearnRate); //learn
                    if (maxIndex == categoryCount-1)	// committed the previous uncommitted category, so add a new blank one.
                    {	
//                        if (categoryCount+1 == mCategories.size())
//                            mCategories = (category[])resizeArray(mCategories, mCategories.length + 16);
                        mCategories.push_back(new artCategory(mDimensions));
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
        return maxIndex;
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
//    void outputCategoryWeight(int i)
//    {
//        if (i>= 0 && i < mCategories.size())
//            outlet(2, mCategories.at(i)->GetWeights());
//    }
//    /**
//     * Reallocates an array with a new size, and copies the contents
//     * of the old array to the new array.
//     * @param oldArray  the old array, to be reallocated.
//     * @param newSize   the new array size.
//     * @return          A new array with the same contents.
//     */
//    private Object resizeArray (Object oldArray, int newSize) 
//    {
//        int oldSize = java.lang.reflect.Array.getLength(oldArray);
//        Class elementType = oldArray.getClass().getComponentType();
//        Object newArray = java.lang.reflect.Array.newInstance(elementType,newSize);
//        int preserveLength = Math.min(oldSize,newSize);
//        if (preserveLength > 0)
//            System.arraycopy (oldArray,0,newArray,0,preserveLength);
//        return newArray; 
//    }
//    
    double calcDistance(int cat)	// use set input and calculate distance to center of specified category
    {
        if (cat < mCategories.size())
            return mCategories.at(cat)->distance(input);
        else
            return -1;
    }
    double* getWeights()	// return all of the weights of all of our categories
    {
        double *weights = new double[categoryCount*mDimensions*2];
        for (int i = 0; i < categoryCount; i++)
            memcpy(weights+(i*mDimensions*2), mCategories.at(i)->GetWeights(), mDimensions*2);
        return weights;
    }
};
