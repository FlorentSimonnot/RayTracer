//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_LIGHT_HPP
#define SYNTHESE_IMAGE_LIGHT_HPP

#include "Object.hpp"
#include <Vector.hpp>
#include <Point.hpp>

class Ray;

// TODO
class Light : public Object {
private:
    Point m_position;
    Vector m_rotation;
    Vector m_color;
//    Ray *rays; Liste des rayons lumineux du point de lumiere
public:
    Light();
    Light(Point const& position,Vector const& rotation,Vector const& color);
    operator std::string() const;
//    Vector computColor();
};


#endif //SYNTHESE_IMAGE_LIGHT_HPP
