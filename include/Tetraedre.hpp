//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_TRIANGLE_HPP
#define PROJECT_TRIANGLE_HPP

#include "Object.hpp"

// TODO
class Tetraedre : public Object {
private:
    Point point_1;
    Point point_2;
    Point point_3;
    Point point_4;

    int color;
public:
    Tetraedre(void);

    Tetraedre(Point point_1, Point point_2, Point point_3,Point point_4);

    ~Tetraedre();

    Tetraedre operator=(const Tetraedre &p);

    bool intersect(Ray &ray, double &dist);

};


#endif //PROJECT_TRIANGLE_HPP
