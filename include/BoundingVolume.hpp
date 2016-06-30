//
// Created by Irknar on 02/06/2016.
//

#ifndef BOUNDINGVOLUME_HPP
#define BOUNDINGVOLUME_HPP

#include "Vector.hpp"
#include "Ray.hpp"

class BoundingVolume {
public:
	BoundingVolume(Vector center, float radius);
	BoundingVolume();

	bool intersect(Ray const &ray, float depth) const;
	Vector getCenter(void) const;

private:
	Vector m_center;
	float m_radius;
};

#endif //BOUNDINGVOLUME_HPP
