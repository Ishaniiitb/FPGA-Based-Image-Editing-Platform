#ifndef READBMP_H_
#define READBMP_H_
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<vector<vector<int>>> ReadBMP(const string& filename, int& width, int& height);
#endif