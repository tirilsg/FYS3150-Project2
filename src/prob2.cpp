#include <iostream>
#include <armadillo>
#include "prob2.h"


using namespace std;
using namespace arma;

mat createA(int N, double a, double d) {
    mat A(N,N,arma::fill::zeros); //an array with the correct dimentions NxN is created
    //we fill the diagonals with the correct values a and d so we get the tridiagonal matrix we wanted
    A.diag() = arma::vec(N,arma::fill::ones)*d;
    A.diag(1) = arma::vec(N-1,arma::fill::ones)*a;
    A.diag(-1) =arma::vec(N-1,arma::fill::ones)*a;
    return A; //the function returns the array that resembles the A NxN tridiag(a,d,a)
}

mat eigvec(int N, double a, double d) {
    //we calculate the eigenvectors and store them in a matrix
    mat eigvec(N, N, fill::zeros); //matrix with the correct dimentions NxN
    //we insert two for-loops that loops through each element of the matrix, and fills the
    //correct value for the eigenvector-element, given by the formulas in the assignment text
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            eigvec(i, j) = sin((i + 1) * (j + 1) * datum::pi/ (N + 1));
        }
    }
    return normalise(eigvec); //the function returnsour matrix filled with eigenvectors
}

vec eigval(int N, double a, double d) {
    //we calculate the eigenvalues and store them, in a vector
    vec eigvals(N, fill::zeros);
    for (int i = 0; i < N; ++i) {
        //for the eigenvalues we only ned to loop throug a single for-loop, since each eigenvector
        //only has a single corresponding eigenvalue. the values is calculated using the analytic formula from the assignment text
        eigvals(i) = d + 2 * a * cos((i + 1) * datum::pi / (N + 1));
    }
    return eigvals; //the function returns the vector containing the eigenvalues 
}

void solveMat(int N, double a, double d, bool visual,bool match){
    vec eigenvalues_an= eigval(N, a, d); //we calculate eigenvalues using the function eigval
    mat eigenvectors_an = eigvec(N, a, d); //calculates eigenvectors using eigvec
    mat A_mat = (createA(N, a, d)); //uses createA to establish the matrix A
    vec eigenvalues;
    mat eigenvectors;
    arma::eig_sym(eigenvalues, eigenvectors, A_mat); //calculates eigenvalues and eigenvectors using 
    //the integrated armadillo-function eig_sym
    //the eigenvalues we computed by our formulas are sorted, and the corresponding eigenvectors are as well
    uvec sorted_indices = sort_index(eigenvalues_an);
    eigenvalues_an = eigenvalues_an(sorted_indices);
    eigenvectors_an = normalise(eigenvectors_an.cols(sorted_indices));
    //if we call the function with the argument visual being true, the program
    //will print the eigenvalues and eigenvectors
    if (visual){
        cout << "Eigenvalues computed using eigval function:" << endl;
        cout << eigenvalues_an << endl;
        cout << "Eigenvalues obtained from Armadillo:" << endl;
        cout << (eigenvalues) << endl;
        cout << "Eigenvectors computed using eigvec function:" << endl;
        cout << eigenvectors_an << endl;
        cout << "Eigenvectors obtained from Armadillo:" << endl;
        cout << (eigenvectors) << endl;
    }
    //we check that the two methods gave the same results by examinig the difference
    bool eigenvalues_match = approx_equal(abs(eigenvalues_an), abs(eigenvalues), "absdiff", 1e-6);
    bool eigenvectors_match = approx_equal(abs(eigenvectors_an), abs(eigenvectors), "absdiff", 1e-6);
    if (match){//if the function is called with the argument match = true, the code will print wether there was a match or not
        if (eigenvalues_match && eigenvectors_match) {
        cout << "Eigenvalues and eigenvectors match between the two methods." << endl;
        } else {
            cout << "Eigenvalues and/or eigenvectors do not match between the two methods." << endl;
            }
    }
}