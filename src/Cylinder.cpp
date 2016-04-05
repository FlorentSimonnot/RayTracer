//
// Created by Narex on 05/04/2016.
//

#include "../include/Cylinder.hpp"

Cylinder::Cylinder(){ }

Cylinder::Cylinder(float radius, float height)
        : radius_(radius),
          height_(height) { }

Cylinder::~Cylinder() {

}

bool Cylinder::intersect(Ray &ray, float &dist) {

    return true;
}