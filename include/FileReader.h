//
// Created by Justine on 17.10.2024.
//

#ifndef TEST_FILEREADER_H
#define TEST_FILEREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class FileReader {
public:
    FileReader(const string &fileName);
    vector<vector<int>> getDistanceMatrix();

private:
    vector<vector<int>> distanceMatrix;
    void readFile(const string &fileName);
};


#endif //TEST_FILEREADER_H
