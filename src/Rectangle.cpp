//
// Created by Narex on 05/04/2016.
//

#include <Triangle.hpp>
#include <limits>
#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle()
        : Shape(),
          m_p0(), m_p1(), m_p2(), m_p3(), m_p4(), m_p5(), m_p6(), m_p7(),
          m_t1(), m_t2(), m_t3(), m_t4(), m_t5(), m_t6(), m_t7(), m_t8(), m_t9(), m_t10(), m_t11(), m_t12() {
    Point center = m_position + (1.f / 2.f) * m_scale.rotationVector(m_inverse);
    float radius = m_scale.norm() / 2.f;
    m_boundingVolume = BoundingVolume(center, radius);
}

Rectangle::Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color,
                     float angle, std::string material_name)
        : Shape(position, direction, scale, color, angle, material_name),
          m_p0(), m_p1(), m_p2(), m_p3(), m_p4(), m_p5(), m_p6(), m_p7(),
          m_t1(), m_t2(), m_t3(), m_t4(), m_t5(), m_t6(), m_t7(), m_t8(), m_t9(), m_t10(), m_t11(), m_t12() {
    Point center = m_position + (1.f / 2.f) * m_scale.rotationVector(m_inverse);
    float radius = m_scale.norm() / 2.f;
    m_boundingVolume = BoundingVolume(center, radius);
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
    float tmp_dist1, tmp_dist2 = std::numeric_limits<float>::infinity();
    bool test = false;
    for (Triangle t:triangles) {
        if (t.intersect(ray, tmp_dist1)) {
            if (tmp_dist2 > tmp_dist1 && tmp_dist1 >= std::numeric_limits<float>::epsilon()) {
                test = true;
                tmp_dist2 = tmp_dist1;
            }
        }
    }
    dist = tmp_dist2;
    return test;
}

bool Rectangle::intersect_shadow(const Ray& ray, float& dist) {
    return intersect(ray, dist);
}

void Rectangle::precalcul() {
    Vector vX, vY, vZ;

    vX = Vector(1, 0, 0).rotationVector(m_inverse) * m_scale.x();
    vY = Vector(0, 1, 0).rotationVector(m_inverse) * m_scale.y();
    vZ = Vector(0, 0, 1).rotationVector(m_inverse) * m_scale.z();

    m_p0 = m_position;
    m_p1 = m_position + vX;
    m_p2 = m_position + vX + vY;
    m_p3 = m_position + vY;

    m_p4 = m_position + vZ;
    m_p5 = m_position + vX + vZ;
    m_p6 = m_position + vX + vY + vZ;
    m_p7 = m_position + vY + vZ;

    m_t1 = Triangle(m_p0, m_p1, m_p2, m_color, m_Materiaux.getName());
    m_t2 = Triangle(m_p0, m_p2, m_p3, m_color, m_Materiaux.getName());

    m_t3 = Triangle(m_p0, m_p1, m_p5, m_color, m_Materiaux.getName());
    m_t4 = Triangle(m_p0, m_p4, m_p5, m_color, m_Materiaux.getName());

    m_t5 = Triangle(m_p0, m_p3, m_p7, m_color, m_Materiaux.getName());
    m_t6 = Triangle(m_p0, m_p4, m_p7, m_color, m_Materiaux.getName());

    m_t7 = Triangle(m_p6, m_p1, m_p5, m_color, m_Materiaux.getName());
    m_t8 = Triangle(m_p6, m_p1, m_p2, m_color, m_Materiaux.getName());

    m_t9 = Triangle(m_p6, m_p3, m_p7, m_color, m_Materiaux.getName());
    m_t10 = Triangle(m_p6, m_p3, m_p2, m_color, m_Materiaux.getName());

    m_t11 = Triangle(m_p6, m_p4, m_p5, m_color, m_Materiaux.getName());
    m_t12 = Triangle(m_p6, m_p4, m_p7, m_color, m_Materiaux.getName());
}

Vector Rectangle::getNormalFromPoint(const Ray& ray, float dist) const {

    Triangle triangles[] = {m_t1, m_t2, m_t3, m_t4, m_t5, m_t6, m_t7, m_t8, m_t9, m_t10, m_t11, m_t12};
    float tmp_dist1, tmp_dist2 = std::numeric_limits<float>::infinity();
    Triangle triangle;
    for (Triangle t:triangles) {
        if (t.intersect(ray, tmp_dist1)) {
            if (tmp_dist2 > tmp_dist1) {
                tmp_dist2 = tmp_dist1;
                triangle = t;
            }
        }
    }

    return triangle.getNormalFromPoint(ray, dist);
}

bool Rectangle::enter(Point position, Vector normal) const {
    Vector out = getBoundingVolume().getCenter() - position;

    return out.produitScalaire(normal) > 0;
}
