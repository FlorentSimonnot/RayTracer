//
// Created by Narex on 08/05/2016.
//
// TODO finir le fichier
#include "Matrice.hpp"

Matrice::Matrice() { }

Matrice::Matrice(Vector const& v1, Vector const& v2, Vector const& v3)
        : m_col1(v1),
          m_col2(v2),
          m_col3(v3) { }

Matrice Matrice::createMatriceRotation(float angle, Vector const& axe) {

}

Matrice Matrice::getRotationMatrix(Vector const& axe) const {


    return Matrice();
}

