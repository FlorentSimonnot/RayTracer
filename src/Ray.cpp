//
// Created by Narex on 05/04/2016.
//

#include "Ray.hpp"

// TODO

Ray::Ray(Point &origin, Vector &direction)
        : origin_(origin),
          direction_(direction) { }

Ray::~Ray() {

}

void Ray::setDirection(const Vector &v) {
    this->direction_=v;
}

void Ray::setOrigin(const Point &p) {
    this->origin_=p;
}

Point &Ray::getOrigin() {
    return origin_;
}

Vector &Ray::getDirection() {
    return direction_;
}

