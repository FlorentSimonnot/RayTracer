#pragma once

#include <ostream>
#include "Object.hpp"
#include "Vector.hpp"
#include "Matrice.hpp"
#include "Materiaux.hpp"

class Ray;

class Shape : public Object {
protected:
    Vector m_position, m_direction, m_scale, m_color;
    Matrice m_Mat_rotation, m_inverse;
    Materiaux m_Materiau;

    Point m_Camera_Pos;

    Shape* m_boundingVolume;
public:
    Shape();

    Shape(Vector const& color);
    Shape(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color);

    Shape(Shape const& s);
    Shape& operator=(Shape const& o);

    virtual ~Shape();

    virtual operator std::string() const;

    Vector const& getColor() const;

    virtual bool intersect(Ray const& ray, float& dist) = 0;
    virtual bool intersect_shadow(Ray const& ray, float& dist) = 0;

    // A changer la variable color peut etre plus tard
//    virtual void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) = 0;

    bool operator==(Shape const& o);

    bool operator!=(Shape const& o);

    Shape* getBoundingVolume() const;

    virtual void calculBoundingVolume() = 0;

    void setCamera_Pos(Point const& p);

    virtual void precalcul() = 0;

    virtual Vector getNormalFromPoint(const Ray& ray, float dist) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s);
};