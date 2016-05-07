#pragma once

#include "Object.hpp"
#include "Vector.hpp"

class Ray;

class Shape : public Object {
protected:
	Vector m_position, m_rotation, m_scale;

private:
    int m_color;

public:
    Shape();
    Shape(Vector const& position, Vector const& rotation, Vector const& scale);
    virtual ~Shape();

    virtual operator std::string() const;

    void setColor(int color);
    int getColor();
};