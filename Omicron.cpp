//
// Created by Omri Leizerovitch on 04/03/2022.
//

#include "Omicron.h"

void Omicron::update() {
    int ran = rand() % 100;
    double r = static_cast<double>(ran) / 100;
    if( r < getP() ) {
        for(int i=0; i<getLen(); i++) {
            if( getName()[i] == 'A') {
                setNameIndex(i, 'T');
            }
            if( getName()[i] == 'C') {
                setNameIndex(i, 'G');
            }
            if( getName()[i] == 'G') {
                setNameIndex(i, 'C');
            }
        }
    }
}