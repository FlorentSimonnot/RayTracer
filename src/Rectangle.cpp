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
    Point center = m_position + (1.f / 2.f) * m_scale;
    float radius = m_scale.norm() / 2.f;
    m_boundingVolume = BoundingVolume(center, radius);
}

Rectangle::Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color, float angle)
        : Shape(position, direction, scale, color, angle),
          m_p0(), m_p1(), m_p2(), m_p3(), m_p4(), m_p5(), m_p6(), m_p7(),
          m_t1(), m_t2(), m_t3(), m_t4(), m_t5(), m_t6(), m_t7(), m_t8(), m_t9(), m_t10(), m_t11(), m_t12() {
    Point center = m_position + (1.f / 2.f) * m_scale;
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
    Vector normal (0, 0, 0);
    Vector d1 = ray.getDirection().rotationVector(m_Mat_rotation);
    Vector d2 = ray.getOrigin().rotationVector(m_Mat_rotation);
    Vector collide = d2 + dist * d1;
    Vector tmp = collide - m_position;

    float eps = 0.00001;
    if (tmp.x() <= eps && tmp.x() >= -eps) {
        normal = Vector(-1, 0, 0).rotationVector(m_inverse);
    }
    else if (tmp.x() <= m_scale.x() + eps && tmp.x() >= m_scale.x() - eps) {
        normal = Vector(1, 0, 0).rotationVector(m_inverse);
    }
    else if (tmp.y() <= eps && tmp.y() >= -eps) {
        normal = Vector(0, -1, 0).rotationVector(m_inverse);
    }
    else if (tmp.y() <= m_scale.y() + eps && tmp.y() >= m_scale.y() - eps) {
        normal = Vector(0, 1, 0).rotationVector(m_inverse);
    }
    else if (tmp.z() <= eps && tmp.z() >= -eps) {
        normal = Vector(0, 0, -1).rotationVector(m_inverse);
    }
    else if (tmp.z() <= m_scale.z() + eps && tmp.z() >= m_scale.z() - eps) {
        normal = Vector(0, 0, 1).rotationVector(m_inverse);
    }
    if (ray.getDirection().produitScalaire(normal) > 0) {
        normal = -normal;
    }
    return normal;
}