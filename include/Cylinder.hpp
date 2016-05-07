//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Shape.hpp"
#include "Point.hpp"


// TODO
class Cylinder : public Shape {
private:
	Point m_center;
    float m_radius;
    float m_height;

public:
    Cylinder();
    Cylinder(Point const& center, float radius, float height);
    ~Cylinder();

    bool intersect(Ray &ray, float &dist);
    float getRadius();
    float getHeight();

	Sphere calculSphereEnglobante() override ;
};



#endif //PROJECT_CYLINDER_HPP
