//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_RECTANGLE_HPP
#define PROJECT_RECTANGLE_HPP

#include "Shape.hpp"

// TODO
class Rectangle : public Shape {
private:
    Point m_p0,m_p1,m_p2,m_p3,m_p4,m_p5,m_p6,m_p7; // Liste de tout les point du rectangle pour du pre calcul
public:
    Rectangle();

    Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color);

    virtual ~Rectangle();

    operator std::string() const;

    bool intersect(Ray const& ray, float& dist);

//    void computeColorNormal(const Ray& ray, float dist, Vector& color, Vector& normal);

    BoundingVolume getBoundingVolume();

    void precalcul();
};

#endif //PROJECT_RECTANGLE_HPP
