//
// Created by Narex on 07/05/2016.
//


#include "Light.hpp"

Light::Light()
        : m_position(), m_rotation(), m_color(255, 255, 0) { }

Light::Light(Point const& position, Vector const& rotation, Vector const& color)
        : m_position(position), m_rotation(rotation), m_color(color) { }

Light::operator std::string() const {
    return "position : " + std::string(m_position) + "\t rotation : " + std::string(m_rotation) +
           "\t color : " + std::string(m_color);
}