//
// Created by Narex on 05/04/2016.
//

#include "Point.hpp"

Point::Point()
		: Vector() {
}

Point::Point(float x, float y, float z)
		: Vector(x, y, z) {
}

Point::Point(Vector const &o)
		: Vector(o) {
}

Point::~Point() {
}

float Point::distance(Point const &o) const {
	return (*this - o).norm();
}