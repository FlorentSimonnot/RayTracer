//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include "Point.hpp"
#include "Object.hpp"

class Ray;

// TODO
class Sphere : public Object {

private:
    Point center_;
    double radius_;

public:
    Sphere(void);

    Sphere(Point center, double radius);

    ~Sphere();

    Sphere operator=(const Sphere &p);

    bool intersect(Ray &ray,double &dist);

    Point &getCenter();

    double getRadius();
};


#endif //PROJECT_SPHERE_HPP
