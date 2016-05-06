//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"
#include <cmath>
#include <limits>

Sphere::Sphere()
        : m_center(), m_radius(1.f) {
}

Sphere::Sphere(Point center, float radius)
        : m_center(center), m_radius(radius) {
}

Sphere::~Sphere() {
}

Sphere &Sphere::operator=(const Sphere &o) {
    m_center = o.m_center;
    m_radius = o.m_radius;
    return *this;
}

Point &Sphere::getCenter() {
    return m_center;
}

float Sphere::getRadius() {
    return m_radius;
}

// TODO A tester
bool Sphere::intersect(Ray &ray, float &dist) {
    Vector d1 = ray.getDirection() - ray.getOrigin();
    Vector d2 = ray.getOrigin() - getCenter();
    Vector ray_dir = ray.getDirection();
    Vector center = getCenter();

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
    float gamma =
            ray_dir.produitScalaire(ray_dir) + center.produitScalaire(center) - 2 * ray_dir.produitScalaire(center) -
            m_radius * m_radius;

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
