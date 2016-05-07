#include "Shape.hpp"
#include <iostream>

Shape::Shape()
        : Object(), m_position(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_color() {
}

Shape::Shape(const Vector& position, const Vector& rotation, const Vector& scale)
        : Object(), m_position(position), m_rotation(rotation), m_scale(scale), m_color() {
}

Shape::~Shape() {
}

Shape::operator std::string() const {
	return "position : " + std::string(m_position) + "\t rotation : " + std::string(m_rotation) + "\t scale : " + std::string(m_scale);
}

void Shape::setColor(int color) {
    m_color = color;
}

int Shape::getColor() {
    return m_color;
}