//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_CAMERA_HPP
#define SYNTHESE_IMAGE_CAMERA_HPP

#include "Vector.hpp"
#include "Point.hpp"
#include "Object.hpp"

class Camera: public Object {
private:
    float m_fov; // Angle d'ouverture

//    float m_width,m_height;
    float m_depth; // Profondeur de vue <=> distance max jusqu'a laquel les objets apparaissent
    Point m_position; // Position de la camera
    Vector m_orientation; // Orientation de la camera

public:
    Camera();
    Camera(Point const& position, Vector const& orientation);
    Camera(float fov, float depth, Point const& position, Vector const& orientation);
    virtual ~Camera();

    virtual operator std::string() const;

    float getFov();

//    float width();
//
//    float height();

    float depth();

    Point getPosition();

    Vector getOrientation();

    void setFov(float val);

//    void setWidth(float val);
//
//    void setHeight(float val);

    void setDepth(float val);

    void setPosition(Point position);

    void setOrientation(Vector orientation);

};


#endif //SYNTHESE_IMAGE_CAMERA_HPP
