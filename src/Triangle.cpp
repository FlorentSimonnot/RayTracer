#include <limits>
#include <math.h>
#include <Sphere.hpp>
#include "Triangle.hpp"

Triangle::Triangle()
        : Shape(), m_p1(-0.5f, -0.5f, 0), m_p2(0.5f, -0.5f, 0), m_p3(0, 1.f, 0) {
}

Triangle::Triangle(Point const& p1, Point const& p2, Point const& p3, Vector const& color)
        : Shape(color), m_p1(p1), m_p2(p2), m_p3(p3) {
}

Triangle::~Triangle() {
}

Triangle::operator std::string() const {
    return "triangle => " + std::string(m_p1) + " " + std::string(m_p2) + " " + std::string(m_p3) +
           "\t color : " + std::string(m_color);
}

// Algo de Möller-Trumbdore
// TODO A verifier
bool Triangle::intersect(const Ray& ray, float& dist) {
    Vector edge_1(m_p2 - m_p1);
    Vector edge_2(m_p3 - m_p1);
    Vector p(ray.getDirection().crossProduct(edge_2));

    float det = edge_1.produitScalaire(p);

    if (det > -std::numeric_limits<float>::epsilon() &&
        det < std::numeric_limits<float>::epsilon()) {
        return false;
    }
    float inv_det = 1 / det;
    Vector t(ray.getOrigin() - m_p1);

    float u = t.produitScalaire(p) * inv_det;
    if (u < 0 || u > 1) {
        return false;
    }
    Vector q(t.crossProduct(edge_1));

    float v = ray.getDirection().produitScalaire(q) * inv_det;
    if (v < 0 || u + v > 1) {
        return false;
    }

    float t_2 = edge_2.produitScalaire(q) * inv_det;
    if (t_2 > std::numeric_limits<float>::epsilon()) {
        dist = t_2;
        return true;
    }
    return false;
}

void Triangle::calculBoundingVolume() {
    float A = m_p1.distance(m_p2);
    float B = m_p2.distance(m_p3);
    float C = m_p3.distance(m_p1);
    float radius;
    Point center;

    Point a = m_p3;
    Point b = m_p1;
    Point c = m_p2;

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
    Sphere *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0));
    m_boundingVolume = s;
}

void Triangle::precalcul() { }

Vector Triangle::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector crossNorma = (m_p1 - m_p2).crossProduct(m_p2 - m_p3);
    crossNorma *= 1. / crossNorma.norm();
    Vector normal(crossNorma);
    if (ray.getDirection().produitScalaire(normal) > 0) {
        normal = -normal;
    }
    return normal;
}

//void Triangle::computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) {
//
//}