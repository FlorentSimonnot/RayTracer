//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "RayTracer.hpp"

RayTracer::RayTracer(float depth, Point const& pos, Vector const& orientation, int nbRayon)
        : camera(depth, pos, orientation),
          m_pas((float) 1.57 / WINDOW_WIDTH),
          m_gui(),
          m_nbRayons(nbRayon) {
}

RayTracer::~RayTracer() { }

void RayTracer::draw(Scene const& scene) {
    for (int j = 0; j < WINDOW_HEIGHT; ++j) {
        for (int i = 0; i < WINDOW_WIDTH; ++i) {
            float angle_x = m_pas * (i - WINDOW_WIDTH / 2.f);
            float angle_y = m_pas * (j - WINDOW_HEIGHT / 2.f);

            Vector color(0, 0, 0);
            for (int k = 0; k < m_nbRayons; k++) {
                float off_x = (float) ((rand() / RAND_MAX) - 0.5) * m_pas;
                float off_y = (float) ((rand() / RAND_MAX) - 0.5) * m_pas;
                camera.orientation() *= 1. / camera.orientation().norm();
                Vector directionTempo(
                        camera.orientation()
                                .rotationVector((angle_x + off_x) * cosf(angle_y + off_y),
                                                camera.orientation_down())
                                .rotationVector(angle_y + off_y,
                                                camera.orientation_right())
                );
                directionTempo *= 1. / directionTempo.norm();

                Point p = camera.position();
                Ray ray(p, directionTempo);
                // Calcul de la couleur a afficher
                Shape const *shape = scene.getFirstCollision(ray, camera.depth());
                if (shape) {
                    color += shape->getColor();
                }

            }

            color = moyenneColor(color);
//            std::cout << std::string(color) << std::endl;
            m_gui.setPixel(i, j, color);
        }
    }

    m_gui.render();
    // TODO A supprimer plus tard
    // Met le programme en pause et attent une saisie
    scanf("%*c");
}

Vector RayTracer::moyenneColor(Vector const& colors) const {
    float divide = (float) 1. / m_nbRayons;
    return Vector((float) round(colors.x() * divide),
                  (float) round(colors.y() * divide),
                  (float) round(colors.z() * divide));
}