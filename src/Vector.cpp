//
// Created by Narex on 05/04/2016.
//

#include "../include/Vector.hpp"

Vector::Vector() : ParentPointVector() { }

Vector::Vector(double x, double y, double z) : ParentPointVector(x, y, z) { }

Vector::~Vector() { }

Vector Vector::nullVector() {
    return Vector(0, 0, 0);
}

Vector Vector::operator=(const ParentPointVector &p) {
    this->ParentPointVector::operator=(p);
    return (*this);
}

Vector Vector::operator=(const Vector &p) {
    this->ParentPointVector::operator=(p);
    return (*this);
}

Vector Vector::operator+(const Vector &p) {
    Vector result;
    result = this->ParentPointVector::operator+(p);
    return result;
}

Vector Vector::operator-(const Vector &p) {
    Vector result;
    result = this->ParentPointVector::operator-(p);
    return result;
}

Vector Vector::operator*(const Vector &v) {
    double x = this->y * v.z - this->z * v.y;
    double y = this->z * v.x - this->x * v.z;
    double z = this->x * v.y - this->y * v.x;
    return Vector(x, y, z);
}

double Vector::produitScalaire(const Vector &v) {
    double ps = 0;
    ps = this->getX() + v.getX()
         + this->getY() + v.getY()
         + this->getZ() + v.getZ();
    return ps;
}

Vector Vector::multiBy(double value) {
    return Vector(this->x * value, this->y * value, this->z * value);
}
