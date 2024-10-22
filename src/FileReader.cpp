//
// Created by Justine on 17.10.2024.
//

#include "../include/FileReader.h"

using namespace std;

//Konstruktor
FileReader::FileReader(const std::string &fileName) {
    readFile(fileName);
}
//Funkcja do wczytywania danych z pliku
void FileReader::readFile(const string &fileName) {
    ifstream file(fileName);

    if(!file){
        //cout << "sciezka do pliku" << config.getInputFile() << endl;
        cerr << "Nie udalo sie otworzyc plik " << fileName << endl;
        exit(1);//wyjscie z programu
    }

    int cityCount;
    file >> cityCount; //wczytanie liczby miast

    distanceMatrix.resize(cityCount, vector<int>(cityCount));
    string line;
    getline(file, line);  // Pobranie pustej linii po liczbie miast

    for(int i = 0; i < cityCount; i++){
        getline(file, line);
        stringstream ss(line);
        for(int j = 0; j < cityCount; j++){
            ss >> distanceMatrix[i][j];
        }
    }
}

//zwraca macierz
vector<vector<int>> FileReader::getDistanceMatrix() {
    return distanceMatrix;
}