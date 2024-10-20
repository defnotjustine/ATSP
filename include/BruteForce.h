//
// Created by Justine on 20.10.2024.
//

#ifndef TEST_BRUTEFORCE_H
#define TEST_BRUTEFORCE_H

#include <vector>

using namespace std;

class BruteForce {

public:
    //konstruktor przyjmujacy macierz odleglosci
    BruteForce(const vector<vector<int>> &distanceMatrix);

    int findShortestPath();

private:
    vector<vector<int>> distenceMatrix; //przechowujemy macierz odleglosci
    int minCost;
    vector<int> shortestPath; //przechowywanie najkrotszej sciezki
    //generowanie permutacji
    void permute(vector<int> &path, int left, int right);

    //oblicza koszt aktualnej sciezki
    int calculateCost(const vector<int> &path);
};


#endif //TEST_BRUTEFORCE_H
