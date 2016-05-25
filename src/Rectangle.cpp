//
// Created by Narex on 05/04/2016.
//

#include <Triangle.hpp>
#include <Sphere.hpp>
#include <limits>
#include "Rectangle.hpp"

Rectangle::Rectangle()
        : Shape(),
          m_p0(), m_p1(), m_p2(), m_p3(), m_p4(), m_p5(), m_p6(), m_p7(),
          m_t1(), m_t2(), m_t3(), m_t4(), m_t5(), m_t6(), m_t7(), m_t8(), m_t9(), m_t10(), m_t11(), m_t12() {
}

Rectangle::Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color)
        : Shape(position, direction, scale, color),
          m_p0(), m_p1(), m_p2(), m_p3(), m_p4(), m_p5(), m_p6(), m_p7(),
          m_t1(), m_t2(), m_t3(), m_t4(), m_t5(), m_t6(), m_t7(), m_t8(), m_t9(), m_t10(), m_t11(), m_t12() {
}

Rectangle::~Rectangle() {
}

Rectangle::operator std::string() const {
    return "rectangle => " + Shape::operator std::string();
}

bool Rectangle::intersect(const Ray& ray, float& dist) {

    // Format du rectangle pour la construction
    // Repere de la forme
    //  y  z
    //  | /
    //  |/___ x
    // P7 ____ P6
    //   /   /|
//      /   / | P5
//  p3 /___/  /
//    |    | /
//    |____|/
//   p0    P1


    Triangle triangles[] = {m_t1, m_t2, m_t3, m_t4, m_t5, m_t6, m_t7, m_t8, m_t9, m_t10, m_t11, m_t12};
    bool test = false;
    float tmp_dist;
    for (Triangle t:triangles) {
        if (t.intersect(ray, tmp_dist)) {
            test = true;
            if (dist > tmp_dist && tmp_dist >= std::numeric_limits<float>::epsilon()) {
                dist = tmp_dist;
            }
        }
    }
    return test;
}

bool Rectangle::intersect_shadow(const Ray& ray, float& dist) {
    return intersect(ray, dist);
}

void Rectangle::calculBoundingVolume() {
    Point center = m_position + (1.f / 2.f) * m_scale;
    float radius = m_scale.norm() / 2.f;
    Sphere *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0));
    m_boundingVolume = s;
}

void Rectangle::precalcul() {
    m_p0 = m_position;
    m_p1 = Point(m_position.x() + m_scale.x(), m_position.y(), m_position.z());
    m_p2 = Point(m_position.x() + m_scale.x(), m_position.y() + m_scale.y(), m_position.z());
    m_p3 = Point(m_position.x(), m_position.y() + m_scale.y(), m_position.z());

    m_p4 = Point(m_position.x(), m_position.y(), m_position.z() + m_scale.z());
    m_p5 = Point(m_position.x() + m_scale.x(), m_position.y(), m_position.z() + m_scale.z());
    m_p6 = Point(m_position.x() + m_scale.x(), m_position.y() + m_scale.y(), m_position.z() + m_scale.z());
    m_p7 = Point(m_position.x(), m_position.y() + m_scale.y(), m_position.z() + m_scale.z());

    m_t1 = Triangle(m_p0, m_p1, m_p2, m_color);
    m_t2 = Triangle(m_p0, m_p2, m_p3, m_color);

    m_t3 = Triangle(m_p0, m_p1, m_p5, m_color);
    m_t4 = Triangle(m_p0, m_p4, m_p5, m_color);

    m_t5 = Triangle(m_p0, m_p3, m_p7, m_color);
    m_t6 = Triangle(m_p0, m_p4, m_p7, m_color);

    m_t7 = Triangle(m_p6, m_p1, m_p5, m_color);
    m_t8 = Triangle(m_p6, m_p1, m_p2, m_color);

    m_t9 = Triangle(m_p6, m_p3, m_p7, m_color);
    m_t10 = Triangle(m_p6, m_p3, m_p2, m_color);

    m_t11 = Triangle(m_p6, m_p4, m_p5, m_color);
    m_t12 = Triangle(m_p6, m_p4, m_p7, m_color);
}

Vector Rectangle::getNormalFromPoint(const Ray& ray, float dist) const {
    Vector collide(ray.getOrigin() + dist * ray.getDirection());
    Vector tmp = collide - m_position;
    Vector normal(0, 0, 0);

    float eps = 0.00001;
    if (tmp.x() <= eps && tmp.x() >= -eps) {
        normal = Vector(-1, 0, 0);
    }
    else if (tmp.x() <= m_scale.x() + eps && tmp.x() >= m_scale.x() - eps) {
        normal = Vector(1, 0, 0);
    }
    else if (tmp.y() <= eps && tmp.y() >= -eps) {
        normal = Vector(0, -1, 0);
    }
    else if (tmp.y() <= m_scale.y() + eps && tmp.y() >= m_scale.y() - eps) {
        normal = Vector(0, 1, 0);
    }
    else if (tmp.z() <= eps && tmp.z() >= -eps) {
        normal = Vector(0, 0, -1);
    }
    else if (tmp.z() <= m_scale.z() + eps && tmp.z() >= m_scale.z() - eps) {
        normal = Vector(0, 0, 1);
    }
    if (ray.getDirection().produitScalaire(normal) > 0) {
        normal = -normal;
    }
    return normal;
}