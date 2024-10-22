//
// Created by Justine on 21.10.2024.
//

#ifndef TEST_MATRIXGENERATOR_H
#define TEST_MATRIXGENERATOR_H

#include <vector>
#include "../include/ConfigReader.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

class MatrixGenerator {
public:
    //konstruktor przyjmujacy rozmiar macierzy
    MatrixGenerator(int size, int minValueToGenerate, int maxValueToGenerate);

    //funkcja generujaca symetryczna macierz odleglosci
    vector<vector<int>> generateSymmetricMatrix();

    //funkcja generujacaasymetryczna macierz odleglosci
    vector<vector<int>> generateAsymmetricMatrix();


private:
    int size; //rozmiar macierzy(liczba miast)
    int minValueToGenerate;
    int maxValueToGenerate;
    int generateRandomDistance();
    //funkcja generujaca losowa odleglosc
};


#endif //TEST_MATRIXGENERATOR_H
