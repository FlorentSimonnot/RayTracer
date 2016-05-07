//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Point.hpp"
#include "Shape.hpp"

// TODO
class Rectangle : public Shape {
//private:
//    float m_width;
//    float m_height;
//    float m_depth;

public:
    Rectangle();
    Rectangle(Vector const& position, Vector const& rotation, Vector const& scale);

    virtual ~Rectangle();

    bool intersect(Ray const &ray, float &dist);

};

#endif //PROJECT_RECTANGLE_HPP
