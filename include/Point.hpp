//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_POINT_HPP
#define PROJECT_POINT_HPP

#include "Vector.hpp"

class Point : public Vector {
public:
    Point();
    Point(float x, float y, float z);
    Point(const Vector & o);
    virtual ~Point();

    float distance(const Point & o) const;
};

#endif //PROJECT_POINT_HPP
