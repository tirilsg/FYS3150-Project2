# Project2 FYS3150 Second try
This repository contains our programproject.cpp, which runs a code that compiles a bunch of header-files '*'prob2.h'*, *'prob3.h'*, *'prob4.h'*, *'prob5.h'* and *'prob6.h'* which all contain definition-statements for functions defined in their own .cpp-files. The .h files are all saved in their own folder "include", and the corresponding .cpp files with the same name are saved in a folder "src". To be able to use this code when running our main program, we need to remember to link these when compiling the code. The program is furtherheavily reliant on usage of 'armadillo'. To run the code, one will have to remember to link armadillo as well, which is done by using the -larmadillo flag when linking. Follow these steps when linking to make the code work in an ubuntu terminal: 

* g++ project.cpp src/*.cpp -I include -o project -O2 -llapack -lblas -larmadillo
* make project
* ./project
