//
// Created by Omri Leizerovitch on 04/03/2022.
//

#include "Ex1.h"

bool compareF(const SARS_CoV_2* a, const SARS_CoV_2* b) {
    return (a->getF() > b->getF());
}

void Ex1::init(char* file1, char* file2) {
    /*
     * initialize all parameters from 2 data files
     */
    ifstream cnfg(file1);
    ifstream fstGeneration(file2);
    if (!cnfg || !fstGeneration) {
        cerr << "error: invalid input." << endl;
        exit(-1);
    }
    setConfig(cnfg);
    set1stGen(fstGeneration);

    for(int i=0; i<n; i++) {
        if( fstGenArr[i] == 'a') {
            population.push_back(new Alpha(fstGen[i], fstGen[i]));
        }if( fstGenArr[i] == 'd') {
            population.push_back(new Delta(fstGen[i], fstGen[i]));
        }if( fstGenArr[i] == 'o') {
            population.push_back(new Omicron(fstGen[i], fstGen[i]));
        }
    } // copy first generation to population

    // set strongest
    if( fstGenArr[0] == 'a') {
        strongestChar = 'a';
        strongest = fstGen[0];
    }
    else if( fstGenArr[0] == 'd') {
        strongestChar = 'd';
        strongest = fstGen[0];
    }
    else if( fstGenArr[0] == 'o') {
        strongestChar = 'o';
        strongest = fstGen[0];
    }
}
void Ex1::start() {
    if(simulations == 0) {
        for(int i=0; i<n; i++) {
            cout << fstGenArr[i] << " " << fstGen[i] << endl;
        }
        return;
    }

    while(simulations > 0 && !match()) {
        for(auto & i : population) {
            i->update();
            i->generateHF(target);
        }
        sort(population.begin(), population.end(), compareF);
        groupUpdate();
        setStrongest();

        simulations--;
    }

    for(int i=0; i<fstGen.size(); i++) {
        cout << *population[i] << endl;
    }

    cout << endl;

    for(int i=0; i<fstGen.size(); i++) {
        cout << fstGenArr[i] << " " << fstGen[i] << " " << fstGen[i].count() -1 << endl;
    }
    cout << endl;
    cout << strongestChar << " " << strongest << endl;
}

void Ex1::setConfig(ifstream& ifs) {
    /*
     * initialize parameters from config.dat file
     */
    string num, buffer;
    getline(ifs, num);
    istringstream(num) >> l;
    if(l < 3 || l > 1000) {
        cerr << "ERROR: Invalid input.";
        exit(-1);
    }

    char tar[l];
    getline(ifs, buffer);
    buffer.erase(remove(buffer.begin(), buffer.end(), ' '), buffer.end());
    strcpy(tar, buffer.c_str());
    target = String(tar);

    getline(ifs, num);
    istringstream(num) >> simulations;
    if(simulations > 1000000) {
        cerr << "ERROR: Invalid input.";
        exit(-1);
    }
}
void Ex1::set1stGen(ifstream& ifs) {
    /*
     * initialize parameters from first_generation.dat file
     */
    string num, buffer;
    getline(ifs, num);
    istringstream(num) >> n;
    fstGenArr = new char[n];
    int i=0;
    while(getline(ifs, buffer)) {
        buffer.erase(remove(buffer.begin(), buffer.end(), ' '), buffer.end());
        if( buffer[0] == 'a') {
            buffer.erase(remove(buffer.begin(), buffer.end(), 'a'), buffer.end());
            const char* str = buffer.c_str();
            String s(str);
            fstGen.push_back(s);
            fstGenArr[i] = 'a';
        }
        if( buffer[0] == 'd') {
            buffer.erase(remove(buffer.begin(), buffer.end(), 'd'), buffer.end());
            const char* str = buffer.c_str();
            String s(str);
            fstGen.push_back(s);
            fstGenArr[i] = 'd';
        }
        if( buffer[0] == 'o') {
            buffer.erase(remove(buffer.begin(), buffer.end(), 'o'), buffer.end());
            const char* str = buffer.c_str();
            String s(str);
            fstGen.push_back(s);
            fstGenArr[i] = 'o';
        }
        i++;
    }
}

void Ex1::groupUpdate() {
    int random1 = rand() % n;
    int random2 = rand() % n;
    while(random1 == random2) {
        random2 = rand() % n;
    }
    char a[l];
    char b[l];
    strcpy(a, fstGen[random1].getData());
    strcpy(b, fstGen[random2].getData());

    int s = rand() % l;
    int t = rand() % l;
    while(s > t || s < 2 || s > l-2 || t < 3 || t > l-3) {
        s = rand() % l;
        t = rand() % l;
    }
    for(int i=s; i<t+1; i++) {
        char temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    } // swap char's

    char a_type = fstGenArr[random1];
    char b_type = fstGenArr[random2];

    auto q = population.end();
    q--;
    auto p = population.erase(q);
    delete *p;
    q = population.end();
    q--;
    p = population.erase(q);
    delete *p;

//    population.pop_back();
//    population.pop_back();

    String sa(a);
    String sb(b);

    if( a_type == 'a') {
        Alpha* alpha = new Alpha(sa, fstGen[random1]);
        population.push_back(alpha);
    }
    if( a_type == 'd') {
        Delta* delta = new Delta(sa, fstGen[random1]);
        population.push_back(delta);
    }
    if( a_type == 'o') {
        Omicron* omicron = new Omicron(sa, fstGen[random1]);
        population.push_back(omicron);
    }

    if( b_type == 'a') {
        Alpha* alpha = new Alpha(sb, fstGen[random2]);
        population.push_back(alpha);
    }
    if( b_type == 'd') {
        Delta* delta = new Delta(sb, fstGen[random2]);
        population.push_back(delta);
    }
    if( b_type == 'o') {
        Omicron* omicron = new Omicron(sb, fstGen[random2]);
        population.push_back(omicron);
    }
}
void Ex1::setStrongest() {
    double count = 0;
    for(int i=1; i<strongest.size(); i++) {
        if( strongest[i] == target[i]) {
            count += 1;
        }
    }
    double f = count / static_cast<double>(strongest.size());

    if (population[0]->getF() > f) {
        strongest = population[0]->getName();
    }
}
bool Ex1::match() {
    for(int i=0; i<n; i++) {
        if(population[i]->getF() == 1) {
            cout << "found match!" << endl;
            return true;
        }
    }
    return false;
}
