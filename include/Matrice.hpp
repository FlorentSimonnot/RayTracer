//
// Created by Narex on 08/05/2016.
//

#ifndef SYNTHESE_IMAGE_MATRICE_HPP
#define SYNTHESE_IMAGE_MATRICE_HPP

#include "Vector.hpp"
class Matrice {
private:
    Vector m_col1,m_col2,m_col3;

public:
    Matrice();
    Matrice(Vector const& v1,Vector const& v2,Vector const& v3);
    ~Matrice();

    Matrice createMatriceRotation(float angle,Vector const& axe);

    Matrice getRotationMatrix(Vector const& axe) const;

};


#endif //SYNTHESE_IMAGE_MATRICE_HPP
