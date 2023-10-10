# Project2 FYS3150 Second try
This repository contains our program main.cpp, which runs a code that compiles a bunch of header-files '*'prob2.h'*, *'prob3.h'*, *'prob4.h'*, *'prob5.h'* and *'prob6.h'*. The is heavily reliant on usage of 'armadillo', which is required to make the code work. To run the code, one will have to remember to link armadillo, which is done by following the steps; 

* g++ main.cpp -o main -O2  -L/mnt/c/Users/tiril/OneDrive/skole/FULLARMADILLO/tmp/include/ -llapack -lblas 
* make main
* ./main


in ubuntu when running the code. Replace the line *-L/mnt/c/Users/tiril/OneDrive/skole/FULLARMADILLO/tmp/include/* to link where you downloaded armadillo on your own machine. It is important to link the */include/* file.
