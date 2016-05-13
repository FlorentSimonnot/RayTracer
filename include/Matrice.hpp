//
// Created by Narex on 08/05/2016.
//

#ifndef SYNTHESE_IMAGE_MATRICE_HPP
#define SYNTHESE_IMAGE_MATRICE_HPP

#include "Vector.hpp"

class Matrice {
private:
    Vector m_ligne1, m_ligne2, m_ligne3;
    Matrice(Vector const& v1, Vector const& v2,Vector const& v3);
public:

    Matrice(float angle, Vector const& axe);

    Matrice(Vector const& v1, Vector const& v2);

    ~Matrice();

    Matrice inverseMatrix();

    Vector getLigne1() const;

    Vector getLigne2() const;

    Vector getLigne3() const;


};


#endif //SYNTHESE_IMAGE_MATRICE_HPP
