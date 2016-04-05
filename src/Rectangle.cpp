//
// Created by Narex on 05/04/2016.
//

#include "../include/Rectangle.hpp"

Rectangle::Rectangle(){ }

Rectangle::Rectangle(Point origin, float width, float height)
        : origin_(origin),
          width_(width),
          height_(height) { }

bool Rectangle::intersect(Ray &ray, float &dist) {

    return true;
}