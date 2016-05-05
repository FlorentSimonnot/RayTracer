//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Object.hpp"

class Ray;

// TODO
class Cylinder : public Object {
private:
    double radius_;
    double height_;

public:
    Cylinder(void);
    Cylinder(double radius, double height);

    ~Cylinder();

    bool intersect(Ray &ray, double &dist);

    double getRadius();
    double getHeight();
};



#endif //PROJECT_CYLINDER_HPP
