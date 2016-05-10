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
    float m_width, m_height;
    float m_depth;
    ///////////////////////

    /// Precalcule afin d'optimiser ///
    float m_precompWidth;
    float m_precompHeight;

    // The window used to render the scene.
    Gui m_gui;


    void updatePrecomp();

public:
    RayTracer(float width, float height, float depth, Point const& pos, Vector const& orientation);
    ~RayTracer();

    void draw(Scene const& scene);
    void updateCamera(float width, float height, Point const& origin, Vector const& direction);
};


#endif //PROJECT_RAYTRACER_HPP
