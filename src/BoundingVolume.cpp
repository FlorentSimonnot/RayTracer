//
// Created by Irknar on 02/06/2016.
//

#include "BoundingVolume.hpp"
#include <cmath>
#include <limits>

BoundingVolume::BoundingVolume(Vector center, float radius): m_center(center), m_radius(radius) {
}

BoundingVolume::BoundingVolume(): m_center(), m_radius(0) {
}

bool BoundingVolume::intersect(Ray const &ray, float depth) const {
	Vector ori = ray.getOrigin() - m_center;
	Vector dir = ray.getDirection();

	float beta = 2 * ori.produitScalaire(dir);
	float gamma = ori.produitScalaire(ori) - m_radius * m_radius;

	float delta = beta * beta - 4 * gamma;
	if (delta < 0) {
		return false;
	}

	float t1 = (-beta + sqrt(delta)) / 2;
	float t2 = (-beta - sqrt(delta)) / 2;

	if (t1 < std::numeric_limits<float>::epsilon() || t2 > depth) {
		return false;
	}
	return true;
}

Vector BoundingVolume::getCenter(void) const {
	return (m_center);
}
