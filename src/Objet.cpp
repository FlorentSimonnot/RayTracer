//
// Created by Narex on 05/04/2016.
//

#include "../include/Objet.hpp"

Objet::Objet() {
    epsilon = 0.001;
}

Objet::~Objet() { }

float Objet::getEpsilon() {
    return epsilon;
}
