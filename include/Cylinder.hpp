//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Shape.hpp"
#include "Point.hpp"


// TODO
class Cylinder : public Shape {
public:
    Cylinder();

    Cylinder(const Vector& position, const Vector& rotation, const Vector& scale);

    ~Cylinder();

    bool intersect(const Ray& ray, float& dist);

    float getRadius();

    float getHeight();
};


#endif //PROJECT_CYLINDER_HPP
