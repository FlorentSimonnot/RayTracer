//
// Created by Narex on 07/05/2016.
//


#include "BoundingVolume.hpp"

BoundingVolume::BoundingVolume()
        : m_center(0, 0, 0), m_radius(1) { }

BoundingVolume::BoundingVolume(Point center, float radius)
        : m_center(center), m_radius(radius) { }