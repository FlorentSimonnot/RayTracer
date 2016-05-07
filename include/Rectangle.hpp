//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Shape.hpp"

// TODO
class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle(Vector const& position, Vector const& rotation, Vector const& scale);
    virtual ~Rectangle();

    operator std::string() const;

    bool intersect(Ray &ray, float &dist);
};

#endif //PROJECT_RECTANGLE_HPP
