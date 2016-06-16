#include "Shape.hpp"
#include <iostream>

Shape::Shape()
        : Object(),
          m_position(0.f, 0.f, 0.f),
          m_direction(0.f, 0.f, 0.f),
          m_scale(1.f, 1.f, 1.f),
          m_color(255, 0, 0),
          m_Mat_rotation(),
          m_inverse(),
          m_Materiau(),
          m_Camera_Pos(),
          m_boundingVolume() {
}

Shape::Shape(Vector const& color)
        : Object(),
          m_position(0.f, 0.f, 0.f),
          m_direction(0.f, 0.f, 0.f),
          m_scale(1.f, 1.f, 1.f),
          m_color(color),
          m_Mat_rotation(),
          m_inverse(),
          m_Materiau(),
          m_Camera_Pos(),
          m_boundingVolume() {
}

Shape::Shape(const Vector& position, const Vector& direction, const Vector& scale, Vector const& color, float angle)
        : Object(),
          m_position(position),
          m_direction(direction * (1.f / direction.norm())),
          m_scale(scale),
          m_color(color),
          m_Mat_rotation(Matrice(Vector(0, 0, 1), m_direction, angle)/*/ * Matrice(angle, Vector(0, 0, 1))/*/),
          m_inverse(m_Mat_rotation.inverseMatrix()),
          m_Materiau(),
          m_Camera_Pos(),
          m_boundingVolume() {
/*    m_Mat_rotation = m_Mat_rotation * Matrice(angle, Vector(0, 0, 1).rotationVector(m_Mat_rotation.inverseMatrix()));*/
}

Shape::~Shape() {
}

Shape::operator std::string() const {
    return "position : " + std::string(m_position) + "\t rotation : " + std::string(m_direction) + "\t scale : " +
           std::string(m_scale) + "\t color : " + std::string(m_color);
}

Vector const& Shape::getColor() const {
    return m_color;
}

bool Shape::operator==(Shape const& o) {
    return m_position == o.m_position
           && m_direction == o.m_direction
           && m_scale == o.m_scale
           && m_color == o.m_color;
}

bool Shape::operator!=(Shape const& o) {
    return m_position != o.m_position
           || m_direction != o.m_direction
           || m_scale != o.m_scale
           || m_color != o.m_color;
}

void Shape::setCamera_Pos(Point const& p) {
    m_Camera_Pos = p;
}

BoundingVolume Shape::getBoundingVolume() const {
    return m_boundingVolume;
}

Shape::Shape(Shape const& s)
        : Object(),
          m_position(s.m_position),
          m_direction(s.m_direction * (1.f / s.m_direction.norm())),
          m_scale(s.m_scale),
          m_color(s.m_color),
          m_Mat_rotation(s.m_Mat_rotation),
          m_Materiau(s.m_Materiau),
          m_Camera_Pos(s.m_Camera_Pos),
          m_boundingVolume(s.m_boundingVolume) {
}

Shape& Shape::operator=(Shape const& o) {
    m_position = o.m_position;
    m_direction = o.m_direction * (1.f / o.m_direction.norm());
    m_scale = o.m_scale;
    m_color = o.m_color;
    m_Mat_rotation = o.m_Mat_rotation;
    m_Materiau = o.m_Materiau;
    m_Camera_Pos = o.m_Camera_Pos;
    m_boundingVolume = o.m_boundingVolume;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Shape& s) {
    out << '(' << s.m_position;
    out << ", " << s.m_direction;
    out << ", " << s.m_scale;
    out << ", " << s.m_color << ')';
    return out;
}
