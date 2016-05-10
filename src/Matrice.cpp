//
// Created by Narex on 08/05/2016.
//

#include <math.h>
#include "Matrice.hpp"

Matrice::~Matrice() { }

Matrice::Matrice(float angle, Vector const& axe)
        : m_ligne1(1, 0, 0),
          m_ligne2(0, 1, 0),
          m_ligne3(0, 0, 1) {

    if (angle != 0) {
        float s = (float) sin(angle);
        float c = (float) cos(angle);

//        Vector v1(axe.x() * axe.x() + (1 - axe.x() * axe.x()) * c,
//                  axe.x() * axe.y() + (1 - c) - axe.z() * s,
//                  axe.z() * axe.x() * (1 - c) + axe.y() * s);
//
//        Vector v2(axe.x() * axe.y() * (1 - c) + axe.z() * s,
//                  axe.y() * axe.y() + (1 - axe.y() * axe.y()) * c,
//                  axe.y() * axe.z() + (1 - c) - axe.x() * s);
//
//        Vector v3(axe.z() * axe.x() * (1 - c) - axe.y() * s,
//                  axe.y() * axe.z() * (1 - c) + axe.x() * s,
//                  axe.z() * axe.z() + (1 - axe.z() * axe.z()) * c);

        Vector v1(c + (1 - c) * axe.x() * axe.x(),
                  (1 - c) * axe.x() * axe.y() - s * axe.z(),
                  (1 - c) * axe.x() * axe.z() + axe.y() * s);

        Vector v2((1 - c) * axe.x() * axe.y() + s * axe.z(),
                  c + (1 - c) * axe.y() * axe.y(),
                  (1 - c) * axe.y() * axe.z() - s * axe.x());

        Vector v3((1 - c) * axe.x() * axe.z() - s * axe.y(),
                  (1 - c) * axe.y() * axe.z() + s * axe.x(),
                  c + (1 - c) * axe.z() * axe.z());

        m_ligne1 = v1;
        m_ligne2 = v2;
        m_ligne3 = v3;
    }
}

Matrice& Matrice::inverseMatrix() {

    Vector v1(m_ligne2.y() * m_ligne3.z() - m_ligne2.z() * m_ligne3.y(),
              m_ligne2.z() * m_ligne3.x() - m_ligne3.z() * m_ligne2.x(),
              m_ligne2.x() * m_ligne3.y() - m_ligne2.y() * m_ligne3.x());

    Vector v2(m_ligne3.y() * m_ligne1.z() - m_ligne3.z() * m_ligne1.y(),
              m_ligne3.z() * m_ligne1.x() - m_ligne1.z() * m_ligne3.x(),
              m_ligne3.x() * m_ligne1.y() - m_ligne3.y() * m_ligne1.x());

    Vector v3(m_ligne1.y() * m_ligne2.z() - m_ligne1.z() * m_ligne2.y(),
              m_ligne1.z() * m_ligne2.x() - m_ligne1.x() * m_ligne2.z(),
              m_ligne1.x() * m_ligne2.y() - m_ligne1.y() * m_ligne2.x());

    this->m_ligne1 = v1;
    this->m_ligne2 = v2;
    this->m_ligne3 = v3;
    return (*this);
}


Vector Matrice::getLigne1() const {
    return m_ligne1;
}

Vector Matrice::getLigne2() const {
    return m_ligne2;
}

Vector Matrice::getLigne3() const {
    return m_ligne3;
}

