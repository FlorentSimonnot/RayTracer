//
// Created by Narex on 05/04/2016.
//

#include "Object.hpp"

Object::Object(void) { }

Object::Object(const Object &c) { }

Object::~Object() { }

void Object::setColor(int color) {
    this->color = color;
}

int Object::getColor() {
    return color;
}