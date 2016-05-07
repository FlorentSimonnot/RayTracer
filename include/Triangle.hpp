#pragma once

#include "Shape.hpp"

class Triangle : public Shape {
private:
    Point m_p1, m_p2, m_p3;

public:
	Triangle();
	Triangle(Point const& p1, Point const& p2, Point const& p3);
	virtual ~Triangle();

    operator std::string() const;

	bool intersect(Ray const& ray, float &dist);
};