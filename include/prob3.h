#include <iostream>
#include <armadillo>

#ifndef __prob3_h__  
#define __prob3_h__
using namespace std;
using namespace arma;

double max_offdiag_symmetric(const mat& A, int& k, int& l,bool status);

#endif