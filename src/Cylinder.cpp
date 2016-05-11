//
// Created by Narex on 05/04/2016.
//

#include "Cylinder.hpp"
#include <cmath>
#include <limits>


Cylinder::Cylinder()
        : Shape() {
}


Cylinder::Cylinder(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color)
        : Shape(position, direction, scale, color) {

}

Cylinder::~Cylinder() {
}

// TODO A changer
float Cylinder::getRadius() {
    return m_scale.x();
}

float Cylinder::getHeight() {
    return m_scale.z();
}

Cylinder::operator std::string() const {
    return "cylinder => " + Shape::operator std::string();
}

// Cylindre avec sa hauteur sur l'axe des X
// TODO A finir
bool Cylinder::intersect(const Ray& ray, float& dist) {

    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);

    d1.setZ(0);
    d2.setZ(0);

    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(d2);
    float gamma = d2.produitScalaire(d2) - getRadius() * getRadius();

    float delta = (beta * beta - 4 * alpha * gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();
        return false;
    }
    float t1 = (float) (-beta + sqrt(delta)) / (2 * alpha);
    float t2 = (float) (-beta - sqrt(delta)) / (2 * alpha);
    float t = 0;

    if (t1 < std::numeric_limits<float>::epsilon() && t2 < std::numeric_limits<float>::epsilon()) {
        return false;
    }
    else if (t1 < std::numeric_limits<float>::epsilon()) {
        t = t2;
    }
    else if (t2 < std::numeric_limits<float>::epsilon()) {
        t = t1;
    }
    else {
        t = (float) fmin(t1, t2);
    }
    dist = t;
    return true;

}

// TODO Changer les valeurs
// Ne pas utiliser actuellement
// Evite juste que le compilateur rale
BoundingVolume Cylinder::getBoundingVolume() {
    BoundingVolume boundingVolume(m_position, m_scale.x());
    return boundingVolume;
}