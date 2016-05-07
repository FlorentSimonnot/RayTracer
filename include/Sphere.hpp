//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include <Shape.hpp>

// TODO
class Sphere : public Shape {

public:
    Sphere();
    Sphere(Vector const& position, Vector const& rotation, Vector const& scale);
    virtual ~Sphere();

    bool intersect(Ray const &ray,float &dist);

    Vector &getCenter();

    float getRadius();

    Sphere& operator=(Sphere const& o);

};


#endif //PROJECT_SPHERE_HPP
