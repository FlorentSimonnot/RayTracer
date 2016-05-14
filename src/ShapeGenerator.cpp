//
// Created by Narex on 07/05/2016.
//


#include <ShapeGenerator.hpp>
#include <stdlib.h>


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

std::vector<Shape *> ShapeGenerator::getShapes() const {
    return m_shapes;
}

void ShapeGenerator::generate() {

    for (int i = 0; i < m_numberObjects; i++) {
        switch (rand() % 4) {
            case 0:
                generateCylinder();
                break;
            case 1:
                generateRectangle();
                break;
            case 2:
                generateSphere();
                break;
            case 3:
                generateTriangle();
                break;
            default:
                break;
        }
    }
}

void ShapeGenerator::generateCylinder() {
    Point position = randomVector(m_minPosX, m_maxPosX, m_minPosY, m_maxPosY, m_minPosZ, m_maxPosZ);
    Vector color = randomVector(0, 255, 0, 255, 0, 255);
    Vector scale = randomVector(0, 2, 0, 2, 0, 0);
    Vector orientation = randomVector(-1, 1, -1, 1, -1, 1);


    Shape *s = new Cylinder(position, orientation, scale, color);

    m_shapes.emplace_back(s);
}

void ShapeGenerator::generateRectangle() {
    Point position = randomVector(m_minPosX, m_maxPosX, m_minPosY, m_maxPosY, m_minPosZ, m_maxPosZ);
    Vector color = randomVector(0, 255, 0, 255, 0, 255);
    Vector scale = randomVector(0.1, 2, 0.1, 2, 0.1, 2);
    Vector orientation = randomVector(-1, 1, -1, 1, -1, 1);

    Shape *s = new Rectangle(position, orientation, scale, color);
    m_shapes.emplace_back(s);
}

void ShapeGenerator::generateSphere() {
//    Shape *s = new Sphere(center, Vector(0, 0, 0), Vector(radius, radius, radius), Vector(0, 0, 0));
    Point position = randomVector(m_minPosX, m_maxPosX, m_minPosY, m_maxPosY, m_minPosZ, m_maxPosZ);
    Vector color = randomVector(0, 255, 0, 255, 0, 255);
    Vector scale = randomVector(0, 2, 0, 0, 0, 0);
    Vector orientation = randomVector(-1, 1, -1, 1, -1, 1);

    Shape *s = new Sphere(position, orientation, scale, color);
    m_shapes.emplace_back(s);
}

void ShapeGenerator::generateTriangle() {
//    Vector color = randomVector(0,255,0,255,0,255);
//    Shape *s;// = new Triangle();
//    m_shapes.emplace_back(s);
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