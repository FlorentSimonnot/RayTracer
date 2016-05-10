//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_RAYTRACER_HPP
#define PROJECT_RAYTRACER_HPP

#include "Scene.hpp"
#include <Gui.hpp>

class RayTracer {
private:
    // Ajouter dimension
//    Camera camera;
    Camera camera;
    // Concerne celui qui regarde
    // A remplacer par la camera après
    Point m_position; // Position de la camera
    Vector m_orientation; // Orientation de la camera
    float m_depth;
    ///////////////////////

    /// Precalcule afin d'optimiser ///
    float m_pas;

    // The window used to render the scene.
    Gui m_gui;

public:
    RayTracer(float depth, Point const& pos, Vector const& orientation);
    ~RayTracer();

    void draw(Scene const& scene);
    void updateCamera(Point const& origin, Vector const& direction);
};


#endif //PROJECT_RAYTRACER_HPP
