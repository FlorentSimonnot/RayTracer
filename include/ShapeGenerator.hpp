//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
#define SYNTHESE_IMAGE_OBJECTGENERATOR_HPP

#include <Cylinder.hpp>
#include "Rectangle.hpp"
#include "Sphere.hpp"
#include "Triangle.hpp"
#include <vector>

class ShapeGenerator {
private:
    float m_numberObjects;

    std::vector<Shape *> m_shapes;

    /// Position ///
    float m_minPosX;
    float m_minPosY;
    float m_minPosZ;

    float m_maxPosX;
    float m_maxPosY;
    float m_maxPosZ;

    void generateCylinder();

    void generateRectangle();

    void generateSphere();

    void generateTriangle();

    Vector randomVector(float minX,float maxX,float minY,float maxY,float minZ,float maxZ);

public:
    ShapeGenerator();

    ShapeGenerator(float numberObjects, float minPosX, float maxPosX, float minPosY, float maxPosY,
                   float minPosZ, float maxPosZ);

    virtual ~ShapeGenerator();

    std::vector<Shape *> getShapes() const;

    void generate();


};


#endif //SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
