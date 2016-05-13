#include "Shape.hpp"
#include <iostream>

Shape::Shape()
        : Object(),
          m_position(0.f, 0.f, 0.f),
          m_direction(0.f, 0.f, 0.f),
          m_scale(1.f, 1.f, 1.f),
          m_color(255, 0, 0),
          m_Mat_rotation(Vector(0, 0, 1), m_direction),
          m_Materiau(),
          m_Camera_Pos() {
}

Shape::Shape(Vector const& color)
        : Object(),
          m_position(0.f, 0.f, 0.f),
          m_direction(0.f, 0.f, 0.f),
          m_scale(1.f, 1.f, 1.f),
          m_color(color),
          m_Mat_rotation(Vector(0, 0, 1), m_direction),
          m_Materiau(),
          m_Camera_Pos() {
}

Shape::Shape(const Vector& position, const Vector& direction, const Vector& scale, Vector const& color)
        : Object(),
          m_position(position),
          m_direction(direction * (1.f / direction.norm())),
          m_scale(scale),
          m_color(color),
          m_Mat_rotation(Vector(0, 0, 1), m_direction),
          m_Materiau(),
          m_Camera_Pos() {
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