#include <iostream>
#include <armadillo>
#include <chrono>
#include <fstream>
#include <random>
#include "prob5.h"
#include "prob4.h"
#include "prob2.h"

using namespace std;
using namespace arma;
using namespace chrono;

void iterTime(const vector<int>& sizes, const string& outputFilename, int maxiterations, bool not_dense, double a, double d) {
    ofstream outputFile(outputFilename); // we open the file we want to save data in
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        return;
    }
    outputFile << "Matrix Size (N)\tIterations\tExecution Time (ms)" << endl;
    if(not_dense){
        for (int N : sizes) {
            mat A=createA(N, a, d); // since the matrix is not dense we create it using the createA function 
            int iterations = 0;
            bool converged = false;
            auto start = high_resolution_clock::now();//starts counting time
            // Performs the calculations using jacobi's rotation algorithm by calling jacobi_eigensolver
            vec eigenvalues;
            mat eigenvectors;
            jacobi_eigensolver(A, 1e-6, eigenvalues, eigenvectors, maxiterations, iterations, converged);
            //stops counting time and calculates the total run-time
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            // we write the data to the output file
            outputFile << N << "\t" << iterations << "\t" << duration.count() << endl;
        }
    }
    else{
        for (int N : sizes) {
            mat A=randu<mat>(N, N); //we create a random dense matrix with dimentions N
            A*=10; // the random values are only between 0 and 1, so we multiply by 10 to get a better set of values
            int iterations = 0;
            bool converged = false;
            auto start = high_resolution_clock::now(); //starts counting time
            // Performs the calculations using jacobi's rotation algorithm by calling jacobi_eigensolver
            vec eigenvalues;
            mat eigenvectors;
            jacobi_eigensolver(A, 1e-6, eigenvalues, eigenvectors, maxiterations, iterations, converged);
            //stops counting time and calculates the total run-time
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            // we write the data to the output file
            outputFile << N << "\t" << iterations << "\t" << duration.count() << endl;
         }
    }
    outputFile.close(); // we close the output file
}

