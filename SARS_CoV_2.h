//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_SARS_COV_2_H
#define EXERCISE_1_SARS_COV_2_H

#include "String.h"

class SARS_CoV_2 {
private:
    String name;
    String father;
    char type;
    double f;
    double p;
public:
    SARS_CoV_2() : name(), type(0), f(0), father(), p(0){}
    SARS_CoV_2(String n, char t, String fa) : type(t), f(0), p(0) {
        name = n;
        father = fa;
    }
    ~SARS_CoV_2() {}
    SARS_CoV_2(const SARS_CoV_2& covid);  // copy constructor
    SARS_CoV_2& operator= (const SARS_CoV_2& rhs);  // copy assignment operator

    String getName() const {return name;}
    String getFather() const {return father;}
    void setNameIndex(int i, char c) {name[i] = c;}
    char getType() const {return type;}
    double getP() const {return p;}
    double getF() const {return f;}
    int getLen() {return name.size();}
    void setP(double pi) {p = pi;}

    void generateHF(const String& target);
    virtual void update() {std::cout << "SARS update()\n";}

    friend std::ostream& operator<<(std::ostream& os, const SARS_CoV_2& s);
};
inline std::ostream& operator<<(std::ostream& os, const SARS_CoV_2& s) {
    os << s.type << " " << s.name;
    return os;
}

#endif //EXERCISE_1_SARS_COV_2_H
