//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>

#include "RayTracer.hpp"

RayTracer::RayTracer(float width, float height, float depth)
        : m_width(width),
          m_height(height),
          m_depth(depth),
          m_precompWidth(),
          m_precompHeight(),
          m_gui()
{
    updatePrecomp();
}

RayTracer::~RayTracer() { }

void RayTracer::draw(Scene const& scene) {
    for (int i = 0; i < WINDOW_WIDTH; ++i) {
        for (int j = 0; j < WINDOW_HEIGHT; ++j) {
//            Vector directionTempo(
//                    m_precompWidth * (i - WINDOW_WIDTH / 2.f),
//                    m_precompHeight * (j - WINDOW_HEIGHT / 2.f),
//                    m_depth
//            );

//            Ray ray(m_position, directionTempo);
            Ray ray(m_position, m_orientation);

            // Calcul de la couleur a afficher
            Shape const *shape = scene.getFirstCollision(ray);
            if (shape) {
                m_gui.setPixel(i, j, shape->getColor());
            }
        }
    }

    m_gui.render();
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