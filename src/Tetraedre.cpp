//
// Created by Narex on 05/04/2016.
//

#include "Tetraedre.hpp"

Tetraedre::Tetraedre()
:	point_1(), point_2(), point_3(), point_4(), color()
{
}

Tetraedre::Tetraedre(Point point_1, Point point_2, Point point_3, Point point_4)
        : point_1(point_1),
          point_2(point_2),
          point_3(point_3),
          point_4(point_4), color() { }

Tetraedre::~Tetraedre() {

}

bool Tetraedre::intersect(Ray &ray, float &dist) {

    return true;
}