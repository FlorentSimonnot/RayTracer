#pragma once

#include "Object.hpp"
#include "Sphere.hpp"

class Shape : public Object {

private:
    int m_color;
    Sphere sphereEnglobante;// Chaque objet doit avoir une sphere englobante

public:
    Shape();

    virtual ~Shape();

    void setColor(int color);

    int getColor();

    Sphere getSphereEnglobante();
    void setSphereEnglobante(Sphere sphere);
    virtual Sphere calculSphereEnglobante();
};