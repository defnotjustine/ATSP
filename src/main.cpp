#include <iostream>
using namespace std;
#include <vector>
#include "../include/NearestNeighbours.h"
#include "../include/FileReader.h"

int main() {
    string filename = "C:\\Users\\Justine\\Desktop\\studia\\5sem\\algorytmy\\test\\test\\data\\matrix_6x6.atsp"; //nazwa pliku

    //wczytujemy macierz z pliku
    FileReader fileReader(filename);
    vector<vector<int>> distanceMatrix = fileReader.getDistanceMatrix();

    //obiekt klasy NearestNeighbours
    NearestNeighbours nearestNeighbours(distanceMatrix);
    int startCity = 0;
    int totalDistance = 0; //dlugosc trasy
    //wynik - najkrotsza trasa
    vector<int> tour = nearestNeighbours.findShortestPath(startCity, totalDistance);

    cout << "Najktotsza trasa: ";
    //iterujemy po wszystkich miastach w najkrotszej trasie i wypisujemy
    for(int city : tour){
        cout << city << " ";
    }
    cout << endl;

    cout << "Dlugosc trasy: " << totalDistance << endl;

    return 0;

}
