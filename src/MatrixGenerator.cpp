//
// Created by Justine on 21.10.2024.
//

#include "../include/MatrixGenerator.h"

using namespace std;
//konstruktor
MatrixGenerator::MatrixGenerator(int size, int minValueToGenerate, int maxValueToGenerate) : size(size), minValueToGenerate(minValueToGenerate), maxValueToGenerate(maxValueToGenerate)  {}

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

int MatrixGenerator::generateRandomDistance() {
    // Używamy mt19937 do generowania liczb losowych
    std::random_device rd;  // Urządzenie losujące
    std::mt19937 gen(rd()); // Generator Mersenne Twister z ziarna urządzenia losującego
    std::uniform_int_distribution<> dist(minValueToGenerate, maxValueToGenerate);  // Dystrybucja wartości od 1 do 100
    return dist(gen);
}