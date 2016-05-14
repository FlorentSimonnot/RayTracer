//
// Created by Narex on 15/05/2016.
//

#include "MaterialPoint.hpp"

MaterialPoint::MaterialPoint()
        : m_normal(),
          m_color(),
          m_pointIntersection() {
}

Vector MaterialPoint::color() const {
    return m_color;
}

Vector MaterialPoint::normal() const {
    return m_normal;
}

Point MaterialPoint::pointIntersection() const {
    return m_pointIntersection;
}

void MaterialPoint::setColor(Vector const& v) {
    m_color = v;
}

void MaterialPoint::setNormal(Vector const& v) {
    m_normal = v;
}

void MaterialPoint::setPointIntersection(Point const& p) {
    m_pointIntersection = p;
}