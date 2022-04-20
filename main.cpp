//
// Created by Omri Leizerovitch, ID :316542166
//

#include "Ex1.h"

using namespace std;

int main(int argc, char** argv) {
    /*
     * argv[1] = config.dat
     * argv[2] = first_generation.dat
     */
    if (argc != 3) {
        cerr << "error: invalid input." << endl;
        exit(-1);
    }

    Ex1 *ex1 = new Ex1(argv[1], argv[2]);
    ex1->start();
}

/* g++ main.cpp Ex1.cpp SARS_CoV_2.cpp Alpha.cpp Delta.cpp
 * Omicron.cpp String.cpp -std=c++11 -o simCOVID
 *
 * ./simCOVID config.dat first_generation.dat
 */