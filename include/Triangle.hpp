//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_TRIANGLE_HPP
#define PROJECT_TRIANGLE_HPP

#include "Objet.hpp"

// TODO
class Triangle : public Objet {
private:
    Point point_1;
    Point point_2;
    Point point_3;

public:
    Triangle(void);

    Triangle(Point point_1, Point point_2, Point point_3);

    ~Triangle();

    Triangle operator=(const Triangle &p);

    bool intersect(Ray &ray, float &dist);

};


#endif //PROJECT_TRIANGLE_HPP
