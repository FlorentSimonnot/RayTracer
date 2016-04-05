//
// Created by Narex on 05/04/2016.
//

#include "../include/Sphere.hpp"

Sphere::Sphere(){}

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

// Ne fonctionne pas
bool Sphere::intersect(Ray &ray, float &dist) {
//    float A = 1.f;

//    Point point = ray.getOrigin() - getCenter(); // ray.origin() - center_

    float a = SQR(ray.getDirection().getX()) +
              SQR(ray.getDirection().getY()) +
              SQR(ray.getDirection().getZ());
    float b = ray.getDirection().getX() * ray.getOrigin().getX() +
              ray.getDirection().getY() * ray.getOrigin().getZ() +
              ray.getDirection().getZ() * ray.getOrigin().getZ();
    //norm2(point)
    float c = (SQR((ray.getOrigin() - getCenter()).getX()) +
               SQR((ray.getOrigin() - getCenter()).getY()) +
               SQR((ray.getOrigin() - getCenter()).getZ())) -
              radius_ * radius_;

    float delta = (b * b - a * c);

    if (delta <= 0.f)
        return false;

    float disc = sqrt(delta);
    if ((dist = -(b + disc)) < 0.)
        dist = -(b - disc);
    return true;
}
