//
// Created by Justine on 18.10.2024.
//

#include "../include/ConfigReader.h"

using namespace std;

ConfigReader::ConfigReader(const string &fileName) : fileName(fileName) {}

void ConfigReader::loadConfig() {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw runtime_error("Nie udalo sie otworzyc pliku konfiguracyjnego " + fileName);
    }
    string line;
    while (getline(file, line)) {
        //pomijanie komentarzy (#)
        if (line.empty() || line[0] == '#') {
            continue;
        }

        //wyszukiwanie klucza i wartosci
        istringstream iss(line);
        string key, value;
        if (getline(iss, key, '=') && getline(iss, value)) {
            configValues[trim(key)] = trim(value);
        }
    }

    file.close();
}
    //funkcje pomocnicze
    bool ConfigReader::isGenerateRandom() const{
        return configValues.at("generate_random_matrix") == "true";
    }
    bool ConfigReader::isSymmetrical() const{
        return configValues.at("symmetrical") == "true";
    }
    bool ConfigReader::isProgressBar() const{
        return configValues.at("progress_bar") == "true";
    }
    int ConfigReader::getMinValue() const {
    return stoi(configValues.at("matrix_min"));
    }
    int ConfigReader::getMaxValue() const {
        return stoi(configValues.at("matrix_max"));
    }
    int ConfigReader::algorithmType() const{
        return stoi(configValues.at("algorithm"));
    }

    int ConfigReader::getInstanceSize() const {
        return stoi(configValues.at("instance_size"));
    }

    int ConfigReader::getRandCount() const {
        return stoi(configValues.at("rand_count"));
    }
    string ConfigReader::getInputFile() const {
        return configValues.at("input_matrix_file");
    }
    int ConfigReader::getRepeatCount() const {
        return stoi(configValues.at("repeat_count"));

    }
    string ConfigReader::getOutputFile() const {
        return configValues.at("output_file");
    }

    //usuwanie spacji
    string ConfigReader::trim(const string &str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, last - first + 1);
    }

