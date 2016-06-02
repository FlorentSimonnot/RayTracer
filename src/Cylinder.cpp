//
// Created by Narex on 05/04/2016.
//

#include "Cylinder.hpp"
#include <cmath>
#include <limits>
#include <iostream>
#include <Sphere.hpp>


Cylinder::Cylinder()
        : Shape(),
          m_d2(),
          m_gamma(),
          m_f1p1(),
          m_f1p2(),
          m_f2p1(),
          m_f2p2(),
          m_d2Z() {
}

Cylinder::Cylinder(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color, float angle)
        : Shape(position, direction, scale, color, angle),
          m_d2(),
          m_gamma(),
          m_f1p1(),
          m_f1p2(),
          m_f2p1(),
          m_f2p2(),
          m_d2Z() {

}

Cylinder::~Cylinder() {
}

float Cylinder::getRadius() const {
    return m_scale.x();
}

float Cylinder::getHeight() const {
    return m_scale.z();
}

Cylinder::operator std::string() const {
    return "cylinder => " + Shape::operator std::string();
}

bool Cylinder::intersect(const Ray& ray, float& dist) {

    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
//    m_d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);
    float d1Z = d1.z();
    d1.setZ(0);
//    d2.setZ(0);
    float alpha = d1.produitScalaire(d1);
    float beta = 2 * d1.produitScalaire(m_d2);
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
        float distB = std::numeric_limits<float>::infinity();
        Triangle triangles[] = {m_f1p1, m_f1p2, m_f2p1, m_f2p2};
        for (Triangle t:triangles) {
            float distTmp;
            if (t.intersect(ray, distTmp)) {
                if (distTmp < distB) {
                    distB = distTmp;
                }
            }
        }
        if (distB > std::numeric_limits<float>::epsilon() && distB < dist) {
            dist = distB;
        } else {
            float interZ = m_d2Z + dist * d1Z;
            if (interZ < 0 || interZ > getHeight()) {
                return false;
            }
        }
    }
    else {
        dist = t2;
        float interZ = m_d2Z + dist * d1Z;
        if (interZ > getHeight() || interZ < 0) {
            float distB = std::numeric_limits<float>::infinity();
            Triangle triangles[] = {m_f1p1, m_f1p2, m_f2p1, m_f2p2};
            for (Triangle t:triangles) {
                float distTmp;
                if (t.intersect(ray, distTmp)) {
                    if (distTmp < distB) {
                        distB = distTmp;
                    }
                }
            }
            if (distB < t1 && distB > t2) {
                dist = distB;
                return true;
            }
            return false;
        }
    }
    return true;
}

void Cylinder::calculBoundingVolume() {
    Vector center = m_position + (1.f / 2.f) * (m_direction * getHeight());
    float radius = sqrtf(SQR((1.f / 2.f) * (getHeight())) + SQR(getRadius()));
    Sphere *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0), 0);
    m_boundingVolume = s;
}

void Cylinder::precalcul() {
    m_d2 = (m_Camera_Pos - m_position).rotationVector(m_Mat_rotation);
    m_d2Z = m_d2.z();
    m_d2.setZ(0);
    m_d2.setX(m_d2.x() / m_scale.x());
    m_d2.setY(m_d2.y() / m_scale.y());

    m_gamma = m_d2.produitScalaire(m_d2) - 1;

//    Matrice tmp = m_Mat_rotation.inverseMatrix();
    Vector v1 = Vector(1, 0, 0).rotationVector(m_inverse) * m_scale.x() * 2;
    Vector v2 = Vector(0, 1, 0).rotationVector(m_inverse) * m_scale.y() * 2;

    Point pos_up = m_position + getHeight() * m_direction;

    Point p0 = m_position + v1;
    Point p1 = m_position + v2;
    Point p2 = m_position - v1;
    Point p3 = m_position - v2;

    Point p4 = pos_up + v1;
    Point p5 = pos_up + v2;
    Point p6 = pos_up - v1;
    Point p7 = pos_up - v2;

    m_f1p1 = Triangle(p0, p1, p2, m_color);
    m_f1p2 = Triangle(p0, p3, p2, m_color);
    m_f2p1 = Triangle(p4, p5, p6, m_color);
    m_f2p2 = Triangle(p4, p6, p7, m_color);
}

bool Cylinder::intersect_shadow(const Ray& ray, float& dist) {

    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);
    float d1Z = d1.z();
    float d2Z = d2.z();
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
    d2.setX(d2.x() / m_scale.x());
    d2.setY(d2.y() / m_scale.y());
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
        float distB = std::numeric_limits<float>::infinity();
        Triangle triangles[] = {m_f1p1, m_f1p2, m_f2p1, m_f2p2};
        for (Triangle t:triangles) {
            float distTmp;
            if (t.intersect(ray, distTmp)) {
                if (distTmp < distB) {
                    distB = distTmp;
                }
            }
        }
        if (distB > std::numeric_limits<float>::epsilon() && distB < dist) {
            dist = distB;
        } else {
            float interZ = d2Z + dist * d1Z;
            if (interZ < 0 || interZ > getHeight()) {
                return false;
            }
        }
    }
    else {
        dist = t2;
        float interZ = d2Z + dist * d1Z;
        if (interZ > getHeight() || interZ < 0) {
            float distB = std::numeric_limits<float>::infinity();
            Triangle triangles[] = {m_f1p1, m_f1p2, m_f2p1, m_f2p2};
            for (Triangle t:triangles) {
                float distTmp;
                if (t.intersect(ray, distTmp)) {
                    if (distTmp < distB) {
                        distB = distTmp;
                    }
                }
            }
            if (distB < t1 && distB > t2) {
                dist = distB;
                return true;
            }
            return false;
        }
    }
    return true;
}

Vector Cylinder::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    float d1Z = d1.z();
    d1.setZ(0);
    d1.setX(d1.x() / m_scale.x());
    d1.setY(d1.y() / m_scale.y());
    Vector normal = m_d2 + d1 * dist;
    normal.setX(normal.x() / m_scale.x());
    normal.setY(normal.y() / m_scale.y());
    normal *= 1.f / normal.norm();
//    Matrice inv = m_Mat_rotation.inverseMatrix();
    normal = normal.rotationVector(m_inverse);

    float interZ = m_d2Z + dist * d1Z;

    float eps = 0.00001;
    if (interZ <= eps && interZ >= -eps) {
        normal = m_f2p2.getNormalFromPoint(ray, dist);
    }
    if (interZ >= getHeight() - eps && interZ <= getHeight() + eps) {
        normal = m_f1p2.getNormalFromPoint(ray, dist);
    }

    if(ray.getDirection().produitScalaire(normal) > 0){
        normal = -normal;
    }
    return normal;
}