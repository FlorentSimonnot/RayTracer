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
    Cylinder(Vector const& position, Vector const& rotation, Vector const& scale);
    ~Cylinder();

    bool intersect(Ray &ray, float &dist);
    float getRadius();
    float getHeight();
};



#endif //PROJECT_CYLINDER_HPP
