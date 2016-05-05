//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP


#include "Objet.hpp"

// TODO
class Sphere : Objet {

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
