#include <iostream>
#include <armadillo>
#include "prob4.h"
#include "prob3.h"


void jacobiRotation(mat& A, mat& R, int k, int l) {
    int n = A.n_rows;
    double a_kk = A(k,k);  //we define some variables a_kk, a_ll and a_kl as diagonal elemts 
    double a_ll = A(l,l); // at the positions given by l and k
    double a_kl = A(k,l);
    double tau = 0.0;
    if (abs(a_kl) > 1e-10) { //checking if the off-diagonals are sufficiently small. if not:
        double tan_theta = (a_ll - a_kk) / (2.0 * a_kl); //tan_theta gets calculated
        double t;
        if (tan_theta >= 0) {
            t = 1.0 / (tan_theta + sqrt(1.0 + tan_theta * tan_theta)); // t for positive tan_theta
        } else {
            t = -1.0 / (-tan_theta + sqrt(1.0 + tan_theta * tan_theta)); // t for negative tan_theta
        }
        double c = 1.0 / sqrt(1.0 + t * t); // this equates to cos(theta)
        double s = c * t; // this equates to sin(theta)
        //we update the matrix using the Jacobi rotation 
        A(k,k) = a_kk * c * c - 2.0 * a_kl * c * s + a_ll*s*s;
        A(l,l) = a_ll * c * c + 2.0 * a_kl * c * s + a_kk*s*s;
        A(k,l) = 0.0; 
        A(l,k) = 0.0;
        //all rows that arent k and l gets updated as well
        for (int i = 0; i < n; ++i) {
            if (i != k && i != l) {
                double a_ik = A(i,k);
                double a_il = A(i,l);
                A(i,k) = a_ik*c - a_il*s;
                A(k,i) = A(i,k);
                A(i,l) = a_il*c + a_ik*s;
                A(l,i) = A(i,l);
            }
            //then the eigenvectors stored in the matrix R get updated for all rows
            double r_ik = R(i, k);
            double r_il = R(i, l);
            R(i,k) = r_ik*c - r_il*s;
            R(i,l) = r_il*c + r_ik*s;
        }
    }
}

void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged) {
    // we define n and 
    int n = A.n_rows;
    eigenvectors = mat(n, n, fill::eye);
    mat B = A;
    converged = false;
    iterations = 0;
    for (iterations = 0; iterations < maxiter; ++iterations) {
        int k, l;
        double maxOffDiag = abs(max_offdiag_symmetric(B, k, l,false)); //we call max_offdiag_symmetric to define the max off-diagonal value
        if (maxOffDiag < eps) { //we check if the largest off-diagonal value is sufficiently small 
            converged = true; //if it is, we stop the loop 
            break;
        }
        jacobiRotation(B, eigenvectors, k, l); //we perform a rotation and define a new B
    }
    eigenvalues = B.diag(); //the diagonal now contains the eigenvalues, which we extract
    //then we sort the eigenvectors and normalize the matrix 
    uvec sorted_indices = sort_index(eigenvalues);
    eigenvalues = eigenvalues(sorted_indices);
    eigenvectors= normalise(eigenvectors.cols(sorted_indices));
}

void check_results(mat& C, arma::vec& eigenvalues_jacobi, arma::mat& eigenvectors_jacobi){
    arma::vec eigenvalues_arma;
    arma::mat eigenvectors_arma;
    arma::eig_sym(eigenvalues_arma, eigenvectors_arma, C); //analytical solution 

    //then we examine the difference between our results
    bool eigenvalues_match = approx_equal(abs(eigenvalues_arma), abs(eigenvalues_jacobi), "absdiff", 1e-6);
    bool eigenvectors_match = approx_equal(abs((eigenvectors_arma)), abs(eigenvectors_jacobi), "absdiff",1e-6);
    if (eigenvalues_match && eigenvectors_match) {
        cout << "Eigenvalues and eigenvectors match between the two methods." << endl;
        } else {
            cout << "Eigenvalues and/or eigenvectors do not match between the two methods." << endl;
            }
}