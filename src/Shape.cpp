#include "Shape.hpp"
#include <iostream>

Shape::Shape()
        : Object(), m_position(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_color(255, 0, 0) {
}

Shape::Shape(const Vector& position, const Vector& rotation, const Vector& scale, Vector const& color)
        : Object(), m_position(position), m_rotation(rotation), m_scale(scale), m_color(color) {
}

Shape::~Shape() {
}

Shape::operator std::string() const {
    return "position : " + std::string(m_position) + "\t rotation : " + std::string(m_rotation) + "\t scale : " +
           std::string(m_scale) + "\t color : " + std::string(m_color);
}