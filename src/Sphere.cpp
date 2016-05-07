//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"
#include <cmath>
#include <limits>


Sphere::Sphere()
        : Shape() {
}

Sphere::Sphere(const Vector& position, const Vector& rotation, const Vector& scale)
        : Shape(position, rotation, scale) {
}

Sphere::~Sphere() {
}

float Sphere::getRadius() {
    return m_scale.x();
}

Sphere& Sphere::operator=(const Sphere& o) {
    m_position = o.m_position;
    m_rotation = o.m_rotation;
    m_scale = o.m_scale;
    return *this;
}


// TODO A tester
bool Sphere::intersect(const Ray& ray, float& dist) {
    Vector d1 = ray.getDirection() - ray.getOrigin();
    Vector d2 = ray.getOrigin() - m_position;
    Vector ray_dir = ray.getDirection();
    Vector center = m_position;

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
    float gamma =
            ray_dir.produitScalaire(ray_dir) + center.produitScalaire(center) - 2 * ray_dir.produitScalaire(center) -
            getRadius() * getRadius();

    float delta = (beta * beta - 4 * alpha * gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();;
        return false;

    }
    float t1 = (float) (-beta + sqrt(delta)) / alpha;
    float t2 = (float) (-beta - sqrt(delta)) / alpha;
    float t = 0;

    if ((t1 <= t2 && t1 > std::numeric_limits<float>::epsilon()) ||
        (t2 < t1 && t2 < std::numeric_limits<float>::epsilon())) {
        t = t1;
    } else if ((t2 < t1 && t2 > std::numeric_limits<float>::epsilon()) ||
               (t1 < t2 && t1 < std::numeric_limits<float>::epsilon())) {
        t = t2;
    }

    //TODO Peut etre A changer
    Point p = t * ray.getDirection() + ray.getOrigin();
    dist = p.distance(ray.getOrigin());
    return true;
}