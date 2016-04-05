//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RAY_HPP
#define PROJECT_RAY_HPP

#include "Point.hpp"
#include "Vector.hpp"

// TODO
class Ray {
private:
    Point origin_;
    Vector direction_;

public:
    Ray(void);

    Ray(Point &origin, Vector &direction);

    ~Ray();

    Ray operator=(const Ray &p);
    Ray operator+(const Ray &p);

    Point &getOrigin();

    Vector &getDirection();
};


#endif //PROJECT_RAY_HPP
