#include <iostream>
#include <armadillo>

#ifndef __prob2_h__  
#define __prob2_h__
using namespace std;
using namespace arma;

mat createA(int N, double a, double d);

mat eigvec(int N, double a, double d);

vec eigval(int N, double a, double d);

void solveMat(int N, double a, double d, bool visual,bool match);

#endif