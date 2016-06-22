//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_MATERIAUX_HPP
#define PROJECT_MATERIAUX_HPP

#include "Ray.hpp"
#include "Point.hpp"
#include "Object.hpp"

/**
 * Pour determiner le type de matiere d'un objet , afin de savoir comment la lumiere va etre reflechis
 */

class Materiaux : public Object {

private:

    std::string m_nom;

    float m_coefReflection;
    /* coefficient de reflection */

    float m_indiceRefraction;
    /* indice de refraction du materiaux */

    float m_brillance;
    /* brillance du materiaux*/

    float m_transparence;

public:

    Materiaux();

    Materiaux(Materiaux const& m);

    Materiaux(std::string m_nom, float m_coefReflection, float m_indiceRefraction, float m_brillance,
              float transparence);

    ~Materiaux();

    Materiaux& operator=(Materiaux const& m);

    bool operator==(Materiaux const& m);

    bool operator!=(Materiaux const& m);

    void valueVerification();

    void setIndiceRefraction(float v);

    void setBrillance(float v);

    void setTransparence(float v);

    std::string getName() const;

    float getCoefReflection() const;

    float getIndiceRefraction() const;

    float getBrillance() const;

    float getTransparence() const;

//    bool rayonReflechi(Ray const& r, Point origin, Vector normale, Ray& rayonReflechi);
};


#endif //PROJECT_MATERIAUX_HPP
