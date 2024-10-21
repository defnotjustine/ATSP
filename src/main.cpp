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

int main() {

    //wczytanie konfiguracji
    ConfigReader config("../config/config.txt");
    config.loadConfig();

    // Otwarcie pliku CSV do zapisu
    ofstream csvFile;
    csvFile.open(config.getOutputFile(), ios::app);  // otwórz plik w trybie dopisania

    // Sprawdź, czy plik się otworzył
    if (!csvFile.is_open()) {
        cerr << "Nie można otworzyć pliku CSV do zapisu!" << endl;
        return 1;
    }

    //przechowujemy macierz odleglosci
    vector<vector<int>> distanceMatrix;

    int citiesCount = config.getInstanceSize(); //ilosc miast/instancji
    MatrixGenerator generator(citiesCount);

    //czy generujemy losowa macierz?
    if(config.isGenerateRandom()){
        if(config.isSymmetrical()){
            distanceMatrix = generator.generateSymmetricMatrix();
        } else distanceMatrix = generator.generateAsymmetricMatrix();
    }else{
        //wczytanie macierzy z pliku
        string basePath = "../data/";
        //string fileName = "matrix_6x6.atsp";
        string fileName = config.getInputFile();
        string filePath = basePath+fileName;
        FileReader fileReader(filePath);
        distanceMatrix = fileReader.getDistanceMatrix(); //????????
    }

// Wyświetlamy macierz
    std::cout << "Macierz odleglosci:" << std::endl;
    for (const auto &row: distanceMatrix) {
        for (int value: row) {
            std::cout << value << "\t";
        }
        std::cout << std::endl;
    }

    //obiekt klas
    NearestNeighbours nearestNeighbours(distanceMatrix);
    BruteForce bruteForce(distanceMatrix);
    RandomSearch randomSearch(distanceMatrix);
    int iterations = config.getRepeatCount(); //liczba powtorzen
    chrono::duration<double> avgDuration;
    chrono::duration<double> totalDuration;
    for(int i = 0; i < iterations; ++i) {
        cout << "Iteracja nr" << i + 1 << endl;
        int shortestPath;
        chrono::duration<double> durationBrute;
        if (config.algorithmType() == 1) {
            auto start = chrono::high_resolution_clock::now();
            shortestPath = bruteForce.findShortestPath();
            auto end = chrono::high_resolution_clock::now();
            durationBrute = end - start;
            totalDuration += durationBrute;
        } else if (config.algorithmType() == 2) {
            auto start = chrono::high_resolution_clock::now();
            shortestPath = nearestNeighbours.findShortestPath();
            auto end = chrono::high_resolution_clock::now();
            durationBrute = end - start;
            totalDuration += durationBrute;
        } else if (config.algorithmType() == 3) {
            auto start = chrono::high_resolution_clock::now();
            shortestPath = randomSearch.findShortestPath();
            auto end = chrono::high_resolution_clock::now();
            durationBrute = end - start;
            totalDuration += durationBrute;
        }

        // Zapisz wyniki do pliku CSV
        csvFile << fixed << setprecision(6) << durationBrute.count() << endl;
        cout << "Dlugosc najkrotszej trasy: " << shortestPath << endl;
        //cout << "Czas wykonania algorytmu: " << fixed << setprecision(6) << durationBrute.count() << " ms" << endl;
    }

    avgDuration = totalDuration / iterations;
    cout << "Sredni czas wykonania algorytmu: " << fixed << setprecision(6) << avgDuration.count() << " ms" << endl;

    // Zamknięcie pliku CSV
    csvFile.close();

    return 0;
}
