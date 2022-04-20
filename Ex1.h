//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_EX1_H
#define EXERCISE_1_EX1_H

#include "Alpha.h"
#include "Delta.h"
#include "Omicron.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Ex1 {
public:
    Ex1(char* f1, char* f2) : l(0), simulations(0), n(0), strongest() {init(f1, f2); };
    void init(char* f1, char* f2);
    void start();
    void setConfig(ifstream& ifs);
    void set1stGen(ifstream& ifs);
    void groupUpdate();
    void setStrongest();
    bool match();

private:
    unsigned int l;           // strings dimension  - 3 <= l <= 1,000
    unsigned int simulations; // num of simulations - simulations < 1,000,000
    unsigned int n;           // number of viruses  - 2 <= n <= 200
    String target;            // target string

    char* fstGenArr;          // array that keeps the 1st generation types
    vector<String> fstGen;    // vector of the 1st generation strings
    vector<SARS_CoV_2*> population;
    String strongest;
    char strongestChar;
};


#endif //EXERCISE_1_EX1_H
