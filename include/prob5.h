#include <iostream>
#include <armadillo>
#include <chrono>
#include <fstream>
#include <random>

#ifndef __prob5_h__  
#define __prob5_h__
using namespace std;
using namespace arma;
using namespace chrono;

void iterTime(const vector<int>& sizes, const string& outputFilename, int maxiterations, bool not_dense, double a, double d);

#endif