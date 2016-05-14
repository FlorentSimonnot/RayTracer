//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_CYLINDER_HPP
#define PROJECT_CYLINDER_HPP

#include "Shape.hpp"
#include "Point.hpp"
#include "Triangle.hpp"

class Cylinder : public Shape {
private:
    Point m_d2; // pre-Calcul pour l'optimisation d'intersection de sphere -> servira pour sphere englobante
    float m_gamma;

    Triangle m_f1p1;
    Triangle m_f1p2;
    Triangle m_f2p1;
    Triangle m_f2p2;

    float m_d2Z;
public:
    Cylinder();
    Cylinder(Vector const& position, Vector const& direction, Vector const& scale,Vector const& color);
    virtual ~Cylinder();

    operator std::string() const;

    bool intersect(const Ray& ray, float& dist);

    float getRadius();

    float getHeight();

//    void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal);

    void calculBoundingVolume();

    void precalcul();
};


#endif //PROJECT_CYLINDER_HPP
