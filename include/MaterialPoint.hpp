//
// Created by Narex on 15/05/2016.
//

#ifndef SYNTHESE_IMAGE_MATERIALPOINT_HPP
#define SYNTHESE_IMAGE_MATERIALPOINT_HPP

#include "Point.hpp"
class MaterialPoint {
private:
    /// Normale de la primitive en un point
    Vector m_normal;
    /// Couleur du point
    Vector m_color;

    Point m_pointIntersection;
public:
    MaterialPoint();

    void setPointIntersection(Point const& p);
    void setNormal(Vector const& v);
    void setColor(Vector const& v);

    Point pointIntersection() const;
    Vector normal() const;
    Vector color() const;
};


#endif //SYNTHESE_IMAGE_MATERIALPOINT_HPP
