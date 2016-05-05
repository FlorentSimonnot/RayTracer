#pragma once

#include "Shape.hpp"
#include "Point.hpp"

class Triangle: public Shape {
private:
	Point m_p1, m_p2, m_p3;

public:
	Triangle(Point const& p1, Point const& p2, Point const& p3);
	virtual ~Triangle();
};