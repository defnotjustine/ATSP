#include <iostream>
#include <vector>
#include <fstream>
#include "../include/NearestNeighbours.h"
#include "../include/FileReader.h"
#include "../include/ConfigReader.h"
#include "../include/MatrixGenerator.h"

using namespace std;

int main() {

//    //wczytanie konfiguracji
//    ConfigReader config("C:\\Users\\Justine\\Desktop\\studia\\5sem\\algorytmy\\test\\test\\config\\config.txt");
//    config.loadConfig();
//
//    //przechowujemy macierz odleglosci
//    vector<vector<int>> distanceMatrix;
//    //czy generujemy losowa macierz?
//    if(config.isGenerateRandom()){
//        MatrixGenerator generator;
//        generator.generateRandomMatrix(config.getInstanceSize(), config.getMinValue(), config.getMaxValue());
//    } else{
//        //wczytanie macierzy z pliku
//        FileReader fileReader(config.getInputFile());
//        distanceMatrix = fileReader.getDistanceMatrix(); //????????
//    }

//-------------------------------------
    //string filename = "C:\\Users\\Justine\\Desktop\\studia\\5sem\\algorytmy\\test\\test\\data\\matrix_6x6.atsp"; //nazwa pliku

    //wczytujemy macierz z pliku
    string basePath = "../data/";
    string fileName = "matrix_6x6.atsp";
    string filePath = basePath+fileName;
    FileReader fileReader(filePath);
    vector<vector<int>> distanceMatrix = fileReader.getDistanceMatrix();

    //obiekt klasy NearestNeighbours
    NearestNeighbours nearestNeighbours(distanceMatrix);
    int startCity = 0;
    int shortestPath = nearestNeighbours.findShortestPath();
    cout << "Dlugosc najkrotszej trasy: " << shortestPath << endl;
    //wynik - najkrotsza trasa
//    for (int i = 0; i < config.getRepeatCount(); i++){
//        vector<int> tour = nearestNeighbours.findShortestPath(startCity, totalDistance);
//        cout << "Powtorzenie " << i + 1 << ": Najkrotsza trasa: ";
//        //iterujemy po wszystkich miastach w najkrotszej trasie i wypisujemy
//        for(int city : tour){
//            cout << city << " ";
//        }
//        cout << "Dlugosc trasy: " << totalDistance << endl;
//    }

//
//    //zapis wynikow do pliku
//    ofstream outputFile(config.getOutputFile());
//    outputFile << totalDistance << endl;
//    outputFile.close();


    return 0;

}
