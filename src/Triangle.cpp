//
// Created by Narex on 05/04/2016.
//

#include "../include/Triangle.hpp"

Triangle::Triangle(){}

Triangle::Triangle(Point point_1, Point point_2, Point point_3)
        : point_1(point_1),
          point_2(point_2),
          point_3(point_3) { }

Triangle::~Triangle() {

}

bool Triangle::intersect(Ray &ray, float &dist) {

    return true;
}