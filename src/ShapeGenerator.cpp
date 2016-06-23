//
// Created by Narex on 07/05/2016.
//


#include <ShapeGenerator.hpp>
#include <stdlib.h>

#include <Cylinder.hpp>
#include "Rectangle.hpp"
#include "Sphere.hpp"
#include <Cone.hpp>
#include <cmath>
#include <Camera.hpp>
#include <Light.hpp>
#include <iostream>

ShapeGenerator::ShapeGenerator()
        : m_numberObjects(100),
          m_numberCylinder(0), m_numberRectangle(0), m_numberSphere(0), m_numberTriangle(0), m_numberCone(0),
          m_numberSpot(2),
          m_minPosX(0), m_minPosY(0), m_minPosZ(0),
          m_maxPosX(50), m_maxPosY(50), m_maxPosZ(50),
          m_minScaleX(0), m_minScaleY(0), m_minScaleZ(0),
          m_maxScaleX(5), m_maxScaleY(5), m_maxScaleZ(5),
          m_minColorR(0), m_minColorG(0), m_minColorB(0),
          m_maxColorR(255), m_maxColorG(255), m_maxColorB(255),
          m_positionCamera(0, 0, 0), m_orientationCamera(1, 1, 1), m_depth(100) {
    testInitValues();
}

// TEST DONE
ShapeGenerator::ShapeGenerator(int numberObjects)
        : m_numberObjects(numberObjects),
          m_numberCylinder(0), m_numberRectangle(0), m_numberSphere(0), m_numberTriangle(0), m_numberCone(0),
          m_numberSpot(2),
          m_minPosX(0), m_minPosY(0), m_minPosZ(0),
          m_maxPosX(50), m_maxPosY(50), m_maxPosZ(50),
          m_minScaleX(0), m_minScaleY(0), m_minScaleZ(0),
          m_maxScaleX(5), m_maxScaleY(5), m_maxScaleZ(5),
          m_minColorR(0), m_minColorG(0), m_minColorB(0),
          m_maxColorR(255), m_maxColorG(255), m_maxColorB(255),
          m_positionCamera(0, 0, 0), m_orientationCamera(1, 1, 1), m_depth(100) {
    testInitValues();
}

ShapeGenerator::ShapeGenerator(int numberCylinder, int numberRectangle, int numberSphere,
                               int numberTriangle, int numberCone, int numberSpot,
                               float minPosX, float minPosY, float minPosZ,
                               float maxPosX, float maxPosY, float maxPosZ,
                               float minScaleX, float minScaleY, float minScaleZ,
                               float maxScaleX, float maxScaleY, float maxScaleZ,
                               int minColorR, int minColorG, int minColorB,
                               int maxColorR, int maxColorG, int maxColorB,
                               Point positionCamera, Vector orientationCamera, float depth)
        : m_numberObjects(0),
          m_numberCylinder(numberCylinder),
          m_numberRectangle(numberRectangle),
          m_numberSphere(numberSphere),
          m_numberTriangle(numberTriangle),
          m_numberCone(numberCone),
          m_numberSpot(numberSpot),
          m_minPosX(minPosX), m_minPosY(minPosY), m_minPosZ(minPosZ),
          m_maxPosX(maxPosX), m_maxPosY(maxPosY), m_maxPosZ(maxPosZ),
          m_minScaleX(minScaleX), m_minScaleY(minScaleY), m_minScaleZ(minScaleZ),
          m_maxScaleX(maxScaleX), m_maxScaleY(maxScaleY), m_maxScaleZ(maxScaleZ),
          m_minColorR(abs(minColorR) % 255), m_minColorG(abs(minColorG) % 255), m_minColorB(abs(minColorB) % 255),
          m_maxColorR(abs(maxColorR) % 255), m_maxColorG(abs(maxColorG) % 255), m_maxColorB(abs(maxColorB) % 255),
          m_positionCamera(positionCamera), m_orientationCamera(orientationCamera), m_depth(depth) {
    testInitValues();
}

ShapeGenerator::ShapeGenerator(int numberObjects, int numberSpot,
                               float minPosX, float minPosY, float minPosZ,
                               float maxPosX, float maxPosY, float maxPosZ,
                               float minScaleX, float minScaleY, float minScaleZ,
                               float maxScaleX, float maxScaleY, float maxScaleZ,
                               int minColorR, int minColorG, int minColorB,
                               int maxColorR, int maxColorG, int maxColorB,
                               Point positionCamera, Vector orientationCamera, float depth)
        : m_numberObjects(numberObjects),
          m_numberCylinder(0),
          m_numberRectangle(0),
          m_numberSphere(0),
          m_numberTriangle(0),
          m_numberCone(0),
          m_numberSpot(numberSpot),
          m_minPosX(minPosX), m_minPosY(minPosY), m_minPosZ(minPosZ),
          m_maxPosX(maxPosX), m_maxPosY(maxPosY), m_maxPosZ(maxPosZ),
          m_minScaleX(minScaleX), m_minScaleY(minScaleY), m_minScaleZ(minScaleZ),
          m_maxScaleX(maxScaleX), m_maxScaleY(maxScaleY), m_maxScaleZ(maxScaleZ),
          m_minColorR(abs(minColorR) % 255), m_minColorG(abs(minColorG) % 255), m_minColorB(abs(minColorB) % 255),
          m_maxColorR(abs(maxColorR) % 255), m_maxColorG(abs(maxColorG) % 255), m_maxColorB(abs(maxColorB) % 255),
          m_positionCamera(positionCamera), m_orientationCamera(orientationCamera), m_depth(depth) {
    testInitValues();
}


ShapeGenerator::~ShapeGenerator() { }

void ShapeGenerator::testInitValues() {
    if (m_minPosX > m_maxPosX) {
        inverseValue(m_minPosX, m_maxPosX);
    }
    if (m_minPosY > m_maxPosY) {
        inverseValue(m_minPosY, m_maxPosY);
    }
    if (m_minPosZ > m_maxPosZ) {
        inverseValue(m_minPosZ, m_maxPosZ);
    }

    if (m_numberObjects < 0) {
        m_numberObjects = 0;
    }
    if (m_numberRectangle < 0) {
        m_numberRectangle = 0;
    }
    if (m_numberSphere < 0) {
        m_numberSphere = 0;
    }
    if (m_numberTriangle < 0) {
        m_numberTriangle = 0;
    }
    if (m_numberCone < 0) {
        m_numberCone = 0;
    }
    if (m_numberSpot < 0) {
        m_numberSpot = 1;
    }

    if (m_minScaleX < 0) {
        m_minScaleX = 0.1;
    }
    if (m_minScaleY < 0) {
        m_minScaleY = 0.1;
    }
    if (m_minScaleZ < 0) {
        m_minScaleZ = 0.1;
    }

    if (m_maxScaleX < 0) {
        m_maxScaleX = 2;
    }
    if (m_maxScaleY < 0) {
        m_maxScaleY = 2;
    }
    if (m_maxScaleZ < 0) {
        m_maxScaleZ = 2;
    }

    if (m_minScaleX > m_maxScaleX) {
        inverseValue(m_minScaleX, m_maxScaleX);
    }
    if (m_minScaleY > m_maxScaleY) {
        inverseValue(m_minScaleY, m_maxScaleY);
    }
    if (m_minScaleZ > m_maxScaleZ) {
        inverseValue(m_minScaleZ, m_maxScaleZ);
    }

    if (m_depth < 0) {
        m_depth = 50;
    }
}

void ShapeGenerator::inverseValue(float& a, float& b) {
    float temp;
    temp = a;
    a = b;
    b = temp;
}

void ShapeGenerator::generate(std::vector<std::unique_ptr<Object>>& objects) {

    if (m_numberObjects > 0) {
        generateRandomObjects(objects);
        // Au cas ou il n'y a pas eu de generation de lumiere lors de l'aleatoire
        if (m_numberSpot) {
            generateAllSpots(objects);
            std::cout << " -------------------- " << std::endl;
        }
    }
    else {
        if (m_numberCylinder) {
            generateAllCylinder(objects);
        }
        if (m_numberRectangle) {
            generateAllRectangle(objects);
        }
        if (m_numberSphere) {
            generateAllSphere(objects);
        }
        if (m_numberTriangle) {
            generateAllTriangle(objects);
        }
        if (m_numberCone) {
            generateAllCone(objects);
        }
        if (m_numberSpot) {
            generateAllSpots(objects);
        }
    }
    generateShape(CAMERA, objects);
}

void ShapeGenerator::generateRandomObjects(std::vector<std::unique_ptr<Object>>& objects) {
    ObjectType type;
    for (int i = 0; i < m_numberObjects; i++) {
        type = static_cast<ObjectType>(rand() % (LIGHT));
        // On exclue les triangle car non implementé
/*/        if (type == TRIANGLE) {
            i--;
            continue;
        }/*/
        generateShape(type, objects);
        std::cout << " -------------------- " << std::endl;
    }
}

void ShapeGenerator::generateAllCylinder(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberCylinder; i++) {
        generateShape(CYLINDER, objects);
    }
}

void ShapeGenerator::generateAllRectangle(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberRectangle; i++) {
        generateShape(RECTANGLE, objects);
    }
}

void ShapeGenerator::generateAllSphere(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberSphere; i++) {
        generateShape(SPHERE, objects);
    }
}

void ShapeGenerator::generateAllTriangle(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberTriangle; i++) {
        generateShape(TRIANGLE, objects);
    }
}

void ShapeGenerator::generateAllCone(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberCone; i++) {
        generateShape(CONE, objects);
    }
}

void ShapeGenerator::generateAllSpots(std::vector<std::unique_ptr<Object>>& objects) {
    for (int i = 0; i < m_numberSpot; i++) {
        generateShape(LIGHT, objects);
    }
}

void ShapeGenerator::generateCylinder(const Point position, const Vector orientation, const Vector scale,
                                      const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Cylinder(position, orientation, scale, color, 0, "Default"));
    std::cout << " Cylinder " << std::endl
    << " Position = " << position << std::endl
    << " Orientation = " << orientation << std::endl
    << " Scale = " << scale << std::endl
    << " Color = " << color << std::endl;
}

void ShapeGenerator::generateRectangle(const Point position, const Vector orientation, const Vector scale,
                                       const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Rectangle(position, orientation, scale, color, 0, "Default"));
    std::cout << " Rectangle " << std::endl
    << " Position = " << position << std::endl
    << " Orientation = " << orientation << std::endl
    << " Scale = " << scale << std::endl
    << " Color = " << color << std::endl;
}

void ShapeGenerator::generateSphere(const Point position, const Vector orientation, const Vector scale,
                                    const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Sphere(position, orientation, scale, color, 0, "Default"));
    std::cout << " Sphere " << std::endl
    << " Position = " << position << std::endl
    << " Orientation = " << orientation << std::endl
    << " Scale = " << scale << std::endl
    << " Color = " << color << std::endl;
}

void ShapeGenerator::generateCone(const Point position, const Vector orientation, const Vector scale,
                                  const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Cone(position, orientation, scale, color, 0, "Default"));
    std::cout << " Cone " << std::endl
    << " Position = " << position << std::endl
    << " Orientation = " << orientation << std::endl
    << " Scale = " << scale << std::endl
    << " Color = " << color << std::endl;
}

void ShapeGenerator::generateTriangle(const Point position_1, const Point position_2, const Point position_3,
                                      const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Triangle(position_1, position_2, position_3, color, "Default"));
    std::cout << " Triangle " << std::endl
    << " position = " << position_1 << std::endl
    << " position_2 = " << position_2 << std::endl
    << " position_3 = " << position_3 << std::endl
    << " Color = " << color << std::endl;
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

void ShapeGenerator::generateShape(ObjectType type, std::vector<std::unique_ptr<Object>>& objects) {

    Point position = randomVector(m_minPosX, m_maxPosX, m_minPosY, m_maxPosY, m_minPosZ, m_maxPosZ);
    Vector color = randomVector(m_minColorR, m_maxColorR, m_minColorG, m_maxColorG, m_minColorB, m_maxColorB);
    Vector scale = randomVector(m_minScaleX, m_maxScaleX, m_minScaleY, m_maxScaleY, m_minScaleZ, m_maxScaleZ);
    Vector orientation = randomVector(-1, 1, -1, 1, -1, 1);
    std::unique_ptr<Object> object;
    Point position_2 = randomVector(position.x() - 2, position.x() + 2, position.y() - 2, position.y() + 2,
                                    position.z() - 2, position.z() + 2);
    Point position_3 = randomVector(position.x() - 2, position.x() + 2, position.y() - 2, position.y() + 2,
                                    position.z() - 2, position.z() + 2);
    switch (type) {
        case CYLINDER:
            generateCylinder(position, orientation, scale, color, object);
            break;
        case RECTANGLE:
            generateRectangle(position, orientation, scale, color, object);
            break;
        case SPHERE:
            generateSphere(position, orientation, scale, color, object);
            break;
        case TRIANGLE:
            generateTriangle(position, position_2, position_3, color, object);
            break;
        case CONE:
            generateCone(position, orientation, scale, color, object);
            break;
        case LIGHT:
            generateSpotLight(position, color, object);
            break;
        case CAMERA:
            generateCamera(object);
            break;
//        default:
//            break;
    }
    objects.emplace_back(std::move(object));
}


void ShapeGenerator::generateSpotLight(const Point position, const Vector color, std::unique_ptr<Object>& object) {
    object.reset(new Light(position, color));
    std::cout << " Light " << std::endl
    << " Position = " << position << std::endl
    << " Color = " << color << std::endl;
    std::cout << " -------------------- " << std::endl;

}

void ShapeGenerator::generateCamera(std::unique_ptr<Object>& object) {

    object.reset(new Camera(m_depth, m_positionCamera, m_orientationCamera));
//    object.reset(new Camera(m_depth, Vector(0, 0, 0), Vector(1, 1, 1)));

//    std::cout << " Camera " << std::endl
//    << " Position = " << position << std::endl
//    << " Orientation = " << orientation << std::endl;
}



























