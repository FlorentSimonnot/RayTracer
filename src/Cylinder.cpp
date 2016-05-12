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

bool Cylinder::intersect(const Ray& ray, float& dist) {

    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    // TODO mettre un champs qui calcul ça direct -> optimisation temps calcul
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

// TODO Changer les valeurs
// Ne pas utiliser actuellement
// Evite juste que le compilateur rale
BoundingVolume Cylinder::getBoundingVolume() {
    BoundingVolume boundingVolume(m_position, m_scale.x());
    return boundingVolume;
}