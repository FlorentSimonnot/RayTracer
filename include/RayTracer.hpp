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
    Scene m_scene;
//    Camera camera;

    // Concerne celui qui regarde
    // A remplacer par la camera après
    Point m_position; // Position de la camera
    Vector m_orientation; // Orientation de la camera
    float m_width, m_height;
    float m_depth;
    ///////////////////////

    /// Resolution ///
    float m_pixelWidth;
    float m_pixelHeight;

    /// Precalcule afin d'optimiser ///
    float m_precompWidth;
    float m_precompHeight;

    Gui m_gui;

    void updatePrecomp();

public:
    RayTracer();

    RayTracer(float width, float heigth, float depth, float pixelWidth, float pixelHeight, Scene scene,Gui gui);

    ~RayTracer();

    void draw();

    void computColor(Ray const& ray, Vector color);

    void updateCamera(float width, float height, Point const& origin, Vector const& direction);


};


#endif //PROJECT_RAYTRACER_HPP
