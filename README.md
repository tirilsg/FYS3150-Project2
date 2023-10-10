# Project2 FYS3150 Second try
This repository contains our programproject.cpp, which runs a code that compiles a bunch of header-files '*'prob2.h'*, *'prob3.h'*, *'prob4.h'*, *'prob5.h'* and *'prob6.h'* which all contain definition-statements for functions defined in their own .cpp-files. The .h files are all saved in their own folder "include", and the corresponding .cpp files with the same name are saved in a folder "src". To be able to use this code when running our main program, we need to remember to link these when compiling the code. The program is furtherheavily reliant on usage of 'armadillo'. To run the code, one will have to remember to link armadillo as well, which is done by using the -larmadillo flag when linking. Follow these steps when linking to make the code work in an ubuntu terminal: 

--------

* g++ project.cpp src/*.cpp -I include -o project -O2 -llapack -lblas -larmadillo
* make project
* ./project

--------

To pass the Project, I did make changes to everything you commented on. The structure of the project was changed, and I split it into header files containing definitions and cpp files containing code, saved in different folders. I changed the linking process to accomodate these changes as well, and used the -larmadillo flag to make it easier for whoever would want to run the code to do so. The Jacobi's rotation algorithm function was rewritten to make it more efficient by following the recipe in the lecture notes suggested, and I created another function that makes sure that the code runs as intended. For problem 5 we rewrote the code entirely, because when I looked at it I noticed I hadn't really answered it. I made sure to only use matrices up to size N=220, when this turned out to be large enough to give us a pattern. I also added a part to this code that checked how long the algorithm had to run to give us the appropriate answers, and tested it on both tridiagnal matrices, as well as dense matrices of the same sizes. To make sure that the reader of this project could follow along without having to run the code themselves, I inserted both what was printed into the terminal, data from .text-files created as well as figures into the .tex document. 
