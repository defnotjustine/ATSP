//
// Created by Justine on 21.10.2024.
//

#include "../include/MatrixGenerator.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//konstruktor
MatrixGenerator::MatrixGenerator(int size) : size(size) {
    srand(time(nullptr)); //inicjalizacja generatora losowego
}

//generacja symetrycznej macierzy
vector<vector<int>> MatrixGenerator::generateSymmetricMatrix() {
    vector<vector<int>> matrix(size, vector<int>(size, 0));

    //generowanie wartosci tylko dla polowy, bo macierz symetryczna
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            if(i == j){
                matrix[i][j] = -1; //brak drogi do samego siebie
            } else{
                int distance = generateRandomDistance();
                matrix[i][j] = distance;
                matrix[j][i] = distance; //odbicie symetryczne
            }
        }
    }
    return matrix;
}

//generacja asymetrycznej macierzy
vector<vector<int>> MatrixGenerator::generateAsymmetricMatrix() {
    vector<vector<int>> matrix(size, vector<int>(size, 0));

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(i == j){
                matrix[i][j] = -1; //brak drogi do samego siebie
            } else{
                matrix[i][j] = generateRandomDistance();
            }
        }
    }
    return matrix;
}

//generacja losowej wartosci odleglosci(przyjelam zakres 1 - 100)
int MatrixGenerator::generateRandomDistance() {
    return rand() % 100 + 1;
}
