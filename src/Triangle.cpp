#include <limits>
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

// TODO Changer les valeurs
// Ne pas utiliser actuellement
// Evite juste que le compilateur rale
BoundingVolume Triangle::getBoundingVolume() {
    BoundingVolume boundingVolume(m_position, m_scale.x());
    return boundingVolume;
}

void Triangle::computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) {
    
}