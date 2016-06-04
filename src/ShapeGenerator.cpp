//
// Created by Narex on 07/05/2016.
//


#include <ShapeGenerator.hpp>
#include <stdlib.h>

#include <Cylinder.hpp>
#include "Rectangle.hpp"
#include "Sphere.hpp"
#include <Cone.hpp>

ShapeGenerator::ShapeGenerator()
        : m_numberObjects(100),
          m_shapes(),
          m_minPosX(),
          m_minPosY(),
          m_minPosZ(),
          m_maxPosX(),
          m_maxPosY(),
          m_maxPosZ() {
}

ShapeGenerator::ShapeGenerator(float numberObjects, float minPosX, float maxPosX, float minPosY, float maxPosY,
                               float minPosZ, float maxPosZ)
        : m_numberObjects(numberObjects),
          m_shapes(),
          m_minPosX(minPosX),
          m_minPosY(minPosY),
          m_minPosZ(minPosZ),
          m_maxPosX(maxPosX),
          m_maxPosY(maxPosY),
          m_maxPosZ(maxPosZ) {
}

ShapeGenerator::~ShapeGenerator() { }

std::vector<Shape*> ShapeGenerator::getShapes() const {
    return m_shapes;
}

void ShapeGenerator::generate() {
    for (int i = 0; i < m_numberObjects; i++) {
        int type = rand() % 4;
        generateShape(type);
    }
}

Shape* ShapeGenerator::generateCylinder(const Point position, const Vector orientation, const Vector scale,
                                        const Vector color) {
    Shape* s = new Cylinder(position, orientation, scale, color, 0);
    return s;
}

Shape* ShapeGenerator::generateRectangle(const Point position, const Vector orientation, const Vector scale,
                                         const Vector color) {
    Shape* s = new Rectangle(position, orientation, scale, color, 0);
    return s;
}

Shape* ShapeGenerator::generateSphere(const Point position, const Vector orientation, const Vector scale,
                                      const Vector color) {
    Shape* s = new Sphere(position, orientation, scale, color, 0);
    return s;
}

Shape* ShapeGenerator::generateCone(const Point position, const Vector orientation, const Vector scale,
                                    const Vector color) {
    Shape* s = new Cone(position, orientation, scale, color, 0);
    return s;
}

Shape* ShapeGenerator::generateTriangle(const Point position_1, const Point position_2, const Point position_3,
                                        const Vector color) {
    Shape* s = new Triangle(position_1, position_2, position_3, color);
    return s;
}


Vector ShapeGenerator::randomVector(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
    float rangeX = maxX - minX;
    float x = rangeX * ((((float) rand()) / (float) RAND_MAX)) + minX;

    float rangeY = maxY - minZ;
    float y = rangeY * ((((float) rand()) / (float) RAND_MAX)) + minY;

    float rangeZ = maxZ - minZ;
    float z = rangeZ * ((((float) rand()) / (float) RAND_MAX)) + minZ;

    return Vector(x, y, z);
}

// TODO
void ShapeGenerator::generateShape(int type) {

    Point position = randomVector(m_minPosX, m_maxPosX, m_minPosY, m_maxPosY, m_minPosZ, m_maxPosZ);
    Vector color = randomVector(0, 255, 0, 255, 0, 255);
    Vector scale = randomVector(0, 2, 0, 2, 0, 0);
    Vector orientation = randomVector(-1, 1, -1, 1, -1, 1);
    Shape* s;
    switch (type) {
        case 0:
            s = generateCylinder(position, orientation, scale, color);
            break;
        case 1:
            s = generateRectangle(position, orientation, scale, color);
            break;
        case 2:
            s = generateSphere(position, orientation, scale, color);
            break;
        case 3:
//            Point position_2 = randomVector();
//            Point position_3 = randomVector();
            s = generateTriangle(position, orientation, scale, color);
            break;
        case 4:
            s = generateCone(position, orientation, scale, color);
            break;
        default:
            break;
    }
    m_shapes.emplace_back(s);
}