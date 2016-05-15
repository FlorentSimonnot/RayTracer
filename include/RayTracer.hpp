//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_RAYTRACER_HPP
#define PROJECT_RAYTRACER_HPP

#include "Scene.hpp"
#include "Gui.hpp"
#include "PPMExporter.hpp"

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

    void draw(Scene const& scene,PPMExporter& ppme);
    void draw(Scene const& scene);

    Vector moyenneColor(Vector const &colors) const;

    void computColor(Ray const& ray, Vector& color,Scene const& scene,float cameraDepth);
};


#endif //PROJECT_RAYTRACER_HPP
