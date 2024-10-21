//
// Created by Justine on 17.10.2024.
//

#ifndef TEST_NEARESTNEIGHBOURS_H
#define TEST_NEARESTNEIGHBOURS_H

#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class NearestNeighbours {
public:
    NearestNeighbours(const vector<vector<int>> &distanceMatrix);
    int findShortestPath();

private:
    vector<vector<int>> distanceMatrix;
    int findNearestNeighbor(int currentCity, const vector<bool>& visited);
};


#endif //TEST_NEARESTNEIGHBOURS_H
