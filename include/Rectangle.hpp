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
    float width_;
    float height_;
    float depth_;

public:
    Rectangle(void);
    Rectangle(Point origin, float width, float height,float depth);

    ~Rectangle();

    bool intersect(Ray &ray, float &dist);

};

#endif //PROJECT_RECTANGLE_HPP
