//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_RAYTRACER_HPP
#define PROJECT_RAYTRACER_HPP

#include "Scene.hpp"
#include <Gui.hpp>


class RayTracer {
private:
    /// Precalcule afin d'optimiser ///
    float m_pas;

    // The window used to render the scene.
    Gui m_gui;

    int m_nbRayons;

    int m_nbReflexions;

public:
    RayTracer(int nbRayons,int nbReflexions);
    ~RayTracer();

    void draw(Scene const& scene);

    Vector moyenneColor(Vector const &colors) const;

    void computColor(Ray const& ray, Vector& color, int level,Scene const& scene,float cameraDepth);
};


#endif //PROJECT_RAYTRACER_HPP
