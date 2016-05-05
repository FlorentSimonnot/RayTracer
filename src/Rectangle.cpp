//
// Created by Narex on 05/04/2016.
//

#include "Rectangle.hpp"
#include "Ray.hpp"

Rectangle::Rectangle()
:	Shape(), origin(), width(1.f), height(1.f), depth(1.f)
{
}

Rectangle::Rectangle(Point origin, float width, float height, float depth)
: 	Shape(), origin(origin), width(width), height(height), depth(depth)
{
}

Rectangle::~Rectangle() {
}

bool Rectangle::intersect(Ray &ray, float &dist) {

    return true;
}