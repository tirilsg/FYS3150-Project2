#include <iostream>
#include <armadillo>


#ifndef __prob4_h__  
#define __prob4_h__
using namespace std;
using namespace arma;

void jacobiRotation(arma::mat& A, arma::mat& R, int k, int l);
void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged);
void check_results(mat& C, arma::vec& eigenvalues, arma::mat& eigenvectors);

#endif