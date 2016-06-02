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
    Triangle m_t1,m_t2,m_t3,m_t4,m_t5,m_t6,m_t7,m_t8,m_t9,m_t10,m_t11,m_t12;
public:
    Rectangle();

    Rectangle(Vector const& position, Vector const& direction, Vector const& scale, Vector const& color, float angle);

    virtual ~Rectangle();

    operator std::string() const;

    bool intersect(Ray const& ray, float& dist);
    bool intersect_shadow(Ray const& ray, float &dist);

    void precalcul();

    Vector getNormalFromPoint(const Ray& ray, float dist) const;
};

#endif //PROJECT_RECTANGLE_HPP
