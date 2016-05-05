#pragma once

#include "Object.hpp"

class Shape: public Object {
public:
	Shape();
	virtual ~Shape();

private:
	int m_color;

    void setColor(int color);
    int getColor();
};