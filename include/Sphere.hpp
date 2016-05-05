//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include "Object.hpp"

// TODO
class Sphere : public Object {

private:
    Point m_center;
    float m_radius;

public:
    Sphere();

    Sphere(Point center, float radius);

    ~Sphere();

    Sphere& operator=(const Sphere &p);

    bool intersect(Ray &ray,float &dist);

    Point &getCenter();

    float getRadius();
};


#endif //PROJECT_SPHERE_HPP
