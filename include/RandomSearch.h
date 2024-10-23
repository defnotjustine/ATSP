//
// Created by Justine on 20.10.2024.
//

#ifndef RANDOMSEARCH_H
#define RANDOMSEARCH_H

#include <vector>
#include <cstdlib> // Dla funkcji rand() i srand()
#include <limits> // Dla std::numeric_limits
#include <ctime>  // Dla inicjalizacji generatora losowego time()
#include "ConfigReader.h"

class RandomSearch {
public:
    RandomSearch(const std::vector<std::vector<int>>& distanceMatrix);

    // Funkcja wykonująca algorytm losowy i zwracająca najlepszy znaleziony koszt
    int findShortestPath(int paths);

private:
    std::vector<std::vector<int>> distanceMatrix; // Przechowywanie macierzy odległości
    int pathsToGenerate; // Liczba generowanych ścieżek
    std::vector<int> bestPath; // Przechowywanie najlepszej ścieżki
    int minCost; // Minimalny koszt najlepszej ścieżki

    // Funkcja obliczająca koszt ścieżki
    int calculateCost(const std::vector<int>& path);

    // Funkcja generująca losową ścieżkę z kontrolą odwiedzonych miast
    std::vector<int> generateRandomPath();

    // Funkcja sprawdzająca, czy miasto zostało już odwiedzone
    bool isVisited(int city, const std::vector<int>& visited);
};

#endif // RANDOMSEARCH_H

