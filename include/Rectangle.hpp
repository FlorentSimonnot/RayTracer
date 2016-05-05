//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Object.hpp"

class Ray;

// TODO
class Rectangle : public Object {
private:
    Point origin;
    float width;
    float height;
    float depth;

public:
    Rectangle();
    Rectangle(Point origin, float width, float height,float depth);

    ~Rectangle();

    bool intersect(Ray &ray, float &dist);

};

#endif //PROJECT_RECTANGLE_HPP
