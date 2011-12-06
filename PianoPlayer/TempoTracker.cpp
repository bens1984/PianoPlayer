//
//  TempoTracker.cpp
//  PianoPlayer
//
//  Created by Ben Smith on 12/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TempoTracker.h"
#include <math.h>
#include <iostream>

#define CLUSTER_SIZE 50     // how many milliseconds apart notes must be to be deemed equivalent
#define CLUSTER_RATIO 0.15   // how far apart notes must be to be in the same cluster, in terms of %

#define remainder(x, y) ((x/y) - floor((x/y) + 0.5))   

TempoTracker::TempoTracker(double _windowSize) : windowSize(_windowSize) {
    
}

TempoTracker::~TempoTracker() {
    durations.clear();
    stackedDurations.clear();
}

double TempoTracker::CalculatePhase(double frequency) {
    int i;
    if (stackedDurations.size() == 0)
        return -1;
    // take 0 as 0 degrees and calculate the position of each beat (duration) in terms of radians
    vector<double> inRadians;
    inRadians.push_back(0); // there is a pulse at 0 and it will be at 0 degrees
    for (vector<double>::iterator it = stackedDurations.begin(); it != stackedDurations.end(); it++) {
        inRadians.push_back(remainder(*it, frequency) * M_PI);
    }
    // calculate the weight (gravity) of each point
    double gravity[inRadians.size()];
    for (int i = 0; i < inRadians.size(); i++)
        gravity[i] = 1;
    i = 0;
    for (vector<double>::iterator it = inRadians.begin(); it != inRadians.end(); it++, i++) {
        for (int j = i+1; j < inRadians.size(); j++) {
            double distance = fabs(*it - inRadians.at(j));
            if (distance > M_PI_2)
                distance = M_PI - distance;     // if it's more than half way around the circle then we want the short side distance
            distance = distance * distance;
            if (distance < 0.1)
                distance = 0.1;
            if (distance != 0)
                distance = 1.0 / distance;
            gravity[i] += distance;
            gravity[j] += distance;
        }
    }
    // find heaviest point
    double heaviest = -1;
    int heaviestIndex = -1;
    for (int i = 0; i < inRadians.size(); i++) {
        if (gravity[i] > heaviest) {
            heaviest = gravity[i];
            heaviestIndex = i;
        }
    }
//    // calculate an average vector
//    double x = 0;
//    double y = 0;
//    for (vector<double>::iterator it = inRadians.begin(); it != inRadians.end(); it++) {
//        x += sin(*it);
//        y += cos(*it);
//    }
//    x /= inRadians.size();
//    y /= inRadians.size();
    // calculate phase from this average vector
    if (heaviestIndex != -1) {
//        cout << "fit " << frequency << ":: ";
        double phase = inRadians.at(heaviestIndex); //acos(y / sqrt(x*x + y*y));
        // calculate least squares value, i.e. how well this frequency fits these durations
        phase *= frequency * M_1_PI;
        double leastSquares = 0;
        for (vector<double>::iterator it = stackedDurations.begin(); it != stackedDurations.end(); it++) {
            double ls = pow(fabs (remainder((*it - phase), frequency)) + 1, 2.0);
//            cout << *it << "=" << ls << ", ";
            if (ls > 0)
                leastSquares += 1.0 / ls;    // offset for phase, then 
        }
//    cout << endl;
        return leastSquares;
    } else
        return -1;
}

void TempoTracker::AddPulse(double duration) {
    if (duration > 0) {
        durations.push_back(duration);
        for (vector<double>::iterator it = stackedDurations.begin(); it != stackedDurations.end(); it++)
            *it += duration;
        stackedDurations.push_back(duration);
        while (stackedDurations.size() && stackedDurations.at(0) > windowSize) {  //remove anything that is older than 'windowSize' milliseconds
            stackedDurations.erase(stackedDurations.begin());
            durations.erase(durations.begin());
        }
    }
}
double TempoTracker::CalculateTempo() {
    vector<double> distances;   // get all of the IOI distances
    
    for (vector<double>::iterator it = stackedDurations.begin(); it != stackedDurations.end(); it++) {
        distances.push_back(*it);
        for (vector<double>::iterator it2 = it+1; it2 != stackedDurations.end(); it2++) {
            distances.push_back(*it - *it2);
        }
    }
    
    // now cluster the distances
    vector<double> clusters, clusterSums;
    vector<int> clusterCounts;
    bool matched;
    for (vector<double>::iterator it = distances.begin(); it != distances.end(); it++) {
        matched = false;
        for (int i = 0; i < clusters.size(); i++) {
            double dif = fabs(clusters.at(i) - *it);
            if (dif < CLUSTER_SIZE || dif < clusters.at(i) * CLUSTER_RATIO) {
                matched = true;
                clusterSums.at(i) += *it;
                clusterCounts.at(i)++;
                clusters.at(i) = clusterSums.at(i) / clusterCounts.at(i);
                break;
            }
        }
        if (!matched) {
            clusters.push_back(*it);
            clusterSums.push_back(*it);
            clusterCounts.push_back(1);
        }
    }
    
    
    // look for integer ratios between the clusters (1:2:3:etc)
    vector<double> clusterWeights;
    for (vector<double>::iterator it = clusters.begin(); it != clusters.end(); it++) {
        double newWeight = CalculatePhase(*it);
//        newWeight = (newWeight > 0 ? 1 / newWeight : 0);
        clusterWeights.push_back(newWeight);
    }
//    clusterWeights.insert(clusterWeights.begin(), clusterCounts.begin(), clusterCounts.end());  // copy counts into weights
    clusterSums.clear();
    clusterSums.insert(clusterSums.begin(), clusterWeights.begin(), clusterWeights.end());  // copy counts into weights
    for (int i = 0; i < clusters.size(); i++) {
        for (int j = i+1; j < clusters.size(); j++) {
            if (clusters.at(i) > clusters.at(j)) {
//                cout << clusters.at(i) << "/" << clusters.at(j) << " = " << remainder(clusters.at(i), clusters.at(j)) << endl;
                if (fabs(remainder(clusters.at(i), clusters.at(j))) < CLUSTER_RATIO) {
                    clusterSums.at(i) += clusterWeights.at(j);
                    clusterSums.at(j) += clusterWeights.at(i);
                }
            } else {
//                cout << clusters.at(j) << "/" << clusters.at(i) << " = " << remainder(clusters.at(j), clusters.at(i)) << endl;
                if (fabs(remainder(clusters.at(j), clusters.at(i))) < CLUSTER_RATIO) {
                clusterSums.at(i) += clusterWeights.at(j);
                clusterSums.at(j) += clusterWeights.at(i);
                }
            }
        }
    }
    double maxWeight = -1;
    int maxIndex = -1;
    for (int i = 0; i < clusterWeights.size(); i++) {
        if (clusters.at(i) >= 300 && clusters.at(i) < 1000 && clusterWeights.at(i) > maxWeight) {    // make sure it's in foot tapping range
            maxWeight = clusterWeights.at(i);
            maxIndex = i;
        }
//        cout << clusters.at(i) << " :: " << clusterSums.at(i) << " || " << clusterWeights.at(i) << endl;
    }
    if (maxIndex == -1) // nothing was found, now try again, for something "out of range"
        for (int i = 0; i < clusterWeights.size(); i++) {
            if (clusterWeights.at(i) > maxWeight) {    // make sure it's in foot tapping range
                maxWeight = clusterWeights.at(i);
                maxIndex = i;
            }
        }
    if (maxIndex > 0)
        return clusters.at(maxIndex);
    else
        return -1;
}