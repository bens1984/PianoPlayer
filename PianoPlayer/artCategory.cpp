//
//  artCategory.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 10/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "artCategory.h"
#include <cmath>
#include <iostream>

ArtCategory::ArtCategory(int dim) : sum(0), committed(false), dimensions(dim*2), magnitude(0)	// * 2 to use complement vector
{
    if (dimensions > 0)
        weighting = new double[dimensions];
    else weighting = 0x00;
    for (int i = 0; i < dimensions; i++)
        weighting[i] = 1;	// can set higher than one to force deeper category search
    sum = dimensions;
}
ArtCategory::~ArtCategory()
{
    delete weighting;
}

double ArtCategory::GetMagnitude() {
    if (magnitude == 0) {
        for (int i = 0; i < dimensions; i++)
            magnitude += weighting[i] * weighting[i];
        magnitude = sqrt(magnitude);
    }
}
// calculate the mChoice match factor for this category and the given input
double ArtCategory::Choose(const double* input, int size, double mChoice)
{
    double minTotal = 0;
    for (int i = 0; i < size; i++)
        minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
    return minTotal / (mChoice + sum);
}
double ArtCategory::Choose(const double* input, int size, double mChoice, vector<ResonanceGroup>& resonanceWeights)
{
    double minTotal = 0;
    double mySum = 0;
    for (int i = 0; i < resonanceWeights.size(); i++)
    {
        double tempMin = 0;
        double tempSum = 0;
        for (int j = resonanceWeights.at(i).startIndex*2; j < resonanceWeights.at(i).startIndex*2+resonanceWeights.at(i).length*2; j++)
        {
            tempMin += (input[j] < weighting[j] ? input[j] : weighting[j]);
            tempSum += weighting[j];
        }
        if (resonanceWeights.at(i).length > 0)
        {
            minTotal += (tempMin / resonanceWeights.at(i).length) * resonanceWeights.at(i).weight;
            mySum += (tempSum / resonanceWeights.at(i).length) * resonanceWeights.at(i).weight;
        }
    }
    return minTotal / (mChoice + mySum);
}

bool ArtCategory::mVigilance(const double *input, int size, double mVigilance)
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
double ArtCategory::GetVigilance(const double *input, int size)
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

double ArtCategory::Learn(const double* input, int size, double mLearnRate)
{
    if (size > 0)
    {
        double *newWeighting = new double[size];
        double residual = 0;
        if (!committed)
        {
            mLearnRate = 1;
            committed = true;
        }
        double inverseLearnRate = 1.0 - mLearnRate;
        for (int i = 0; i < size; i++)
            newWeighting[i] = mLearnRate * (input[i] < weighting[i] ? input[i] : weighting[i]) + inverseLearnRate * weighting[i];
        // calculate residual
        for (int i = 0; i < size; i++)
        {
            residual += weighting[i] - newWeighting[i];
            weighting[i] = newWeighting[i];
        }
        sum = 0;	// now update the total for this category
        for (int i = 0; i < dimensions; i++)
            sum += weighting[i];
        delete newWeighting;
        
        magnitude = 0;  // reset, recalc it the next time it's needed
        
        return residual / (size * 0.5);
    } else return -1;
}
double ArtCategory::GetResidual(const double* input, int size, double mLearnRate)  // return the amount of change in the category if this input was learned with LearnRate=1
{
    double residual = 0;
    
//    if (!committed)
//    {
        mLearnRate = 1;
//    }
    double inverseLearnRate = 1.0 - mLearnRate;
    for (int i = 0; i < size; i++)
    {
        double min = (input[i] < weighting[i] ? input[i] : weighting[i]);
        residual += pow(weighting[i] - (mLearnRate * min + inverseLearnRate * weighting[i]), 2.0);
    }
    
    return residual / (size * 0.5);
}

const double* ArtCategory::GetWeights()
{
    return weighting;
}

const double ArtCategory::distance(const double *input)
{
    // This first version takes the not complemented part only (or at least it did...)
//    int featureLength = dimensions / 2;	// how many elements in the pre-complement coded vector?
//    double center[featureLength];
//    
//    for (int i = 0; i < featureLength; i++)	// find the 'center' of the category
//    {
//        center[i] = (weighting[i] + (1.0 - weighting[i+featureLength])) * 0.5;
//    }
//    double dist = 0;
//    for (int i = 0; i < featureLength; i++)	// calculate the distance to the input
//        dist += pow(input[i]-center[i],2);

    // second version just calculates the magnitude of the difference between the input and our weighting
    double dist = 0;
    for (int i = 0; i < dimensions; i++)	// calculate the distance to the input
        dist += pow(input[i]-weighting[i],2.0);

    if (dist > 0)
        dist = sqrt(dist);
    return dist / (dimensions * 0.25);
}
const double ArtCategory::curvature(const double* theseWeights)    // return the angle of change between theseWeights and our weighting
{
    double dot = 0.0;
    double sumThese = 0.0;
    double unitWeight, unitThese;
    for (int i = 0; i < dimensions; i++) {
        sumThese += theseWeights[i] * theseWeights[i];
    }
    sumThese = sqrt(sumThese);  // calc the magnitude of the incoming weights
    GetMagnitude();
    if (sumThese == 0 || magnitude == 0)
        return 0;
    else {
        for (int i = 0; i < dimensions; i++) {
            unitWeight = (weighting[i]) / magnitude;
            unitThese = (theseWeights[i]) / sumThese;
            dot += unitWeight * unitThese;
        }
        
        return acos(dot);
    }
}

void ArtCategory::resizeCategory(int newSize)
{    
    int newDim = newSize * 2;
    if (newDim > dimensions)
    {
//        std::cout << "resizing " << dimensions << " " << newSize << std::endl;
        double *newWeights = new double[newDim];
        if (weighting != 0x00)
        {
            memcpy(newWeights, weighting, dimensions*sizeof(double));
            delete weighting;
        }
        for (int i = dimensions; i < newDim; i++)
        {
            newWeights[i] = 1.0;
//            newWeights[i+1] = 1.0;       // setting both to 1 makes the dimension "unknown". Any input will "match"
            // this is specific to the RL, makes each new dimension learned at '0', rather than leaving it open (setting both of these values to 1)
        }
        dimensions = newDim;
        for (int i = 0; i < dimensions; i++)
            sum += newWeights[i];

        committed = false;
        weighting = newWeights;
    }
}

char* ArtCategory::Serialize(int &size) {
    size = 1 + sizeof(int) + sizeof(double) * (dimensions + 1); // committed + dimensions + sum + weights
    char* data = (char*)malloc(size);
    
    data[0] = committed;
    memcpy(data+1, &dimensions, sizeof(dimensions));
    memcpy(data+5, &sum, sizeof(sum));
    memcpy(data+9, weighting, dimensions * sizeof(double));
    
    return data;
}
void ArtCategory::Deserialize(char* data, int size) {
    committed = data[0];
    memcpy(&dimensions, data+1, sizeof(dimensions));
    memcpy(&sum, data+5, sizeof(sum));
    delete weighting;
    weighting = (double*)malloc(dimensions * sizeof(double));
    memcpy(weighting, data+9, dimensions * sizeof(double));
    magnitude = 0;
}