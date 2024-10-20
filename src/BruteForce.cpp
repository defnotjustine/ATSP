//
// Created by Justine on 20.10.2024.
//

#include "../include/BruteForce.h"
#include <limits>

BruteForce::BruteForce(const vector<vector<int>> &distanceMatrix)
: distenceMatrix(distanceMatrix), minCost(numeric_limits<int>::max()){}

//szuka najkrotsza droge
int BruteForce::findShortestPath() {
    int n = distenceMatrix.size();
    vector<int> path(n);

    //inicjalizacja sciezki kolejno miastami od 0 do n-1
    for(int i = 0; i < n; ++i){
        path[i] = i;
    }

    //generowanie wszystkich mozliwych permutacji
    permute(path, 1, n -1);

    return minCost;
}

// Funkcja zamieniająca elementy w tablicy
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//funkcja rekurencyjna generujaca permutacje miast
void BruteForce::permute(vector<int> &path, int left, int right) {
    if(left == right){
        int cost = calculateCost(path);
        if(cost < minCost){
            minCost = cost;
            shortestPath = path;
        }
    } else{
        for(int i = left; i <= right; ++i){
            swap(path[left],path[i]);
            permute(path, left + 1, right);
            swap(path[left], path[i]); //przywracamy oryginalny stan
        }
    }
}

//funkcja obliczajaca koszt danej sciezki
int BruteForce::calculateCost(const vector<int> &path) {
    int cost = 0;
    for(int i = 0; i < path.size() - 1; ++i){
        cost += distenceMatrix[path[i]][path[i + 1]];
    }
    //powrot do miasta poczatkowego
    cost += distenceMatrix[path.back()][path.front()];
    return cost;
}
