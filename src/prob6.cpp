#include <iostream>
#include <armadillo>
#include <chrono>
#include <fstream>
#include <random>
#include "prob6.h"
#include "prob4.h"


mat disA(int n) {
    double h = 1.0 / n;
    // Create the matrix A based on the discretization
    mat A(n + 1, n + 1, fill::zeros);
    for (int i = 0; i <= n; ++i) {
        A(i, i) = 2.0 / (h * h);
        if (i > 0) {
            A(i, i - 1) = -1.0 / (h * h);
            A(i - 1, i) = A(i, i - 1);
        }
    }
    return A;
}
void export_data(string eigval, string eigvec, const arma::mat& A, double eps, arma::vec& eigenvalues_jacobi, arma::mat& eigenvectors_jacobi, const int maxiter, int& iterations, bool& converged){
    jacobi_eigensolver(A, eps, eigenvalues_jacobi, eigenvectors_jacobi, maxiter, iterations, converged);
    eigenvalues_jacobi.save(eigval, raw_ascii); //the eigenvalues are saved in the file eigval
    eigenvectors_jacobi.save(eigvec, raw_ascii);//the eigenvectors are saved in the file eigvec
    cout << "Eigenvalues and eigenvectors saved to file "<< eigval << " and " << eigvec << endl;
}