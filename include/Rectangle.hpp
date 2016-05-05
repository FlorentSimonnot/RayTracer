//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Objet.hpp"

// TODO
class Rectangle : public Objet {
private:
    Point origin_;
    double width_;
    double height_;
    double depth_;

public:
    Rectangle(void);
    Rectangle(Point origin, double width, double height,double depth);

    ~Rectangle();

    bool intersect(Ray &ray, double &dist);

};

#endif //PROJECT_RECTANGLE_HPP
