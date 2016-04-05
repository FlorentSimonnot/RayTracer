//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Objet.hpp"

// TODO
class Cylinder : public Objet {
private:
    float radius_;
    float height_;

public:
    Cylinder(void);
    Cylinder(float radius, float height);

    ~Cylinder();





    bool intersect(Ray &ray, float &dist);

};



#endif //PROJECT_CYLINDER_HPP
