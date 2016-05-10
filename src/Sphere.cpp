//
// Created by Narex on 05/04/2016.
//

#include "Sphere.hpp"
#include <cmath>
#include <limits>


Sphere::Sphere()
        : Shape() {
}

Sphere::Sphere(Vector const& position, Vector const& rotation, Vector const& scale, Vector const& color)
        : Shape(position, rotation, scale, color) {
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
    Vector d1 = ray.getDirection(); //- ray.getOrigin();
    Vector d2 = m_position - ray.getOrigin();
//    Vector ray_dir = ray.getDirection();
//    Vector center = m_position;

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
    float gamma = d2.produitScalaire(d2) - getRadius() * getRadius();
    //ray_dir.produitScalaire(ray_dir) + center.produitScalaire(center) - 2 * ray_dir.produitScalaire(center) -


    float delta = (beta * beta - 4 * alpha * gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();;
        return false;

    }
    float t1 = (float) (-beta + sqrt(delta)) / alpha;
    float t2 = (float) (-beta - sqrt(delta)) / alpha;
    float t = 0;

    if (t1 < std::numeric_limits<float>::epsilon()) {
        t = t2;
    }
    else if (t2 < std::numeric_limits<float>::epsilon()) {
        t = t1;
    }
    else if (t1 < std::numeric_limits<float>::epsilon() && t2 < std::numeric_limits<float>::epsilon()) {
        return false;
    }
    else {
        t = (float) fmin(t1, t2);
    }
    dist = t;
//
//    if ((t1 <= t2 && t1 > std::numeric_limits<float>::epsilon()) ||
//        (t2 < t1 && t2 < std::numeric_limits<float>::epsilon())) {
//        t = t1;
//    } else if ((t2 < t1 && t2 > std::numeric_limits<float>::epsilon()) ||
//               (t1 < t2 && t1 < std::numeric_limits<float>::epsilon())) {
//        t = t2;
//    }
//    else if(t1 < std::numeric_limits<float>::epsilon() && t2 < std::numeric_limits<float>::epsilon() ){
//        return false;
//    }

    //TODO Peut etre A changer
//    Point p = t * ray.getDirection() + ray.getOrigin();
//    dist = p.distance(ray.getOrigin());
    return true;
}

//void Sphere::computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) {
//
////    Vector v(ray.getOrigin() + dist*ray.getDirection());
////    normal = v - m_position;
////    normal *= 1/(sqrt(normal.norm()));
//    color = this->m_color;
//}

BoundingVolume Sphere::getBoundingVolume() {
    BoundingVolume boundingVolume(m_position, m_scale.x());
    return boundingVolume;
}