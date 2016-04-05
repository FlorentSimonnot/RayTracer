//
// Created by narex on 03/04/16.
//

#include "geometry.hpp"

#include <iostream>

//////////////// Ray ///////////////////
Ray::Ray(Point3d &origin, Direction3d &direction)
        : origin_(origin),
          direction_(direction) { }

Ray::~Ray() {

}

Point3d Ray::origin() {
    return origin_;
}

Direction3d Ray::direction() {
    return direction_;
}




////////////// Sphere /////////////////////

Sphere::Sphere(Point3d &center, float &radius)
        : center_(center),
          radius_(radius) { }

Sphere::~Sphere() {

}

// Ne fonctionne pas
bool Sphere::intersect(Ray &ray, float &dist) {
    float A = 1.f;
    Point3d vector; // ray.origin() - center_
    vector.x = ray.origin().x - center_.x;
    vector.y = ray.origin().y - center_.y;
    vector.z = ray.origin().z - center_.z;

    std::cout << 2;
    float B = ray.direction().x * vector.x +
              ray.direction().y * vector.y +
              ray.direction().z * vector.z; // (ray.direction() * (vector));

    //norm2(vector)
    float C = (vector.x * vector.x +
               vector.y * vector.y +
               vector.z * vector.z)
              - radius_ * radius_;

    float delta = (B * B - A * C);

    if (delta < 0.f)
        return false;
    float disc = sqrt(delta);
    if ((dist = -(B + disc)) < 0.)
        dist = -(B - disc);
    return true;
}

/////////////// Triangle ////////////////////


Triangle::Triangle(Point3d &point_1, Point3d &point_2, Point3d &point_3)
        : point_1_(point_1),
          point_2_(point_2),
          point_3_(point_3) { }

Triangle::~Triangle() {

}

bool Triangle::intersect(Ray &ray, float &dist) {

    return true;
}

/////////////// Cylindre ////////////////////

Cylinder::Cylinder(float radius, float height)
        : radius_(radius),
          height_(height) { }

Cylinder::~Cylinder() {

}

bool Cylinder::intersect(Ray &ray, float &dist) {

    return true;
}


/////////////// Rectangle ////////////////////

//Rectangle::Rectangle(Point3d &origin, float width, float height)
//        : origin_(origin),
//          width_(width),
//          height_(height) { }
//
//bool Rectangle::intersect(Ray &ray, float &dist) {
//
//    return true;
//}

int main(void) {

}