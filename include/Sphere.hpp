//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_SPHERE_HPP
#define PROJECT_SPHERE_HPP

#include <Shape.hpp>

// TODO
class Sphere : public Shape {
private:
    Point m_d2; // pre-Calcul pour l'optimisation d'intersection de sphere -> servira pour sphere englobante
    float m_gamma;
public:
    Sphere();

    Sphere(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color);

    virtual ~Sphere();

    bool intersect(const Ray& ray, float& dist);
    bool intersect_shadow(Ray const& ray, float &dist);

    float getRadius();

    Sphere& operator=(Sphere const& o);

    operator std::string() const;

//    void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal);

    void calculBoundingVolume();

    void precalcul();

    Vector getNormalFromPoint(const Ray& ray, float dist) const;
};


#endif //PROJECT_SPHERE_HPP
