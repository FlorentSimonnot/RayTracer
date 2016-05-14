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

Sphere::Sphere(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color)
        : Shape(position, direction, scale, color), m_d2(), m_gamma() {
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
    Vector d1 = ray.getDirection();
    // TODO mettre un champs qui calcul ça direct -> optimisation temps calcul
    // m_d2 = ray.getOrigin() - m_position
    Vector d2 = m_d2;//ray.getOrigin() - m_position;

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
//    float gamma = d2.produitScalaire(d2) - getRadius() * getRadius();

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

//void Sphere::computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) {
//
////    Vector v(ray.getOrigin() + dist*ray.getDirection());
////    normal = v - m_position;
////    normal *= 1/(sqrt(normal.norm()));
//    color = this->m_color;
//}

void Sphere::calculBoundingVolume() {
    Point center = m_position;
    float radius = getRadius();
    Sphere *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0));
    m_boundingVolume = s;
}

void Sphere::precalcul() {
    m_d2 = m_Camera_Pos - m_position;
    m_gamma = m_d2.produitScalaire(m_d2) - getRadius() * getRadius();
}

Vector Sphere::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector collide(ray.getOrigin() + dist * ray.getDirection());
    Vector normal = collide - m_position;
    normal *= 1.f / normal.norm();
    return normal;
}