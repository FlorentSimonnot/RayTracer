//
// Created by Irknar on 17/05/2016.
//

#ifndef PROJECT_CONE_HPP
#define PROJECT_CONE_HPP

#include "Shape.hpp"
#include "Point.hpp"
#include "Triangle.hpp"
#include "Matrice.hpp"

class Cone : public Shape {
private:
    Point m_d2; // pre-Calcul pour l'optimisation d'intersection de sphere -> servira pour sphere englobante
    float m_gamma;
    float m_tanX;
    float m_tanY;

    Triangle m_p1;
    Triangle m_p2;

public:
    Cone();
    Cone(Vector const& position, Vector const& direction, Vector const& scale,Vector const& color);
    virtual ~Cone();

    operator std::string() const;

    bool intersect(const Ray& ray, float& dist);
    bool intersect_shadow(const Ray& ray, float& dist);

    float getRadius() const ;

    float getHeight() const;

    void calculBoundingVolume();

    void precalcul();

    Vector getNormalFromPoint(const Ray& ray, float dist) const;
};


#endif //PROJECT_CONE_HPP
