//
// Created by Omri Leizerovitch on 04/03/2022.
//

#include "SARS_CoV_2.h"

SARS_CoV_2::SARS_CoV_2(const SARS_CoV_2& covid) {
    name = covid.name;
    father = covid.father;
    type = covid.type;
    f = covid.f;
    p = covid.p;
}

void SARS_CoV_2::generateHF(const String& target) {
    double count = 0;
    for(int i=1; i<name.size(); i++) {
        if( name[i] == target[i]) {
            count += 1;
        }
    }
    f = count / static_cast<double>(name.size());
}
SARS_CoV_2& SARS_CoV_2::operator= (const SARS_CoV_2& rhs) {
    if(this == &rhs) {
        return *this;
    }
    name = rhs.name;
    father = rhs.father;
    type = rhs.type;
    f = rhs.f;
    p = rhs.p;

    return *this;
}
