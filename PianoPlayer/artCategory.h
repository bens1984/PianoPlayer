#pragma once
//
//  artCategory.h
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <Math.h>
#include <string.h>

class artCategory
{
private:
    bool committed;	// switch to true after the category is committed
    double* weighting;
    int dimensions;
    double sum;
    
public:
    artCategory(int dim) : sum(0), committed(false), dimensions(dim*2)	// * 2 to use complement vector
    {
        weighting = new double[dimensions];
        for (int i = 0; i < dimensions; i++)
            weighting[i] = 1;	// can set higher than one to force deeper category search
        sum = dim * 2;
    }
    
    // calculate the mChoice match factor for this category and the given input
    double Choose(double input[], int size, double mChoice)
    {
        double minTotal = 0;
        for (int i = 0; i < size; i++)
            minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
        return minTotal / (mChoice + sum);
    }
    
    bool mVigilance(double input[], int size, double mVigilance)
    {
        double minTotal = 0;
        double inputTotal = 0;
        for (int i = 0; i < size; i++)
        {
            minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
            inputTotal += input[i];
        }
        
        return (minTotal / inputTotal >= mVigilance);
    }
    double GetVigilance(double input[], int size)
    {
        double minTotal = 0;
        double inputTotal = 0;
        for (int i = 0; i < size; i++)
        {
            minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
            inputTotal += input[i];
        }
        return minTotal / inputTotal;
    }
    
    void Learn(double input[], int size, double mLearnRate)
    {
        if (!committed)
        {
            mLearnRate = 1;
            committed = true;
        }
        double inverseLearnRate = 1.0f - mLearnRate;
        for (int i = 0; i < size; i++)
            weighting[i] = mLearnRate * (input[i] < weighting[i] ? input[i] : weighting[i]) + inverseLearnRate * weighting[i];
        sum = 0;	// now update the total for this category
        for (int i = 0; i < dimensions; i++)
            sum += weighting[i];
    }
    
    double* GetWeights()
    {
        return weighting;
    }
    
    double distance(double input[])
    {
        // take the not complemented part
        int featureLength = dimensions / 2;	// how many elements in the pre-complement coded vector?
        double center[featureLength];
        
        for (int i = 0; i < featureLength; i++)	// find the 'center' of the category
        {
            center[i] = (weighting[i] + (1.0 - weighting[i+featureLength])) * 0.5;
        }
        double dist = 0;
        for (int i = 0; i < featureLength; i++)	// calculate the distance to the input
            dist += pow(input[i]-center[i],2);
        if (dist > 0)
            dist = sqrt(dist);
        return dist;
    }
    
    void resizeCategory(int newSize)
    {
        double *oldWeights = weighting;
        weighting = new double[newSize];
        memcpy(weighting, oldWeights, dimensions);
        for (int i = dimensions; i < newSize; i+=2)
        {
            weighting[i] = 0.0;
            weighting[i+1] = 1.0;       // this is specific to the RL, makes each new dimension learned at '0', rather than leaving it open (setting both of these values to 1)
        }
             dimensions = newSize;
        delete oldWeights;
    }
};
