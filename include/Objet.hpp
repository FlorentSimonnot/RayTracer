//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJET_HPP
#define PROJECT_OBJET_HPP

#include "Point.hpp"
#include "Ray.hpp"

class Objet {
private:
    double epsilon; /* Pour corriger approximation de calcul */
    int color_;
    double coefReflection;/* coefficient de reflection */

    double coefReflectionInv;/* 1 - coefReflection */

    double indiceRefraction;/* indice de refraction de l'objet */

    double brillance;        /* brillance de l'objet*/

public:
    Objet(void);

    ~Objet();

    void setColor(int color);
    void setIndiceRefraction(double v);
    void setBrillance(double v);

    double getEpsilon();
    double getBrillance();
    double getIndiceRefraction();

    int getColor();

};

#endif //PROJECT_OBJET_HPP
