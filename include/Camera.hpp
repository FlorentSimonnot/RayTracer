//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_CAMERA_HPP
#define SYNTHESE_IMAGE_CAMERA_HPP

#include "Vector.hpp"
#include "Point.hpp"

class Camera {
private:
    float m_fov; // Angle d'ouverture
    float m_depth; // Profondeur de vue <=> distance max jusqu'a laquel les objets apparaissent
    Vector m_orientation; // Orientation de la camera
    Point m_position; // Position de la camera

public:
    Camera();

    Camera(Point position, Vector orientation);

    Camera(float fov, float depth, Point position, Vector orientation);

    ~Camera();

    float getFov();

    float getDepth();

    Point getPosition();

    Vector getOrientation();

    void setFov(float val);

    void setDepth(float val);

    void setPosition(Point position);

    void setOrientation(Vector orientation);

};


#endif //SYNTHESE_IMAGE_CAMERA_HPP
