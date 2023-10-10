#include <iostream>
#include <list>
#include <armadillo>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include "prob2.h"
#include "prob3.h"
#include "prob4.h"
#include "prob5.h"
#include "prob6.h"

using namespace std;
using namespace arma;

int main(){
    int N=6;
    double a=2;
    double d=5;
    bool visual=true;
    bool match=true;
    //test-run for the function solveMat
    cout << "Problem 2" << endl;
    solveMat(N, a, d, visual, match);
    mat B = {{1,   0,    0, 0.5},
             {0,   1, -0.7,   0},
             {0,   1, -0.7,   0},
             {0.5, 0,    0,   1}};//this is the matrix A from Problem2b in the assignment
    int k, l;
    bool status=true; //we set status=true for the function max_offdiag_symmetric to print the largest of-diagonal element value
    cout << "  " << endl;
    cout << "Problem 3" << endl;
    double maxOffDiag = max_offdiag_symmetric(B, k, l,status); //we run the code for the matrix B
    cout << "  " << endl;

    cout << "Problem 4" << endl;
    mat C = createA(N, a, d);

    //we define arguments needed to call our function jacobi_eigensolver
    vec eigenvalues_jacobi;
    mat eigenvectors_jacobi;
    double eps = 1e-6;
    int maxiter = 1000;
    int iterations;
    bool converged; 
    //then we call the function 
    jacobi_eigensolver(C, eps, eigenvalues_jacobi, eigenvectors_jacobi, maxiter, iterations, converged);
    check_results(C, eigenvalues_jacobi, eigenvectors_jacobi);
    cout << "  " << endl;

    cout << "Problem 5" << endl;
    vector<int> sizes = {6, 10, 20, 30, 50, 80, 120, 150, 180, 200, 220}; // Adjust as needed
    bool not_dense=true; 
    maxiter = 110000;
    string outputFilename = "prob5notdense.txt";
    iterTime(sizes, outputFilename, maxiter, not_dense, a, d);
    cout << "Data recorded in " << outputFilename << endl;
    not_dense=false; 
    outputFilename = "prob5dense.txt";
    iterTime(sizes, outputFilename, maxiter, not_dense, a, d);
    cout << "Data recorded in " << outputFilename << endl;

    cout << "  " << endl;
    cout << "Problem 6" << endl;
    N=10;
    mat A=disA(N+1);
    eigenvalues_jacobi=vec(N+1,fill::zeros);
    eigenvectors_jacobi=mat(N+1, N+1, fill::zeros);
    //then we use export_data to create text files containing the eigenvalues and eigenvectors 
    export_data("eigenvaluesn10.txt", "eigenvectorsn10.txt", A, eps, eigenvalues_jacobi, eigenvectors_jacobi, maxiter, iterations, converged);
    N=100;
    A=disA(N+1);
    eigenvalues_jacobi=vec(N,fill::zeros);
    eigenvectors_jacobi=mat(N, N, fill::zeros);
    //then we use export_data to create text files containing the eigenvalues and eigenvectors 
    export_data("eigenvaluesn100.txt", "eigenvectorsn100.txt", A, eps, eigenvalues_jacobi, eigenvectors_jacobi, maxiter, iterations, converged);
    return 0;
}