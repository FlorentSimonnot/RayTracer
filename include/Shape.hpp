#pragma once

#include "Object.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include <BoundingVolume.hpp>

class Shape : public Object {
protected:
    Vector m_position, m_rotation, m_scale, m_color;

public:
    Shape();
    Shape(Vector const& color);
    Shape(Vector const& position, Vector const& rotation, Vector const& scale, Vector const& color);

    virtual ~Shape();

    virtual operator std::string() const;

    Vector const& getColor() const;

    virtual bool intersect(Ray const& ray, float& dist) = 0;

    // A changer la variable color peut etre plus tard
//    virtual void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) = 0;

    bool operator==(Shape const& o);

    bool operator!=(Shape const& o);

    virtual BoundingVolume getBoundingVolume() = 0;
};