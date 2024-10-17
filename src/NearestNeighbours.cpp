//
// Created by Justine on 17.10.2024.
//

#include <limits>
#include "../include/NearestNeighbours.h"
using namespace std;
//konstruktor
//NearestNeighbours::NearestNeighbours(const vector<vector<int>> &distanceMatrix) : distanceMatrix(distanceMatrix) {}

NearestNeighbours::NearestNeighbours(const vector<vector<int>> &distanceMatrix) : distanceMatrix(distanceMatrix) {}

//szukamy najblizszego sasiada
int NearestNeighbours::findNearestNeighbor(int currentCity, const vector<bool>& visited){
    int nearestCity = -1; //wartosc domyslna(nie znaleziono jeszcze sasiada)
    int minDistance = numeric_limits<int>::max();

    for (int i = 0; i < distanceMatrix.size(); i++){
        //pomijamy odwiedzone miasta oraz to samo miasto
        if(!visited[i] && distanceMatrix[currentCity][i] < minDistance && distanceMatrix[currentCity][i] != -1) {
            minDistance = distanceMatrix[currentCity][i];
            nearestCity = i;
        }
    }

    return nearestCity;
}
//szukanie najkrotszej drogi
vector<int> NearestNeighbours::findShortestPath(int startCity, int &totalDistance){
    int n = distanceMatrix.size();
    vector<int> tour;  //droga
    vector<bool> visited(n, false); //odwiedzone wierzcholki
    totalDistance = 0; //dlugosc najkrotszej trasy

    int currentCity = startCity; //ustawiamy poczatkowy wierzcholek
    tour.push_back(currentCity);
    visited[currentCity] = true;

    for(int i = 1; i < n; i++){
        int nextCity = findNearestNeighbor(currentCity, visited);
        if(nextCity != -1){
            tour.push_back(nextCity);
            visited[nextCity] = true;
            totalDistance += distanceMatrix[currentCity][nextCity];
            currentCity = nextCity;
        }
    }

    // Powrót do miasta początkowego
    totalDistance += distanceMatrix[currentCity][startCity]; // Dodajemy odległość powrotu do startCity
    tour.push_back(startCity); //konczymy sciezke miastem poczatkowym

    return tour;
}
