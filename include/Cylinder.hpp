//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Objet.hpp"

// TODO
class Cylinder : public Objet {
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
