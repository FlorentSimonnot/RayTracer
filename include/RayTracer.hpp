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
 //   Gui m_gui;

    int m_nbRayons;

public:
    RayTracer(int nbRayons);
    ~RayTracer();

    int *draw(Scene const& scene,PPMExporter& ppme);
    int *draw(Scene const& scene);

    Vector moyenneColor(Vector const &colors) const;

    Vector computColor(Ray const& ray, Scene const& scene, float cameraDepth, int n);

    Vector& calculLights(const Scene& scene, Vector& color, const MaterialPoint& caracteristics, float facteur,
                         float scalaire, const Vector& refl, Vector& diffuse, Vector& specular) const;
};


#endif //PROJECT_RAYTRACER_HPP
