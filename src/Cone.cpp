//
// Created by Irknar on 17/05/2016.
//

#include "Cone.hpp"
#include <cmath>
#include <limits>
#include <iostream>
#include <Sphere.hpp>


Cone::Cone()
        : Shape(),
          m_d2(),
          m_gamma(),
          m_tanAngle(),
          m_p1(),
          m_p2() {
}

Cone::Cone(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color)
        : Shape(position, direction, scale, color),
          m_d2(),
          m_gamma(),
          m_tanAngle(),
          m_p1(),
          m_p2() {

}

Cone::~Cone() {
}

float Cone::getRadius() const {
    return m_scale.x();
}

float Cone::getHeight() const {
    return m_scale.y();
}

Cone::operator std::string() const {
    return "cylinder => " + Shape::operator std::string();
}

bool Cone::intersect(const Ray& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = m_d2;
    float alpha = SQR(d1.x()) + SQR(d1.y()) - SQR(d1.z() * m_tanAngle);
    float beta = 2 * (d1.x() * d2.x() + d1.y() * d2.y() - SQR(m_tanAngle) * d1.z() * d2.z());

    float delta = (beta * beta - 4 * alpha * m_gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();
        return false;
    }
    float sqr = (float) sqrt(delta);
    float alpha2 = 2 * alpha;

    float t1 = (-beta + sqr) / alpha2;
    float t2 = (-beta - sqr) / alpha2;

    if (t2 == t1 && t1 < std::numeric_limits<float>::epsilon()) {
        dist = t1;
    } else if (t2 < t1) {
        if (t1 < std::numeric_limits<float>::epsilon()) {
            return false;
        }
        else if (t2 < std::numeric_limits<float>::epsilon()) {
            dist = t1;
            float distB = std::numeric_limits<float>::infinity();
            Triangle triangles[] = {m_p1, m_p2};
            for (Triangle t:triangles) {
                float distTmp;
                if (t.intersect(ray, distTmp)) {
                    distB = distTmp;
                }
            }
            if (distB > std::numeric_limits<float>::epsilon() && distB < dist) {
                dist = distB;
            } else {
                float interZ = d2.z() + dist * d1.z();
                if (interZ > 0 || interZ < -getHeight()) {
                    return false;
                }
            }
        }
        else {
            dist = t2;
            float interZ = d2.z() + dist * d1.z();
            if (interZ > 0) {
                return false;
            } else if (interZ < -getHeight()){
                Triangle triangles[] = {m_p1, m_p2};
                for (Triangle t:triangles) {
                    if (t.intersect(ray, dist)) {
                        if (dist > t2 && dist < t1) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    } else {
        float distB = std::numeric_limits<float>::infinity();
        Triangle triangles[] = {m_p1, m_p2};
        for (Triangle t:triangles) {
            float distTmp;
            if (t.intersect(ray, distTmp)) {
                distB = distTmp;
            }
        }
        if (t2 < std::numeric_limits<float>::epsilon()) {
            if (distB == std::numeric_limits<float>::infinity())
                return false;
            else {
                dist = distB;
                return true;
            }
        }
        else if (t1 < std::numeric_limits<float>::epsilon()) {
            dist = t2;
        }
        else {
            if (distB < t1) {
                dist = distB;
                return true;
            }
            dist = t1;
        }

        float interZ = d2.z() + dist * d1.z();
        if (interZ > 0 || interZ < -getHeight())
            return (false);

    }
    return true;
}

bool Cone::intersect_shadow(const Ray& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);
    float alpha = SQR(d1.x()) + SQR(d1.y()) - SQR(d1.z() * m_tanAngle);
    float beta = 2 * (d1.x() * d2.x() + d1.y() * d2.y() - SQR(m_tanAngle) * d1.z() * d2.z());
    float gamma = SQR(d2.x()) + SQR(d2.y()) - SQR(d2.z() * m_tanAngle);

    float delta = (beta * beta - 4 * alpha * gamma);

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();
        return false;
    }
    float sqr = (float) sqrt(delta);
    float alpha2 = 2 * alpha;

    float t1 = (-beta + sqr) / alpha2;
    float t2 = (-beta - sqr) / alpha2;

    if (t2 == t1 && t1 < std::numeric_limits<float>::epsilon()) {
        dist = t1;
    } else if (t2 < t1) {
        if (t1 < std::numeric_limits<float>::epsilon()) {
            return false;
        }
        else if (t2 < std::numeric_limits<float>::epsilon()) {
            dist = t1;
            float distB = std::numeric_limits<float>::infinity();
            Triangle triangles[] = {m_p1, m_p2};
            for (Triangle t:triangles) {
                float distTmp;
                if (t.intersect(ray, distTmp)) {
                    distB = distTmp;
                }
            }
            if (distB > std::numeric_limits<float>::epsilon() && distB < dist) {
                dist = distB;
            } else {
                float interZ = d2.z() + dist * d1.z();
                if (interZ > 0 || interZ < -getHeight()) {
                    return false;
                }
            }
        }
        else {
            dist = t2;
            float interZ = d2.z() + dist * d1.z();
            if (interZ > 0) {
                return false;
            } else if (interZ < -getHeight()){
                Triangle triangles[] = {m_p1, m_p2};
                for (Triangle t:triangles) {
                    if (t.intersect(ray, dist)) {
                        if (dist > t2 && dist < t1) {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    } else {
        float distB = std::numeric_limits<float>::infinity();
        Triangle triangles[] = {m_p1, m_p2};
        for (Triangle t:triangles) {
            float distTmp;
            if (t.intersect(ray, distTmp)) {
                distB = distTmp;
            }
        }
        if (t2 < std::numeric_limits<float>::epsilon()) {
            if (distB == std::numeric_limits<float>::infinity())
                return false;
            else {
                dist = distB;
                return true;
            }
        }
        else if (t1 < std::numeric_limits<float>::epsilon()) {
            dist = t2;
        }
        else {
            if (distB < t1) {
                dist = distB;
                return true;
            }
            dist = t1;
        }

        float interZ = d2.z() + dist * d1.z();
        if (interZ > 0 || interZ < -getHeight())
            return (false);

    }
    return true;
}


void Cone::calculBoundingVolume() {
}

void Cone::precalcul() {
    m_tanAngle = getRadius() / getHeight();
    m_d2 = (m_Camera_Pos - m_position).rotationVector(m_Mat_rotation);
    m_gamma = SQR(m_d2.x()) + SQR(m_d2.y()) - SQR(m_d2.z() * m_tanAngle);

    Vector v1 = Vector(1, 0, 0).rotationVector(m_inverse) * getRadius() * 2;
    Vector v2 = Vector(0, 1, 0).rotationVector(m_inverse) * getRadius() * 2;

    Point pos_down = m_position - getHeight() * m_direction;

    Point p0 = pos_down + v1 ;
    Point p1 = pos_down + v2;
    Point p2 = pos_down - v1;
    Point p3 = pos_down - v2;

    m_p1 = Triangle(p0, p1, p2, m_color);
    m_p2 = Triangle(p0, p3, p2, m_color);
}

Vector Cone::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector collide(m_d2 + d1 * dist);
    Vector normal = collide;
    normal.setZ(-normal.z() * SQR(m_tanAngle));
    normal = normal * (1.f / collide.norm());
    normal = normal.rotationVector(m_inverse);

    float interZ = m_d2.z() + dist * d1.z();

    float eps = 0.00001;

    if (interZ >= -getHeight() - eps && interZ <= -getHeight() + eps) {
        normal = m_p2.getNormalFromPoint(ray, dist);
    }

    if(ray.getDirection().produitScalaire(normal) > 0){
        normal = -normal;
    }
    return normal;
}