//
// Created by Narex on 05/04/2016.
//

#include "Ray.hpp"

Ray::Ray(Point const& origin, Vector const& direction)
        : origin(origin),
          direction(direction) { }

Ray::~Ray() {

}

void Ray::setDirection(const Vector& v) {
    this->direction = v;
}

void Ray::setOrigin(const Point& p) {
    this->origin = p;
}

Point Ray::getOrigin() const {
    return origin;
}

Vector Ray::getDirection() const {
    return direction;
}

std::ostream& operator<<(std::ostream& out, const Ray& r) {
	out << '(' << r.origin << ", " << r.direction << ')';
	return out;
}
