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
#define CLUSTER_RATIO 0.2   // how far apart notes must be to be in the same cluster, in terms of %

#define remainder(x, y) (x/y) - (int)(x/y)

TempoTracker::TempoTracker(double _windowSize) : windowSize(_windowSize) {
    
}

TempoTracker::~TempoTracker() {
    durations.clear();
    stackedDurations.clear();
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
    vector<int> clusterWeights;
    clusterWeights.insert(clusterWeights.begin(), clusterCounts.begin(), clusterCounts.end());  // copy counts into weights
    for (int i = 0; i < clusters.size(); i++) {
        for (int j = i+1; j < clusters.size(); j++) {
            if (clusters.at(i) > clusters.at(j)) {
                if (remainder(clusters.at(i), clusters.at(j)) < CLUSTER_RATIO) {
                    clusterWeights.at(i) += clusterCounts.at(j);
                    clusterWeights.at(j) += clusterCounts.at(i);
                }
            } else if (remainder(clusters.at(j), clusters.at(i)) < CLUSTER_RATIO) {
                clusterWeights.at(i) += clusterCounts.at(j);
                clusterWeights.at(j) += clusterCounts.at(i);
            }
        }
    }
    int maxWeight, maxIndex = -1;
    maxWeight = 0;
    for (int i = 0; i < clusterWeights.size(); i++) {
        if (clusters.at(i) >= 300 && clusters.at(i) < 1600 && clusterWeights.at(i) > maxWeight) {    // make sure it's in foot tapping range
            maxWeight = clusterWeights.at(i);
            maxIndex = i;
        }
        cout << clusters.at(i) << " :: " << clusterCounts.at(i) << " || " << clusterWeights.at(i) << endl;
    }
    
    if (maxIndex > 0)
        return clusters.at(maxIndex);
    else
        return -1;
}