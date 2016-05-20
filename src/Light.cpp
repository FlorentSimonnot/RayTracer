//
// Created by Narex on 07/05/2016.
//


#include "Light.hpp"

Light::Light()
        : m_position(), m_color(255, 255, 255) { }

Light::Light(Point const& position, Vector const& color)
        : m_position(position), m_color(color) { }

Light::operator std::string() const {
    return "Light => position : " + std::string(m_position) + "\t color : " + std::string(m_color);
}

//Vector Light::computColor(const Ray& ray, float dist) {
//    return m_color * (1./ SQR(dist));
//}

Vector Light::getCenter() {
    return m_position;
}

Vector Light::getColor() {
    return m_color;
}