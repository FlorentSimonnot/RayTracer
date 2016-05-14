//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_RAYTRACER_HPP
#define PROJECT_RAYTRACER_HPP

#include "Scene.hpp"
#include <Gui.hpp>

/// Carateristique d'une primitive en un point donné
struct MaterialPoint{
    /// Normale de la primitive en un point
    Vector m_normal;
    /// Couleur du point
    Vector m_color;
    /// "Couleur" de la réflexion
    Vector m_reflect;
};

class RayTracer {
private:
    /// Precalcule afin d'optimiser ///
    float m_pas;

    // The window used to render the scene.
    Gui m_gui;

    int m_nbRayons;

public:
    RayTracer(int nbRayons);
    ~RayTracer();

    void draw(Scene const& scene);

    Vector moyenneColor(Vector const &colors) const;

    void updateCamera(float depth, Point const& pos, Vector const& orientation);

//    void computColor
};


#endif //PROJECT_RAYTRACER_HPP
