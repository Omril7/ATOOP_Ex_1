//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_DELTA_H
#define EXERCISE_1_DELTA_H

#include "SARS_CoV_2.h"

class Delta : public SARS_CoV_2 {
public:
    Delta() : SARS_CoV_2() {}
    Delta(String n, String fa) : SARS_CoV_2(n, 'd', fa) {
        double pi = 1 / static_cast<double>(getLen());
        setP(pi);
    }
    void update() override;
};

#endif //EXERCISE_1_DELTA_H
