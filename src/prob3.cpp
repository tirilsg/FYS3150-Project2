#include <iostream>
#include <armadillo>
#include "prob3.h"

using namespace std;
using namespace arma;

double max_offdiag_symmetric(const mat& A, int& k, int& l,bool status) {
    int n = A.n_rows; //we use.n_rows to find the dimensions of our matrix A
    double maxOffDiag = 0; //we set the max value = 0 before looping through 
    //the elements of our matrix 
    // the loop runs throug each element and checks if the absolute value of this new element is larger than the previos
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { 
            double current = abs(A(i, j));
            if ((current) > maxOffDiag) {
                maxOffDiag = current;
                k = i;
                l = j;
            }
        }
    }
    //if the argument status is true the function will print the largest off-diagonal element 
    if (status){
        cout << "The largest off-diagonal element is abs(" << maxOffDiag << "), at indices (" << k << ", " << l << ")." << endl;
    }
    return (A(k, l)); //the function returns the largest off-diagonal element 
}
