//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_MATERIAUX_HPP
#define PROJECT_MATERIAUX_HPP

#include "Ray.hpp"
#include "Point.hpp"

/**
 * Pour determiner le type de matiere d'un objet , afin de savoir comment la lumiere va etre reflechis
 */

class Materiaux {

private:

    float coefReflection;
    /* coefficient de reflection */

    float coefReflectionInv;
    /* 1 - coefReflection */

    float indiceRefraction;
    /* indice de refraction du materiaux */

    float brillance;
    /* brillance du materiaux*/

public:

    Materiaux();

    ~Materiaux();


    Materiaux &operator=(const Materiaux &m);

    bool operator==(const Materiaux &m);

    bool operator!=(const Materiaux &m);

    void setIndiceRefraction(float v);

    void setBrillance(float v);

    float getCoefReflection();

    float getCoefReflectionInv();

    float getIndiceRefraction();

    float getBrillance();

    bool rayonReflechi(Ray &r, Point origin, Vector normale, Ray *rayonReflechi);
};


#endif //PROJECT_MATERIAUX_HPP
