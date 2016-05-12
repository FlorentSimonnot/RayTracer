#pragma once

#include "Object.hpp"
#include "Vector.hpp"
#include "Ray.hpp"
#include <BoundingVolume.hpp>
#include "Matrice.hpp"
#include "Materiaux.hpp"


class Shape : public Object {
protected:
    Vector m_position, m_direction, m_scale, m_color;
    Matrice m_Mat_rotation;
    Materiaux m_Materiau;

    Point m_Camera_Pos;
    Point m_d2; // pre-Calcul pour l'optimisation d'intersection de sphere -> servira pour sphere englobante
public:
    Shape();
    Shape(Vector const& color);
    Shape(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color);

    virtual ~Shape();

    virtual operator std::string() const;

    Vector const& getColor() const;

    virtual bool intersect(Ray const& ray, float& dist) = 0;

    // A changer la variable color peut etre plus tard
//    virtual void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal) = 0;

    bool operator==(Shape const& o);

    bool operator!=(Shape const& o);

    virtual BoundingVolume getBoundingVolume() = 0;

    void setCamera_Pos(Point const& p);

    void calculD2();
};