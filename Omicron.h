//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_OMICRON_H
#define EXERCISE_1_OMICRON_H

#include "SARS_CoV_2.h"

class Omicron : public SARS_CoV_2 {
public:
    Omicron() : SARS_CoV_2() {}
    Omicron(String n, String fa) : SARS_CoV_2(n, 'o', fa) {
        double pi = 2 / static_cast<double>(getLen());
        setP(pi);
    }
    void update() override;
};

#endif //EXERCISE_1_OMICRON_H
