#pragma once

#include "Object.hpp"
#include "Vector.hpp"

class Shape : public Object {
protected:
	Vector m_position, m_rotation, m_scale;

private:
    int m_color;

public:
    Shape();
    virtual ~Shape();

    void setColor(int color);
    int getColor();
};