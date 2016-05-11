//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>
#include <stdio.h>

#include "RayTracer.hpp"

RayTracer::RayTracer(float depth, Point const& pos, Vector const& orientation)
        : camera(depth, pos, orientation),
          m_position(pos),
          m_orientation(orientation),
          m_depth(depth),
          m_pas((float) 1.57 / WINDOW_WIDTH),
          m_gui() {
}

RayTracer::~RayTracer() { }

void RayTracer::draw(Scene const& scene) {
    for (int j = 0; j < WINDOW_HEIGHT; ++j) {
        for (int i = 0; i < WINDOW_WIDTH; ++i) {

            // -> Format :
            // Vector(1, 0, 0) en dir, Vector(0, 1, 0) en droite et Vector(0, 0, -1) en bas
            // TODO Changer les valeurs pour prendre en compte la camera
//            Vector directionTempo(
//                    1,
//                    m_pas * (i - WINDOW_WIDTH / 2.f),
//                    -m_pas * (j - WINDOW_HEIGHT / 2.f)
//
//            );
            // Ne fonctionne pas si rotation de la camera
            // Changer les vecteur 0,0,1 et 0,-1,0 par camera right et down
//            Vector directionTempo(
//                    camera.getOrientation()
//                            .rotationVector(m_pas * (i - WINDOW_WIDTH / 2.f),
//                                            Vector(0, 0, 1))
//                            .rotationVector(-m_pas * (j - WINDOW_HEIGHT / 2.f),
//                                            Vector(0, -1, 0))
//            );
            Vector directionTempo(
                    camera.orientation()
                            .rotationVector(m_pas * (i - WINDOW_WIDTH / 2.f),
                                            camera.orientation_down())
                            .rotationVector(-m_pas * (j - WINDOW_HEIGHT / 2.f),
                                            camera.orientation_right())
            );
            directionTempo *= 1. / directionTempo.norm();

            Point p = camera.position();
            Ray ray(p, directionTempo);

            // Calcul de la couleur a afficher
            Shape const *shape = scene.getFirstCollision(ray, camera.depth());
            if (shape) {
                m_gui.setPixel(i, j, shape->getColor());
            }
        }
    }

    m_gui.render();
    // TODO A supprimer plus tard
    // Met le programme en pause et attent une saisie
    scanf("%*c");
}

// TODO A changer l'avenir
void RayTracer::updateCamera(Point const& position, Vector const& orientation) {
    this->m_position = position;
    this->m_orientation = orientation;
}