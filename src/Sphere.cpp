//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"
#include <cmath>
#include <limits>


Sphere::Sphere()
        : Shape() {
}

Sphere::Sphere(Vector const& position, Vector const& rotation, Vector const& scale)
        : Shape(position, rotation, scale) {
}

Sphere::~Sphere() {
}

Sphere::operator std::string() const {
    return "sphere => " + Shape::operator std::string();
}

Sphere& Sphere::operator=(Sphere const& o) {
    m_position = o.m_position;
    m_rotation = o.m_rotation;
    m_scale = o.m_scale;
    return *this;
}

float Sphere::getRadius() {
    return m_scale.x();
}


// TODO A tester
bool Sphere::intersect(Ray const& ray, float& dist) {
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