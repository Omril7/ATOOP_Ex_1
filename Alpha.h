//
// Created by Omri Leizerovitch on 04/03/2022.
//

#ifndef EXERCISE_1_ALPHA_H
#define EXERCISE_1_ALPHA_H

#include "SARS_CoV_2.h"

class Alpha : public SARS_CoV_2 {
public:
    Alpha() : SARS_CoV_2() {}
    Alpha(String n, String fa) : SARS_CoV_2(n, 'a', fa) {
        setP(0.37);
    }
    void update() override;
};

#endif //EXERCISE_1_ALPHA_H
