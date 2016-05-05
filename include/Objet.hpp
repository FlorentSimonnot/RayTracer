//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJET_HPP
#define PROJECT_OBJET_HPP


#include "Materiaux.hpp"

class Objet {
private:

    float epsilon;
    /* Pour corriger approximation de calcul */

    Materiaux mat;

public:
    Objet();

    ~Objet();

    float getEpsilon();

};

#endif //PROJECT_OBJET_HPP
