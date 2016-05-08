//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>

#include "RayTracer.hpp"

RayTracer::RayTracer() :
        m_position(0, 0, 0),
        m_orientation(0, 0, 0),
        m_width(100),
        m_height(100),
        m_depth(50),
        m_pixelWidth(640),
        m_pixelHeight(480),
        m_scene(),
        m_gui(),
        m_precompWidth(0),
        m_precompHeight(0) { }

RayTracer::RayTracer(float width, float height, float depth, float pixelWidth, float pixelHeight, Scene scene, Gui gui)
        : m_position(0, 0, 0),
          m_orientation(0, 0, 0),
          m_width(width),
          m_height(height),
          m_depth(depth),
          m_pixelWidth(pixelWidth),
          m_pixelHeight(pixelHeight),
          m_scene(scene),
          m_gui(gui),
          m_precompWidth(0),
          m_precompHeight(0) {
    updatePrecomp();
}

RayTracer::~RayTracer() { }

void RayTracer::draw() {

    for (int i = 0; i < m_pixelWidth; ++i) {
        for (int j = 0; j < m_pixelHeight; ++j) {
            Vector directionTempo(
                    m_precompWidth * (i - m_pixelWidth / 2.f),
                    m_precompHeight * (j - m_pixelHeight / 2.f),
                    m_depth
            );
            Ray ray(m_position, directionTempo);
            Vector color(0, 0, 0);
            // Calcul de la couleur a afficher
            computColor(ray, color);

            m_gui.setPixel(i, j, color);
        }
    }

}

void RayTracer::updatePrecomp() {
    m_precompWidth = m_width / m_pixelWidth;
    m_precompHeight = m_height / m_pixelHeight;
}

void RayTracer::computColor(Ray const& ray, Vector color) {
    float dist;
    float index = m_scene.getFirstCollision(ray, dist);
    if (index < 0)
        return;

    Vector normal;
    Shape shape = m_scene.getShape(index);
    shape.computeColorNormal(ray, dist, color, normal);
}

// TODO A changer l'avenir
void RayTracer::updateCamera(float width, float height, Point const& position, Vector const& orientation) {
    this->m_width = width;
    this->m_height = height;
    this->m_position = position;
    this->m_orientation = orientation;
    updatePrecomp();
}