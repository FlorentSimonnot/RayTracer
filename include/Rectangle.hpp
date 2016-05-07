//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Point.hpp"
#include "Shape.hpp"

// TODO
class Rectangle : public Shape {

public:
    Rectangle();

    Rectangle(const Vector& position, const Vector& rotation, const Vector& scale);

    virtual ~Rectangle();

    bool intersect(const Ray& ray, float& dist);

};

#endif //PROJECT_RECTANGLE_HPP
