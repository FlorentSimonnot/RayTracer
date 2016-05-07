#pragma once

#include "Object.hpp"
#include "Vector.hpp"

class Shape: public Object {
public:
	Shape();
	virtual ~Shape();

protected:
	Vector m_position, m_rotation, m_scale;

private:
	int m_color;

    void setColor(int color);
    int getColor();
};