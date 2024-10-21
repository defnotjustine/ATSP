//
// Created by Justine on 20.10.2024.
//
#include "../include/RandomSearch.h"

RandomSearch::RandomSearch(const std::vector<std::vector<int>>& distanceMatrix)
        : distanceMatrix(distanceMatrix), minCost(std::numeric_limits<int>::max()) {
    // Inicjalizacja generatora losowego
    srand(time(nullptr));
}

// Funkcja generująca i porównująca losowe ścieżki
int paths = 5; //generujemy 5 sciezek i szukamy najkrotsza z nich
int RandomSearch::findShortestPath() {
    for (int i = 0; i < paths; ++i) {
        std::vector<int> path = generateRandomPath(); // Generujemy losową ścieżkę
        int cost = calculateCost(path); // Obliczamy koszt ścieżki
        if (cost < minCost) {
            minCost = cost;
            bestPath = path; // Aktualizujemy najlepszą ścieżkę
        }
    }
    return minCost;
}

// Funkcja generująca losową ścieżkę
std::vector<int> RandomSearch::generateRandomPath() {
    int n = distanceMatrix.size();
    std::vector<int> path;
    std::vector<int> visited(n, 0); // Wektor, który oznacza odwiedzone miasta

    // Wybieramy losowo miasto startowe
    int startCity = rand() % n;
    path.push_back(startCity);
    visited[startCity] = 1; // Oznaczamy miasto jako odwiedzone

    // Losowo wybieramy kolejne miasta, które nie zostały jeszcze odwiedzone
    while (path.size() < n) {
        int nextCity = rand() % n;
        if (!isVisited(nextCity, visited) && nextCity != path.back()) {
            path.push_back(nextCity);
            visited[nextCity] = 1;
        }
    }

    return path;
}

// Funkcja sprawdzająca, czy dane miasto zostało odwiedzone
bool RandomSearch::isVisited(int city, const std::vector<int>& visited) {
    return visited[city] == 1;
}

// Funkcja obliczająca koszt ścieżki
int RandomSearch::calculateCost(const std::vector<int>& path) {
    int cost = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        cost += distanceMatrix[path[i]][path[i + 1]];
    }
    // Powrót do miasta początkowego
    cost += distanceMatrix[path.back()][path.front()];
    return cost;
}

