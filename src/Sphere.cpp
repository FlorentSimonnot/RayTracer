//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"

Sphere::Sphere() { }

Sphere::Sphere(Point center, float radius)
        : center_(center),
          radius_(radius) { }

Sphere::~Sphere() { }

Sphere Sphere::operator=(const Sphere &p) {
    this->center_ = p.center_;
    this->radius_ = p.radius_;
    return (*this);
}

Point &Sphere::getCenter() {
    return center_;
}

float Sphere::getRadius(){
    return radius_;
}

// Ne fonctionne pas
bool Sphere::intersect(Ray &ray) {

    float alpha = SQR(ray.getDirection().getX() - ray.getOrigin().getX())
                  + SQR(ray.getDirection().getY() - ray.getOrigin().getY())
                  + SQR(ray.getDirection().getZ() - ray.getOrigin().getZ());
    float beta = 2 * (
            (ray.getDirection().getX() - ray.getOrigin().getX()) * (ray.getOrigin().getX() - getCenter().getX()) +
            (ray.getDirection().getY() - ray.getOrigin().getY()) * (ray.getOrigin().getY() - getCenter().getY()) +
            (ray.getDirection().getZ() - ray.getOrigin().getZ()) * (ray.getOrigin().getZ() - getCenter().getZ()));
    //norm2(point)
    float gamma = SQR(ray.getDirection().getX()) +
                  SQR(ray.getDirection().getY()) +
                  SQR(ray.getDirection().getZ()) +
                  SQR(getCenter().getX()) +
                  SQR(getCenter().getY()) +
                  SQR(getCenter().getZ()) -
                  2 * (ray.getDirection().getX() * getCenter().getX() +
                       ray.getDirection().getY() * getCenter().getY() +
                       ray.getDirection().getZ() * getCenter().getZ()) -
                  SQR(getRadius());

    float delta = (beta * beta - 4 * alpha * gamma);

    return delta >= 0;

//    if (delta <= 0.f)
//        return false;
//
////    float disc = sqrt(delta);
////    if ((dist = -(b + disc)) < 0.)
////        dist = -(b - disc);
//    return true;
}
