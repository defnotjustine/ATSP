//
// Created by Justine on 21.10.2024.
//

#ifndef TEST_MATRIXGENERATOR_H
#define TEST_MATRIXGENERATOR_H

#include <vector>

using namespace std;

class MatrixGenerator {
public:
    //konstruktor przyjmujacy rozmiar macierzy
    MatrixGenerator(int size);

    //funkcja generujaca symetryczna macierz odleglosci
    vector<vector<int>> generateSymmetricMatrix();

    //funkcja generujacaasymetryczna macierz odleglosci
    vector<vector<int>> generateAsymmetricMatrix();

private:
    int size; //rozmiar macierzy(liczba miast)

    //funkcja generujaca losowa odleglosc
    int generateRandomDistance();
};


#endif //TEST_MATRIXGENERATOR_H
