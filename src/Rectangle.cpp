//
// Created by Narex on 05/04/2016.
//

#include "Rectangle.hpp"

Rectangle::Rectangle() { }

Rectangle::Rectangle(Point origin, double width, double height, double depth)
        : origin_(origin),
          width_(width),
          height_(height),
          depth_(depth){}

bool Rectangle::intersect(Ray &ray, double &dist) {

    return true;
}