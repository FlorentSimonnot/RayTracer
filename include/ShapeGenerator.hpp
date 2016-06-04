//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
#define SYNTHESE_IMAGE_OBJECTGENERATOR_HPP


#include <vector>

// TODO Ajouter borne min / Max pour chacun des valeurs necessaire
class ShapeGenerator {
private:

    std::vector<Shape *> m_shapes;

    /// Number of each objects ///
    float m_numberObjects; // Nb objects totaux si le nombre d'objet de chaque type non specifié

    float m_numberCylinder;
    float m_numberRectangle;
    float m_numberSphere;
    float m_numberTriangle;
    float m_numberCone;
    float m_numberSpot;

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
    // Color toujours entre 0 et 255 maximum , ou entre ces 2 bornes
    float m_minColorR;
    float m_minColorG;
    float m_minColorB;

    float m_MaxColorR;
    float m_MaxColorG;
    float m_MaxColorB;


    /// Fonctions de generation ///
    Shape* generateCylinder(const Point position, const Vector orientation, const Vector scale, const Vector color);

    Shape* generateRectangle(const Point position, const Vector orientation, const Vector scale, const Vector color);

    Shape* generateSphere(const Point position, const Vector orientation, const Vector scale, const Vector color);

    Shape* generateTriangle(const Point position_1,const Point position_2,const Point position_3,const Vector color);

    Shape* generateCone(const Point position, const Vector orientation, const Vector scale, const Vector color);

    void generateShape(const int type);

    Vector randomVector(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

public:
    ShapeGenerator();

    ShapeGenerator(float numberObjects, float minPosX, float maxPosX, float minPosY, float maxPosY,
                   float minPosZ, float maxPosZ);

//    ShapeGenerator(float numberObjects, float minPosX, float maxPosX, float minPosY, float maxPosY,
//                   float minPosZ, float maxPosZ);

    virtual ~ShapeGenerator();

    std::vector<Shape *> getShapes() const;

    void generate();

};


#endif //SYNTHESE_IMAGE_OBJECTGENERATOR_HPP
