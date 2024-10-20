//
// Created by Justine on 18.10.2024.
//

#include "../include/MatrixGenerator.h"
#include <cstdlib>
#include <ctime>

using namespace std;

vector<vector<int>> MatrixGenerator::generateRandomMatrix(int size, int minValue, int maxValue) {
    srand(time(nullptr));

    vector<vector<int>> matrix(size, vector<int>(size, -1));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i != j){
                matrix[i][j] = rand() % (maxValue - minValue + 1) + minValue;
            }
        }
    }

    return matrix;
}


