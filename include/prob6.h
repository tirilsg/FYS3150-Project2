#include <iostream>
#include <armadillo>
#include <chrono>
#include <fstream>
#include <random>

#ifndef __prob6_h__  
#define __prob6_h__
using namespace std;
using namespace arma;

mat disA(int n);
void export_data(string eigval, string eigvec, const arma::mat& A, double eps, arma::vec& eigenvalues_jacobi, arma::mat& eigenvectors_jacobi, const int maxiter, int& iterations, bool& converged);

#endif