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
          m_tanX(),
          m_tanY(),
          m_p1(),
          m_p2() {
    Point p1, p2, p3;
    Vector v;

    v = Vector(1, 0, 0).rotationVector(m_inverse) * fmaxf(m_scale.x(), m_scale.y());
    p1 = m_position;
    p2 = m_position + v;
    p3 = m_position - v;

    float A = p1.distance(p2);
    float B = p2.distance(p3);
    float C = p3.distance(p1);
    float radius;
    Point center;

    Point a = p3;
    Point b = p1;
    Point c = p2;

    if (B < C) {
        float tmp = B;
        B = C;
        C = tmp;

        Point ptmp = b;
        b = c;
        c = ptmp;
    }
    if (A < B) {
        float tmp = A;
        A = B;
        B = tmp;

        Point ptmp = a;
        a = b;
        b = ptmp;
    }

    // If obtuse, just use longest diameter, otherwise circumscribe
    if ((B * B) + (C * C) <= (A * A)) {
        radius = A / 2.f;
        center = (b + c) * (1.f / 2.f);
    } else {
        // http://en.wikipedia.org/wiki/Circumscribed_circle
        float cos_a = (B * B + C * C - A * A) / (B * C * 2);
        radius = A / (sqrtf(1 - cos_a * cos_a) * 2.f);
        Vector alpha = a - c,
                beta = b - c;
        center = (beta * alpha.produitScalaire(alpha) - alpha * beta.produitScalaire(beta))
                         .crossProduct(alpha.crossProduct(beta))
                 * (1.f / (alpha.crossProduct(beta).produitScalaire(alpha.crossProduct(beta)) * 2.f))
                 + c;
    }
    m_boundingVolume = BoundingVolume(center, radius);
}

Cone::Cone(Vector const& position, Vector const& direction, Vector const& m_scale, Vector const& color, float angle)
        : Shape(position, direction, m_scale, color, angle),
          m_d2(),
          m_gamma(),
          m_tanX(),
          m_tanY(),
          m_p1(),
          m_p2() {
    Point p1, p2, p3;
    Vector v;

    v = Vector(1, 0, 0).rotationVector(m_inverse) * fmaxf(m_scale.x(), m_scale.y());
    p1 = m_position;
    p2 = m_position + v;
    p3 = m_position - v;

    float A = p1.distance(p2);
    float B = p2.distance(p3);
    float C = p3.distance(p1);
    float radius;
    Point center;

    Point a = p3;
    Point b = p1;
    Point c = p2;

    if (B < C) {
        float tmp = B;
        B = C;
        C = tmp;

        Point ptmp = b;
        b = c;
        c = ptmp;
    }
    if (A < B) {
        float tmp = A;
        A = B;
        B = tmp;

        Point ptmp = a;
        a = b;
        b = ptmp;
    }

    // If obtuse, just use longest diameter, otherwise circumscribe
    if ((B * B) + (C * C) <= (A * A)) {
        radius = A / 2.f;
        center = (b + c) * (1.f / 2.f);
    } else {
        // http://en.wikipedia.org/wiki/Circumscribed_circle
        float cos_a = (B * B + C * C - A * A) / (B * C * 2);
        radius = A / (sqrtf(1 - cos_a * cos_a) * 2.f);
        Vector alpha = a - c,
                beta = b - c;
        center = (beta * alpha.produitScalaire(alpha) - alpha * beta.produitScalaire(beta))
                         .crossProduct(alpha.crossProduct(beta))
                 * (1.f / (alpha.crossProduct(beta).produitScalaire(alpha.crossProduct(beta)) * 2.f))
                 + c;
    }
    m_boundingVolume = BoundingVolume(center, radius);

}

Cone::~Cone() {
}

float Cone::getRadius() const {
    return m_scale.x();
}

float Cone::getHeight() const {
    return m_scale.z();
}

Cone::operator std::string() const {
    return "cone => " + Shape::operator std::string();
}

bool Cone::intersect(const Ray& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_tanX);
    d1.setY(d1.y() / m_tanY);
    Vector d2 = m_d2;
    float alpha = SQR(d1.x()) + SQR(d1.y()) - SQR(d1.z());
    float beta = 2 * (d1.x() * d2.x() + d1.y() * d2.y() - d1.z() * d2.z());

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
            float interZ = d2.z() + dist * d1.z();
            if (interZ > 0 || interZ < -getHeight()) {
                dist = t2;
            }

        }
        float interZ = d2.z() + dist * d1.z();
        if (interZ > 0 || interZ < -getHeight()) {
            return false;
        }
    }
    return true;
}

bool Cone::intersect_shadow(const Ray& ray, float& dist) {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_tanX);
    d1.setY(d1.y() / m_tanY);
    Vector d2 = (ray.getOrigin() - m_position).rotationVector(m_Mat_rotation);
    d2.setX(d2.x() / m_tanX);
    d2.setY(d2.y() / m_tanY);
    float alpha = SQR(d1.x()) + SQR(d1.y()) - SQR(d1.z());
    float beta = 2 * (d1.x() * d2.x() + d1.y() * d2.y() - d1.z() * d2.z());
    float gamma = SQR(d2.x()) + SQR(d2.y()) - SQR(d2.z());

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
            float interZ = d2.z() + dist * d1.z();
            if (interZ > 0 || interZ < -getHeight()) {
                dist = t2;
            }
        }

        float interZ = d2.z() + dist * d1.z();
        if (interZ > 0 || interZ < -getHeight())
            return (false);

    }
    return true;
}

void Cone::precalcul() {
    m_tanX = m_scale.x() / m_scale.z();
    m_tanY = m_scale.y() / m_scale.z();
    m_d2 = (m_Camera_Pos - m_position).rotationVector(m_Mat_rotation);
    m_d2.setX(m_d2.x() / m_tanX);
    m_d2.setY(m_d2.y() / m_tanY);
    m_gamma = SQR(m_d2.x()) + SQR(m_d2.y()) - SQR(m_d2.z());

    Vector v1 = Vector(1, 0, 0).rotationVector(m_inverse) * m_scale.x() * 2;
    Vector v2 = Vector(0, 1, 0).rotationVector(m_inverse) * m_scale.y() * 2;

    Point pos_down = m_position - m_scale.z() * m_direction;

    Point p0 = pos_down + v1 ;
    Point p1 = pos_down + v2;
    Point p2 = pos_down - v1;
    Point p3 = pos_down - v2;

    m_p1 = Triangle(p0, p1, p2, m_color);
    m_p2 = Triangle(p0, p3, p2, m_color);
}

Vector Cone::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    d1.setX(d1.x() / m_tanX);
    d1.setY(d1.y() / m_tanY);
    Vector normal = m_d2 + d1 * dist;
    normal.setX(normal.x() / m_tanX);
    normal.setY(normal.y() / m_tanY);
    normal.setZ(-normal.z());
    normal = normal * (1.f / normal.norm());
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