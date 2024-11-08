#ifndef WRITEBMP_H_
#define WRITEBMP_H_
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void WriteBMP(const string& filename, vector<vector<vector<int>>> pixelData, int width, int height);
#endif