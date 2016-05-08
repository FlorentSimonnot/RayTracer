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
    Cylinder(Vector const& position, Vector const& rotation, Vector const& scale,Vector const& color);
    virtual ~Cylinder();

    operator std::string() const;

    bool intersect(const Ray& ray, float& dist);

    float getRadius();

    float getHeight();

    void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal);

    BoundingVolume getBoundingVolume();
};


#endif //PROJECT_CYLINDER_HPP
