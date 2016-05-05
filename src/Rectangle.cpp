//
// Created by Narex on 05/04/2016.
//

#include "Rectangle.hpp"

Rectangle::Rectangle() { }

Rectangle::Rectangle(Point origin, float width, float height, float depth)
        : origin_(origin),
          width_(width),
          height_(height),
          depth_(depth){}

bool Rectangle::intersect(Ray &ray, float &dist) {

    return true;
}