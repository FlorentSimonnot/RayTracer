//
// Created by Narex on 05/04/2016.
//

#include <Triangle.hpp>
#include "Rectangle.hpp"

Rectangle::Rectangle()
        : Shape() {
}

Rectangle::Rectangle(Vector const& position, Vector const& rotation, Vector const& scale, Vector const& color)
        : Shape(position, rotation, scale, color) {
}

Rectangle::~Rectangle() {
}

Rectangle::operator std::string() const {
    return "rectangle => " + Shape::operator std::string();
}

// TODO
bool Rectangle::intersect(const Ray& ray, float& dist) {

    // Idee algo ->
    // Diviser chaque cote en 2 triangle
    // Appliquer l'algorithme intersection ray / triangle sur chacun des triangle
    // -> 12 triangle au total
    // Surement moyen d'ameliorer

    //
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
    Point p0(m_position);
    Point p1(m_position.x() + m_scale.x(), m_position.y(), m_position.z());
    Point p2(m_position.x(), m_position.y() + m_scale.y(), m_position.z());
    Point p3(m_position.x() + m_scale.x(), m_position.y() + m_scale.y(), m_position.z());
    Point p4(m_position.x(), m_position.y(), m_position.z() + m_scale.z());
    Point p5(m_position.x() + m_scale.x(), m_position.y(), m_position.z() + m_scale.z());
    Point p6(m_position.x() + m_scale.x(), m_position.y() + m_scale.y(), m_position.z() + m_scale.z());
    Point p7(m_position.x(), m_position.y() + m_scale.y(), m_position.z() + m_scale.z());

    Triangle t1(p0, p2, p1, m_color);
    Triangle t2(p0, p2, p3, m_color);
    Triangle t3(p0, p1, p4, m_color);
    Triangle t4(p0, p7, p4, m_color);
    Triangle t5(p0, p7, p3, m_color);

    Triangle t6(p5, p6, p7, m_color);
    Triangle t7(p5, p4, p7, m_color);
    Triangle t8(p5, p4, p1, m_color);
    Triangle t9(p5, p2, p1, m_color);
    Triangle t10(p5, p6, p2, m_color);

    Triangle t11(p3, p2, p7, m_color);
    Triangle t12(p6, p2, p7, m_color);

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
    BoundingVolume boundingVolume(m_position, m_scale.x());
    return boundingVolume;
}