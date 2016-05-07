#include "Shape.hpp"

Shape::Shape() 
:	Object(), m_position(0.f, 0.f, 0.f), m_rotation(0.f, 0.f, 0.f), m_scale(1.f, 1.f, 1.f), m_color()
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