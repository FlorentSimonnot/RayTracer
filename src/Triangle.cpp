#include "Triangle.hpp"

Triangle::Triangle(Point const& p1, Point const& p2, Point const& p3)
:	Shape(), m_p1(p1), m_p2(p2), m_p3(p3)
{
}

Triangle::~Triangle() {
}