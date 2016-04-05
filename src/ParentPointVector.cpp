//
// Created by Narex on 05/04/2016.
//

#include "../include/ParentPointVector.hpp"

ParentPointVector::ParentPointVector(float x, float y, float z)
        : x(x),
          y(y),
          z(z) { }

ParentPointVector::ParentPointVector(void) : x(0), y(0), z(0) { }

ParentPointVector::~ParentPointVector() { }

ParentPointVector ParentPointVector::operator+(const ParentPointVector &p) {
    return ParentPointVector(this->x + p.x, this->y + p.y, this->z + p.z);
}

ParentPointVector ParentPointVector::operator-(const ParentPointVector &p) {
    return ParentPointVector(this->x - p.x, this->y - p.y, this->z - p.z);
}

bool ParentPointVector::operator==(const ParentPointVector &p) {
    return this->x == p.x && this->y == p.y && this->z == p.z;
}

bool ParentPointVector::operator!=(const ParentPointVector &p) {
    return this->x != p.x || this->y != p.y || this->z != p.z;
}

ParentPointVector ParentPointVector::operator=(const ParentPointVector &p) {
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
    return (*this);
}


float ParentPointVector::getX() const {
    return x;
}

float ParentPointVector::getY() const {
    return y;
}

float ParentPointVector::getZ() const {
    return z;
}
