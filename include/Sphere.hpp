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
    Point m_center;
    float m_radius;

public:
    Sphere(void);

    Sphere(Point center, float radius);

    ~Sphere();

    Sphere& operator=(const Sphere &p);

    bool intersect(Ray &ray,float &dist);

    Point &getCenter();

    float getRadius();
};


#endif //PROJECT_SPHERE_HPP
