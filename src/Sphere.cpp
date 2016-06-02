//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"
#include <cmath>
#include <limits>
#include <iostream>


Sphere::Sphere()
        : Shape(), m_d2(), m_gamma() {
}

Sphere::Sphere(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color, float angle)
        : Shape(position, direction, scale, color, angle), m_d2(), m_gamma() {
}

Sphere::~Sphere() {
}

Sphere::operator std::string() const {
    return "sphere => " + Shape::operator std::string();
}

Sphere& Sphere::operator=(Sphere const& o) {
    m_position = o.m_position;
    m_direction = o.m_direction;
    m_scale = o.m_scale;
    return *this;
}

float Sphere::getRadius() {
    return m_scale.x();
}

bool Sphere::intersect(Ray const& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = m_d2;
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
    d1.setZ(d1.z() / m_scale.z());

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);

    float delta = (beta * beta - 4 * alpha * m_gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();
        return false;
    }
    float sqr = (float) sqrt(delta);
    float alpha2 = 2 * alpha;

    float t1 = (-beta + sqr) / alpha2;
    float t2 = (-beta - sqr) / alpha2;

    if (t1 < std::numeric_limits<float>::epsilon()) {
        return false;
    }
    else if (t2 < std::numeric_limits<float>::epsilon()) {
        dist = t1;
    }
    else {
        dist = t2;
    }
    return true;
}

bool Sphere::intersect_shadow(Ray const& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
    d1.setZ(d1.z() / m_scale.z());
    d2.setX(d2.x() / m_scale.x());
    d2.setY(d2.y() / m_scale.y());
    d2.setZ(d2.z() / m_scale.z());

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
    float gamma = d2.produitScalaire(d2) - 1;

    float delta = (beta * beta - 4 * alpha * gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();
        return false;
    }
    float sqr = (float) sqrt(delta);
    float alpha2 = 2 * alpha;

    float t1 = (-beta + sqr) / alpha2;
    float t2 = (-beta - sqr) / alpha2;

    if (t1 < std::numeric_limits<float>::epsilon()) {
        return false;
    }
    else if (t2 < std::numeric_limits<float>::epsilon()) {
        dist = t1;
    }
    else {
        dist = t2;
    }
    return true;
}

void Sphere::calculBoundingVolume() {
    Point center = m_position;
    float radius = getRadius();
    Sphere *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0), 0);
    m_boundingVolume = s;
}

void Sphere::precalcul() {
    m_d2 = (m_Camera_Pos - m_position).rotationVector(m_Mat_rotation);
    m_d2.setX(m_d2.x() / m_scale.x());
    m_d2.setY(m_d2.y() / m_scale.y());
    m_d2.setZ(m_d2.z() / m_scale.z());
    m_gamma = m_d2.produitScalaire(m_d2) - 1;
}

Vector Sphere::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
    d1.setZ(d1.z() / m_scale.z());
    Vector normal = m_d2 + d1 * dist;
    normal.setX(normal.x() / m_scale.x());
    normal.setY(normal.y() / m_scale.y());
    normal.setZ(normal.z() / m_scale.z());
    normal *= 1.f / normal.norm();
    normal = normal.rotationVector(m_inverse);
    if (ray.getDirection().produitScalaire(normal) > 0) {
        normal = -normal;
    }
    return normal;
}