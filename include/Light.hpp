//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_LIGHT_HPP
#define SYNTHESE_IMAGE_LIGHT_HPP

#include "Object.hpp"
#include <Vector.hpp>
#include <Point.hpp>

class Ray;

class Light : public Object {
private:
    Point m_position;
    Vector m_color;

public:
    Light();
    Light(Point const& position,Vector const& color);
    operator std::string() const;
    Vector computColor(const Ray& ray, float dist);
    Vector getCenter();
};


#endif //SYNTHESE_IMAGE_LIGHT_HPP
