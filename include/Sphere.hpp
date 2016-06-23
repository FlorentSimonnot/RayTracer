//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include <Shape.hpp>

class Sphere : public Shape {
private:
    Point m_d2; // pre-Calcul pour l'optimisation d'intersection de sphere -> servira pour sphere englobante
    float m_gamma;
public:
    Sphere();

    Sphere(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color, float angle,
           std::string material_name);

    virtual ~Sphere();

    bool intersect(const Ray& ray, float& dist);
    bool intersect_shadow(Ray const& ray, float &dist);

    float getRadius();

    Sphere& operator=(Sphere const& o);

    operator std::string() const;

    void precalcul();

    Vector getNormalFromPoint(const Ray& ray, float dist) const;
};


#endif //PROJECT_SPHERE_HPP
