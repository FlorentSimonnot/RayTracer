//
// Created by narex on 03/04/16.
//

#include "geometry.hpp"

#include <iostream>

//////////////// ParentPointVector ///////////////////
ParentPointVector::ParentPointVector(float x, float y, float z)
        : x(x),
          y(y),
          z(z) { }

ParentPointVector::~ParentPointVector() { }

ParentPointVector ParentPointVector::operator+(const ParentPointVector &p) {
    return ParentPointVector(this->x + p.x, this->y + p.y, this->z + p.z);
}

ParentPointVector ParentPointVector::operator-(const ParentPointVector &p) {
    return ParentPointVector(this->x - p.x, this->y - p.y, this->z - p.z);
}

bool ParentPointVector::operator==(const ParentPointVector &p) {
    return this->x == p.x && this->y == p.y && this->z == p.z;
}

bool ParentPointVector::operator!=(const ParentPointVector &p) {
    return this->x != p.x || this->y != p.y || this->z != p.z;
}

ParentPointVector ParentPointVector::operator=(const ParentPointVector &p) {
    this->x = p.x;
    this->y = p.z;
    this->z = p.z;
    return (*this);
}

float ParentPointVector::getX() {
    return x;
}

float ParentPointVector::getY() {
    return y;
}

float ParentPointVector::getZ() {
    return y;
}
//////////////// Point ///////////////////

Point::Point(float x, float y, float z) : ParentPointVector(x, y, z) { }

Point::~Point() { }

float Point::distance(const Point &p) {
    return sqrt(SQR(p.x - this->x) + SQR(p.y - this->y) + SQR(p.z - this->z));
}

//Point Point::operator+(const Point &p) {
//    return Point(this->x + p.x,this->y + p.y, this->z + p.z);
//}

//////////////// Vector ///////////////////

Vector::Vector(float x, float y, float z) : ParentPointVector(x, y, z) { }

Vector::~Vector() { }

Vector Vector::nullVector() {
    return Vector(0, 0, 0);
}

Vector Vector::operator*(const Vector &v) {
    float x = this->y * v.z - this->z * v.y;
    float y = this->z * v.x - this->x * v.z;
    float z = this->x * v.y - this->y * v.x;
    return Vector(x, y, z);
}

Vector Vector::multiBy(float value) {
    return Vector(this->x * value, this->y * value, this->z * value);
}

//////////////////////////////////////////// Work in progress ////////////////////////////////////////
//////////////////////////////////////////// Does not work   ////////////////////////////////////////

//////////////// Ray ///////////////////
Ray::Ray(Point &origin, Vector &direction)
        : origin_(origin),
          direction_(direction) { }

Ray::~Ray() {

}

Point &Ray::getOrigin() {
    return origin_;
}


Vector &Ray::getDirection() {
    return direction_;
}

////////////// Sphere /////////////////////

Sphere::Sphere(Point center, float radius)
        : center_(center),
          radius_(radius) { }

Sphere::~Sphere() {

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

    Point a(1., 2., 3.);
    std::cout << "test1\n";
    Point b(1., 2., 3.);
    std::cout << "test\n";


    if (a == b) {
        std::cout << "test3\n";
    }
    else {
        std::cout << "test4\n";
    }
    Point c = a+b;
    // Pas possible de faire Point c = a+b; -> error: conversion from ‘ParentPointVector’ to non-scalar type ‘Point’ requested


    std::cout << (a + b).getX() << "\n";
    std::cout << (a + b).getY() << "\n";
    std::cout << (a + b).getZ() << "\n";
//    std::cout << c.getX() << "\n";
    //std::cout << a+b;

    return 0;
}