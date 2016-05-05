//
// Created by Narex on 05/04/2016.
//

#include "Point.hpp"

Point::Point(void) : ParentPointVector() { }

Point::Point(float x, float y, float z) : ParentPointVector(x, y, z) { }

Point::~Point() { }

float Point::distance(const Point &p) {
    return sqrt(SQR(p.x - this->x) + SQR(p.y - this->y) + SQR(p.z - this->z));
}

Point Point::operator=(const ParentPointVector &p) {
    this->ParentPointVector::operator=(p);
    return (*this);
}

Point Point::operator=(const Point &p) {
    this->ParentPointVector::operator=(p);
    return (*this);
}
