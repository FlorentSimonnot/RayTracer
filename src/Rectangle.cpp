//
// Created by Narex on 05/04/2016.
//

#include "Rectangle.hpp"

Rectangle::Rectangle() :
        width(0),
        height(0),
        depth(0) { }

Rectangle::~Rectangle() {

}

Rectangle::Rectangle(Point origin, float width, float height, float depth)
        : origin(origin),
          width(width),
          height(height),
          depth(depth) { }

bool Rectangle::intersect(Ray &ray, float &dist) {

    return true;
}