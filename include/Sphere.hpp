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

    bool intersect(const Ray& ray, float& dist);

    float getRadius();

    Sphere& operator=(Sphere const& o);

    operator std::string() const;
};


#endif //PROJECT_SPHERE_HPP
