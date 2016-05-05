//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include "Point.hpp"
#include "Ray.hpp"
#include "Object.hpp"

// TODO
class Sphere : public Object {

private:
    Point center_;
    float radius_;

public:
    Sphere(void);

    Sphere(Point center, float radius);

    ~Sphere();

    Sphere operator=(const Sphere &p);

    bool intersect(Ray &ray);

    Point &getCenter();

    float getRadius();
};


#endif //PROJECT_SPHERE_HPP
