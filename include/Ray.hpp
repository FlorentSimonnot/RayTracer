//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RAY_HPP
#define PROJECT_RAY_HPP

#include <ostream>
#include "Point.hpp"

class Ray {
private:
    Point origin;
    Vector direction;

public:
    Ray(Point const& origin, Vector const& direction);

    ~Ray();

    void setOrigin(const Point& p);

    void setDirection(const Vector& v);

    Point getOrigin() const;

    Vector getDirection() const;

    friend std::ostream& operator<<(std::ostream& out, const Ray& r);
};


#endif //PROJECT_RAY_HPP
