#include "Shape.hpp"

Shape::Shape() 
:	Object(), m_position(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_color()
{
}

Shape::Shape(Vector const& position, Vector const& rotation, Vector const& scale) 
:	Object(), m_position(position), m_rotation(rotation), m_scale(scale), m_color()
{
}

Shape::~Shape() {
}

void Shape::setColor(int color) {
    m_color = color;
}

int Shape::getColor(){
    return m_color;
}