//
// Created by narex on 03/04/16.
//

#include "geometry.hpp"

//////////////// Ray ///////////////////
Ray::Ray(Point3d &origin, Direction3d &direction)
        : origin_(origin),
          direction_(direction) { }

Ray::~Ray() {

}

Direction3d Ray::direction() {
    return direction_;
}

Point3d Ray::origin() {
    return origin_;
}


////////////// Sphere /////////////////////

Sphere::Sphere(Point3d &center, float &radius)
        : center_(center),
          radius_(radius) { }

Sphere::~Sphere() {

}


bool Sphere::intersect(const Ray &ray, float &dist) {
    float A = 1.f;
    float B = (ray.direction() * (ray.origin() - center_));
    float C = norm2(ray.origin() - center_) - radius_ * radius_;

    float delta = (B * B - A * C);

    if (delta < 0.f)
        return false;
    float disc = sqrt(delta);
    if (dist = -(B + disc) < 0.)
        dist = -(B - disc);
    return true;
}

/////////////// Triangle ////////////////////


Triangle::Triangle(Point3d point_1, Point3d point_2, Point3d point_3)
        : point_1_(point_1),
          point_2_(point_2),
          point_3_(point_3) { }

Triangle::~Triangle() {

}

bool Triangle::intersect(const Ray &ray, float &dist) {

}

/////////////// Cylindre ////////////////////

Cylinder::Cylinder(Point3d center, float radius, float height)
        : center_(center),
          radius_(radius),
          height_(height) { }

Cylinder::~Cylinder() {

}

bool Cylinder::intersect(const Ray &ray, float &dist) {

}


/////////////// Rectangle ////////////////////

Rectangle::Rectangle(Point3d origin, float width, float height)
        : origin_(origin),
          width_(width),
          height_(height) { }

bool Rectangle::intersect(const Ray &ray, float &dist) {

}