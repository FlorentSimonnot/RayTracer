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
        Vector axe_norm = axe * (1.f / axe.norm());
        float s = (float) sin(angle);
        float c = (float) cos(angle);

//        Vector v1(c + (1 - c) * axe_norm.x() * axe_norm.x(),
//                  (1 - c) * axe_norm.x() * axe_norm.y() - s * axe_norm.z(),
//                  (1 - c) * axe_norm.x() * axe_norm.z() + axe_norm.y() * s);
//
//        Vector v2((1 - c) * axe_norm.x() * axe_norm.y() + s * axe_norm.z(),
//                  c + (1 - c) * axe_norm.y() * axe_norm.y(),
//                  (1 - c) * axe_norm.y() * axe_norm.z() - s * axe_norm.x());
//
//        Vector v3((1 - c) * axe_norm.x() * axe_norm.z() - s * axe_norm.y(),
//                  (1 - c) * axe_norm.y() * axe_norm.z() + s * axe_norm.x(),
//                  c + (1 - c) * axe_norm.z() * axe_norm.z());

//        float s = (float) sin(angle);
//        float c = (float) cos(angle);
//
//        Vector v1(c + (1 - c) * axe.x() * axe.x(),
//                  (1 - c) * axe.x() * axe.y() - s * axe.z(),
//                  (1 - c) * axe.x() * axe.z() + axe.y() * s);
//
//        Vector v2((1 - c) * axe.x() * axe.y() + s * axe.z(),
//                  c + (1 - c) * axe.y() * axe.y(),
//                  (1 - c) * axe.y() * axe.z() - s * axe.x());
//
//        Vector v3((1 - c) * axe.x() * axe.z() - s * axe.y(),
//                  (1 - c) * axe.y() * axe.z() + s * axe.x(),
//                  c + (1 - c) * axe.z() * axe.z());


        // Ligne et colonne inverser
        Vector v1(c + (1 - c) * axe_norm.x() * axe_norm.x(),
                  (1 - c) * axe_norm.x() * axe_norm.y() + s * axe_norm.z(),
                  (1 - c) * axe_norm.x() * axe_norm.z() - s * axe_norm.y());

        Vector v2((1 - c) * axe_norm.x() * axe_norm.y() - s * axe_norm.z(),
                  c + (1 - c) * axe_norm.y() * axe_norm.y(),
                  (1 - c) * axe_norm.y() * axe_norm.z() + s * axe_norm.x());

        Vector v3((1 - c) * axe_norm.x() * axe_norm.z() + axe_norm.y() * s,
                  (1 - c) * axe_norm.y() * axe_norm.z() - s * axe_norm.x(),
                  c + (1 - c) * axe_norm.z() * axe_norm.z());

        m_ligne1 = v1;
        m_ligne2 = v2;
        m_ligne3 = v3;
    }
}

Matrice::Matrice(Vector const& v1, Vector const& v2)
        : Matrice(v1.calculAngle(v2), v2.crossProduct(v1)) {
    float angle = v1.calculAngle(v2);
    if (v2.rotationVector(*this) != v1) {
        *this = Matrice(-angle, v2.crossProduct(v1));
    }
}

Matrice::Matrice(Vector const& v1, Vector const& v2, Vector const& v3)
        : m_ligne1(v1), m_ligne2(v2), m_ligne3(v3) {
}

Matrice Matrice::inverseMatrix() {

//    Vector v1(m_ligne2.y() * m_ligne3.z() - m_ligne2.z() * m_ligne3.y(),
//              m_ligne2.z() * m_ligne3.x() - m_ligne3.z() * m_ligne2.x(),
//              m_ligne2.x() * m_ligne3.y() - m_ligne2.y() * m_ligne3.x());
//
//    Vector v2(m_ligne3.y() * m_ligne1.z() - m_ligne3.z() * m_ligne1.y(),
//              m_ligne3.z() * m_ligne1.x() - m_ligne1.z() * m_ligne3.x(),
//              m_ligne3.x() * m_ligne1.y() - m_ligne3.y() * m_ligne1.x());
//
//    Vector v3(m_ligne1.y() * m_ligne2.z() - m_ligne1.z() * m_ligne2.y(),
//              m_ligne1.z() * m_ligne2.x() - m_ligne1.x() * m_ligne2.z(),
//              m_ligne1.x() * m_ligne2.y() - m_ligne1.y() * m_ligne2.x());

    Vector v1(m_ligne2.y() * m_ligne3.z() - m_ligne2.z() * m_ligne3.y(),
              m_ligne3.y() * m_ligne1.z() - m_ligne3.z() * m_ligne1.y(),
              m_ligne1.y() * m_ligne2.z() - m_ligne1.z() * m_ligne2.y()
    );

    Vector v2(m_ligne2.z() * m_ligne3.x() - m_ligne3.z() * m_ligne2.x(),
              m_ligne3.z() * m_ligne1.x() - m_ligne1.z() * m_ligne3.x(),
              m_ligne1.z() * m_ligne2.x() - m_ligne1.x() * m_ligne2.z()
    );

    Vector v3(m_ligne2.x() * m_ligne3.y() - m_ligne2.y() * m_ligne3.x(),
              m_ligne3.x() * m_ligne1.y() - m_ligne3.y() * m_ligne1.x(),
              m_ligne1.x() * m_ligne2.y() - m_ligne1.y() * m_ligne2.x()

    );


    return Matrice(v1, v2, v3);
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

