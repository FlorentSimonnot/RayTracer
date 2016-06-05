//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
#define SYNTHESE_IMAGE_OBJECTGENERATOR_HPP


#include <vector>
#include <memory>
#include "Shape.hpp"


enum ObjectType {
    CYLINDER = 0,
    RECTANGLE,
    SPHERE,
    TRIANGLE,
    CONE,
    LIGHT,
    CAMERA
};


class ShapeGenerator {
private:

    /// Number of each objects ///
    int m_numberObjects; // Nb objects totaux si le nombre d'objet de chaque type non specifié

    int m_numberCylinder;
    int m_numberRectangle;
    int m_numberSphere;
    int m_numberTriangle;
    int m_numberCone;
    int m_numberSpot;

    /// Position ///
    float m_minPosX;
    float m_minPosY;
    float m_minPosZ;

    float m_maxPosX;
    float m_maxPosY;
    float m_maxPosZ;

    /// Scale ///
    float m_minScaleX;
    float m_minScaleY;
    float m_minScaleZ;

    float m_maxScaleX;
    float m_maxScaleY;
    float m_maxScaleZ;

    /// Color ///
    int m_minColorR;
    int m_minColorG;
    int m_minColorB;

    int m_maxColorR;
    int m_maxColorG;
    int m_maxColorB;

    /// Camera ///
    Point m_positionCamera;
    Vector m_orientationCamera;
    float m_depth;

private:
/// Fonctions de generation ///
    void generateCylinder(const Point position, const Vector orientation, const Vector scale, const Vector color,
                          std::unique_ptr<Object>& object);

    void generateRectangle(const Point position, const Vector orientation, const Vector scale, const Vector color,
                           std::unique_ptr<Object>& object);

    void generateSphere(const Point position, const Vector orientation, const Vector scale, const Vector color,
                        std::unique_ptr<Object>& object);

    void generateTriangle(const Point position_1, const Point position_2, const Point position_3, const Vector color,
                          std::unique_ptr<Object>& object);

    void generateCone(const Point position, const Vector orientation, const Vector scale, const Vector color,
                      std::unique_ptr<Object>& object);

    void generateShape(const ObjectType type, std::vector<std::unique_ptr<Object>>& objects);

    Vector randomVector(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

    void generateSpotLight(const Point position, const Vector color, std::unique_ptr<Object>& object);

    void testInitValues(); // Test des valeurs donné lors de l'initialisation et les change en cas d'incoherence

    void generateRandomObjects(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllCylinder(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllRectangle(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllSphere(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllTriangle(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllCone(std::vector<std::unique_ptr<Object>>& objects);

    void generateAllSpots(std::vector<std::unique_ptr<Object>>& objects);

    void generateCamera(std::unique_ptr<Object>& object);

    void inverseValue(float& a, float& b);

public:

    ShapeGenerator();

    ShapeGenerator(int numberObject);

    /**
     * Constructeur en indiquant juste le nombre total d'objets et le nombre de spot lumineux
     */
    ShapeGenerator(int numberObjects, int numberSpot,
                   float minPosX, float minPosY, float minPosZ,
                   float maxPosX, float maxPosY, float maxPosZ,
                   float minScaleX, float minScaleY, float minScaleZ,
                   float maxScaleX, float maxScaleY, float maxScaleZ,
                   int minColorR, int minColorG, int minColorB,
                   int maxColorR, int maxColorG, int maxColorB,
                   Point positionCamera, Vector orientationCamera, float depth);

    /**
     * Constructeur en indiquant le nombre de chacun des objets
     */
    ShapeGenerator(int numberCylinder, int numberRectangle, int numberSphere,
                   int numberTriangle, int numberCone, int numberSpot,
                   float minPosX, float minPosY, float minPosZ,
                   float maxPosX, float maxPosY, float maxPosZ,
                   float minScaleX, float minScaleY, float minScaleZ,
                   float maxScaleX, float maxScaleY, float maxScaleZ,
                   int minColorR, int minColorG, int minColorB,
                   int maxColorR, int maxColorG, int maxColorB,
                   Point positionCamera, Vector orientationCamera, float depth);

    virtual ~ShapeGenerator();

    void generate(std::vector<std::unique_ptr<Object>>& objects);
};


#endif //SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
