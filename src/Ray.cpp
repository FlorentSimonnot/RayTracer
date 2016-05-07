//
// Created by Narex on 05/04/2016.
//

#include "Ray.hpp"

// TODO

Ray::Ray(Point &origin, Vector &direction)
        : origin(origin),
          direction(direction) { }

Ray::~Ray() {

}

void Ray::setDirection(const Vector &v) {
    this->direction = v;
}

void Ray::setOrigin(const Point &p) {
    this->origin = p;
}

Point &Ray::getOrigin() const {
    return origin;
}

Vector &Ray::getDirection() const {
    return direction;
}

