//
// Created by Narex on 05/04/2016.
//

#include <Triangle.hpp>
#include "Rectangle.hpp"

Rectangle::Rectangle()
        : Shape(),
          m_p0(),
          m_p1(),
          m_p2(),
          m_p3(),
          m_p4(),
          m_p5(),
          m_p6(),
          m_p7() {
}

Rectangle::Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color)
        : Shape(position, direction, scale, color),
          m_p0(),
          m_p1(),
          m_p2(),
          m_p3(),
          m_p4(),
          m_p5(),
          m_p6(),
          m_p7() {
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

    Triangle t1(m_p0, m_p1, m_p2, m_color);
    Triangle t2(m_p0, m_p2, m_p3, m_color);

    Triangle t3(m_p0, m_p1, m_p5, m_color);
    Triangle t4(m_p0, m_p4, m_p5, m_color);

    Triangle t5(m_p0, m_p3, m_p7, m_color);
    Triangle t6(m_p0, m_p4, m_p7, m_color);

    Triangle t7(m_p6, m_p1, m_p5, m_color);
    Triangle t8(m_p6, m_p1, m_p2, m_color);

    Triangle t9(m_p6, m_p3, m_p7, m_color);
    Triangle t10(m_p6, m_p3, m_p2, m_color);

    Triangle t11(m_p6, m_p4, m_p5, m_color);
    Triangle t12(m_p6, m_p4, m_p7, m_color);

    Triangle triangles[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12};
    for (Triangle t:triangles) {
        if (t.intersect(ray, dist)) {
            return true;
        }
    }
    return false;
}

// TODO Changer les valeurs
// Ne pas utiliser actuellement
// Evite juste que le compilateur rale
BoundingVolume Rectangle::getBoundingVolume() {
    Point center = m_position + (1.f / 2.f) * m_scale;
    float radius = m_scale.norm() / 2.f;
    BoundingVolume boundingVolume(center, radius);
    return boundingVolume;
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
}