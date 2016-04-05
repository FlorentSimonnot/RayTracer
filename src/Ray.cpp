//
// Created by Narex on 05/04/2016.
//

#include "../include/Ray.hpp"

// TODO

Ray::Ray(Point &origin, Vector &direction)
        : origin_(origin),
          direction_(direction) { }

Ray::~Ray() {

}

Point &Ray::getOrigin() {
    return origin_;
}

Vector &Ray::getDirection() {
    return direction_;
}

