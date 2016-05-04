//
// Created by Narex on 05/04/2016.
//

#include "../include/Objet.hpp"

Objet::Objet(void) { }

Objet::Objet(const Objet &c) { }

Objet::~Objet() { }

void Objet::setColor(int color) {
    this->color_ = color;
}

int Objet::getColor(){
    return color_;
}