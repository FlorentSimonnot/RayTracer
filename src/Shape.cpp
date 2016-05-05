#include "Shape.hpp"

Shape::Shape() 
:	Object(), m_color()
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