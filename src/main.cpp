#include <iostream>
using namespace std;
#include <vector>
#include "../include/NearestNeighbours.h"

int main() {
    //odleglosci pomiedzy roznymi miastami
    vector<vector<int>> distanceMatrix = {
            {-1, 99, 19, 83, 23, 12},
            {67, -1, 3, 71, 85, 74},
            {54, 76, -1, 55, 62, 78},
            {32, 29, 68, -1, 76, 14},
            {20, 51, 84, 68, -1, 93},
            {96, 38, 82, 24, 9, -1}
    };
    //obiekt klasy NearestNeighbours
    NearestNeighbours nearestNeighbours(distanceMatrix);
    int startCity = 0;
    int totalDistance = 0; //dlugosc trasy
    //wynik - najkrotsza trasa
    vector<int> tour = nearestNeighbours.findShortestPath(startCity, totalDistance);

    cout << "Najktotsza trasa: ";
    //iterujemy po wszystkich miastach w najkrotszej trasie i wypisujemy
    for(int city : tour){
        cout << city << " ";
    }
    cout << endl;

    cout << "Dlugosc trasy: " << totalDistance << endl;

    return 0;

}
