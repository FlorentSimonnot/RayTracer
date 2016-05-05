//
// Created by Narex on 05/04/2016.
//

#include "ParentPointVector.hpp"

ParentPointVector::ParentPointVector(double x, double y, double z)
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


double ParentPointVector::getX() const {
    return x;
}

double ParentPointVector::getY() const {
    return y;
}

double ParentPointVector::getZ() const {
    return z;
}

void ParentPointVector::setX(double v) {
    this->x = v;
}

void ParentPointVector::setY(double v) {
    this->y = v;
}

void ParentPointVector::setZ(double v) {
    this->z = v;
}
