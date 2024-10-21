#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "../include/NearestNeighbours.h"
#include "../include/FileReader.h"
#include "../include/ConfigReader.h"
#include "../include/MatrixGenerator.h"
#include "../include/BruteForce.h"
#include "../include/RandomSearch.h"

using namespace std;

// Funkcja do otwierania pliku CSV
ofstream openCSVFile(const string& outputFile) {
    ofstream csvFile(outputFile, ios::app);  // otwórz plik w trybie dopisania
    if (!csvFile.is_open()) {
        cerr << "Nie można otworzyc pliku CSV do zapisu!" << endl;
        exit(1);  // Wyjdź z programu, jeśli nie uda się otworzyć pliku
    }
    return csvFile;
}

// Funkcja do wyświetlania macierzy odległości
void displayDistanceMatrix(const vector<vector<int>>& distanceMatrix) {
    cout << "Macierz odleglosci:" << endl;
    for (const auto& row : distanceMatrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }
}

// Funkcja do wykonania algorytmu i zwrócenia czasu jego wykonania
chrono::duration<double> executeAlgorithm(int algorithmType,
                                          BruteForce& bruteForce,
                                          NearestNeighbours& nearestNeighbours,
                                          RandomSearch& randomSearch,
                                          int& shortestPath) {
    auto start = chrono::high_resolution_clock::now();

    if (algorithmType == 1) {
        shortestPath = bruteForce.findShortestPath();
    } else if (algorithmType == 2) {
        shortestPath = nearestNeighbours.findShortestPath();
    } else if (algorithmType == 3) {
        shortestPath = randomSearch.findShortestPath();
    }

    auto end = chrono::high_resolution_clock::now();
    return end - start;  // Zwróć czas trwania algorytmu
}

// Funkcja do obsługi całego procesu
void runAlgorithm(ConfigReader& config,
                  const vector<vector<int>>& distanceMatrix,
                  ofstream& csvFile) {

    // Obiekty klas algorytmów
    NearestNeighbours nearestNeighbours(distanceMatrix);
    BruteForce bruteForce(distanceMatrix);
    RandomSearch randomSearch(distanceMatrix);

    int iterations = config.getRepeatCount();
    chrono::duration<double> totalDuration;

    for (int i = 0; i < iterations; ++i) {
        cout << "Iteracja nr " << i + 1 << endl;
        int shortestPath;
        chrono::duration<double> iterationDuration = executeAlgorithm(
                config.algorithmType(), bruteForce, nearestNeighbours, randomSearch, shortestPath
        );

        totalDuration += iterationDuration;  // Dodaj czas trwania tej iteracji do sumy

        // Zapisz czas trwania iteracji do pliku CSV
        csvFile << fixed << setprecision(6) << iterationDuration.count() << endl;

        cout << "Dlugosc najkrotszej trasy: " << shortestPath << endl;
    }

    // Wylicz i wyświetl średni czas
    chrono::duration<double> avgDuration = totalDuration / iterations;
    cout << "Sredni czas wykonania algorytmu: " << fixed << setprecision(6)
         << avgDuration.count() << " ms" << endl;
}

int main() {
    // Wczytanie konfiguracji
    ConfigReader config("../config/config.txt");
    config.loadConfig();

    // Otwarcie pliku CSV do zapisu
    ofstream csvFile = openCSVFile(config.getOutputFile());

    // Przygotowanie macierzy odległości
    vector<vector<int>> distanceMatrix;
    int citiesCount = config.getInstanceSize();
    MatrixGenerator generator(citiesCount);

    // Wygeneruj macierz lub wczytaj z pliku
    if (config.isGenerateRandom()) {
        if (config.isSymmetrical()) {
            distanceMatrix = generator.generateSymmetricMatrix();
        } else {
            distanceMatrix = generator.generateAsymmetricMatrix();
        }
    } else {
        string filePath = "../data/" + config.getInputFile();
        FileReader fileReader(filePath);
        distanceMatrix = fileReader.getDistanceMatrix();
    }

    // Wyświetlenie macierzy odległości
    displayDistanceMatrix(distanceMatrix);

    // Uruchomienie algorytmu
    runAlgorithm(config, distanceMatrix, csvFile);

    // Zamknięcie pliku CSV
    csvFile.close();

    return 0;
}
