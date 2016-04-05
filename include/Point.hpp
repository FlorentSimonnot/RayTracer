//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_POINT_HPP
#define PROJECT_POINT_HPP

#include "ParentPointVector.hpp"
#include <cmath>

class Point : public ParentPointVector {
private:
    Point operator=(const ParentPointVector &p);

public:
    Point(void);

    Point(float x, float y, float z);

    ~Point();

    float distance(const Point &p);

    Point operator=(const Point &p);

    Point operator+(const Point &p);

    Point operator-(const Point &p);

//    Point addVector(const Vector &v);

//    Point substractVector(const Vector &v);

};


#endif //PROJECT_POINT_HPP
