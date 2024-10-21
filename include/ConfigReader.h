//
// Created by Justine on 18.10.2024.
//

#ifndef TEST_CONFIGREADER_H
#define TEST_CONFIGREADER_H

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

class ConfigReader {
public:
    ConfigReader(const string &filename);

    //metoda do wczytywania pliku konf
    void loadConfig();

    //dostep do poszczegolnych parametrow
    bool isGenerateRandom() const;
    bool isSymmetrical() const;
    int algorithmType() const;
    int getInstanceSize() const;
    int getMinValue() const;
    int getMaxValue() const;
    string getInputFile() const;
    string getOutputFile() const;
    int getRepeatCount() const;


private:
    string fileName;
    map<string, string> configValues;

    //usuwanie spacji
    string trim(const string &str);
};


#endif //TEST_CONFIGREADER_H
