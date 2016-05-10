//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>
#include <stdio.h>

#include "RayTracer.hpp"

RayTracer::RayTracer(float width, float height, float depth, Point const& pos, Vector const& orientation)
        : camera(depth, pos, orientation),
          m_position(pos),
          m_orientation(orientation),
          m_width(width),
          m_height(height),
          m_depth(depth),
          m_precompWidth(),
          m_precompHeight(),
          m_gui() {
    updatePrecomp();
}

RayTracer::~RayTracer() { }

void RayTracer::draw(Scene const& scene) {
    for (int j = 0; j < WINDOW_HEIGHT; ++j) {
        for (int i = 0; i < WINDOW_WIDTH; ++i) {

            // TODO Changer les valeurs pour prendre en compte la camera
//            Vector directionTempo(
//                    1,
//                    m_precompWidth * (i - WINDOW_WIDTH / 2.f),
//                    -m_precompHeight * (j - WINDOW_HEIGHT / 2.f)
//
//            );
            // bidouille de test
            Vector directionTempo(
                    m_orientation.x(),
                    m_orientation.y() + m_precompWidth * (i - WINDOW_WIDTH / 2.f),
                    m_orientation.z() - m_precompHeight * (j - WINDOW_HEIGHT / 2.f)
            );
            directionTempo *= 1. / directionTempo.norm();

            Ray ray(m_position, directionTempo);
//            Point p(i,j,50);
//            std::cout << "p " << std::string(p) << std::endl;
//            Ray ray(m_position, m_orientation);

            // Calcul de la couleur a afficher
            Shape const *shape = scene.getFirstCollision(ray);
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

void RayTracer::updatePrecomp() {
    m_precompWidth = m_width / WINDOW_WIDTH;
    m_precompHeight = m_height / WINDOW_HEIGHT;
}

// TODO A changer l'avenir
void RayTracer::updateCamera(float width, float height, Point const& position, Vector const& orientation) {
    this->m_width = width;
    this->m_height = height;
    this->m_position = position;
    this->m_orientation = orientation;
    updatePrecomp();
}