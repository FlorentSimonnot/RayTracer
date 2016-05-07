#pragma once

#include "Object.hpp"
#include "Vector.hpp"
#include "Ray.hpp"

class Shape : public Object {
protected:
    Vector m_position, m_rotation, m_scale, m_color;

public:
    Shape();

    Shape(Vector const& position, Vector const& rotation, Vector const& scale, Vector const& color);

    virtual ~Shape();

    virtual operator std::string() const;
};