//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"

Sphere::Sphere() { }

Sphere::Sphere(Point center, float radius)
        : center(center),
          radius(radius) { }

Sphere::~Sphere() { }

Sphere Sphere::operator=(const Sphere &p) {
    this->center = p.center;
    this->radius = p.radius;
    return (*this);
}

Point &Sphere::getCenter() {
    return center;
}

float Sphere::getRadius() {
    return radius;
}

// TODO A tester
bool Sphere::intersect(Ray &ray, float &dist) {

    float alpha = SQR(ray.getDirection().getX() - ray.getOrigin().getX())
                  + SQR(ray.getDirection().getY() - ray.getOrigin().getY())
                  + SQR(ray.getDirection().getZ() - ray.getOrigin().getZ());
    float beta = 2 * (
            (ray.getDirection().getX() - ray.getOrigin().getX()) * (ray.getOrigin().getX() - getCenter().getX()) +
            (ray.getDirection().getY() - ray.getOrigin().getY()) * (ray.getOrigin().getY() - getCenter().getY()) +
            (ray.getDirection().getZ() - ray.getOrigin().getZ()) * (ray.getOrigin().getZ() - getCenter().getZ()));
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

    if(delta < 0){
        dist = 0;
;
    }
    else{
        float t1 = (-beta + sqrt(delta)) / alpha;
        float t2 = (-beta - sqrt(delta)) / alpha;
        float t;
        if ((t1 <= t2 && t1 > getEpsilon()) || (t2 < t1 && t2 < getEpsilon())){
            t = t1;
        }
        else if ((t2 < t1 && t2 > getEpsilon()) || (t1 < t2 && t1 < getEpsilon())) {
            t = t2;
        }


        //TODO Peut etre A changer
        float x = t * ray.getDirection().getX() + ray.getOrigin().getX();
        float y = t * ray.getDirection().getY() + ray.getOrigin().getY();
        float z = t * ray.getDirection().getZ() + ray.getOrigin().getZ();
        Point p(x,y,z);
        dist = p.distance(ray.getOrigin());

    }

    return delta >= 0;

}
