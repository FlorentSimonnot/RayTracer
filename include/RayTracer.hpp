//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_RAYTRACER_HPP
#define PROJECT_RAYTRACER_HPP

#include "Scene.hpp"
#include "Gui.hpp"

class RayTracer {
private:
//    Camera camera;
    Camera camera;
    ///////////////////////

    /// Precalcule afin d'optimiser ///
    float m_pas;

    // The window used to render the scene.
    Gui m_gui;

    int m_nbRayons;

public:
    RayTracer(float depth, Point const& pos, Vector const& orientation,int nbRayons);
    ~RayTracer();

    void draw(Scene const& scene);

    Vector moyenneColor(Vector const &colors) const;

    void updateCamera(float depth, Point const& pos, Vector const& orientation);
};


#endif //PROJECT_RAYTRACER_HPP
