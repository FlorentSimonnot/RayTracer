//
// Created by Narex on 05/05/2016.
//

#include "../include/Materiaux.hpp"

Materiaux::Materiaux() :
        m_nom("Default"),
        m_coefReflection(1.0),
        m_indiceRefraction(1.0),
        m_brillance(1.0),
        m_transparence(1.0) { }

Materiaux::Materiaux(const Materiaux& m) :
        m_nom(m.m_nom),
        m_coefReflection(m.m_coefReflection),
        m_indiceRefraction(m.m_indiceRefraction),
        m_brillance(m.m_brillance),
        m_transparence(m.m_brillance) { }

Materiaux::Materiaux(std::string m_nom,
                     float m_coefReflection,
                     float m_indiceRefraction,
                     float m_brillance,
                     float transparence) :
        m_nom(m_nom),
        m_coefReflection(m_coefReflection),
        m_indiceRefraction(m_indiceRefraction),
        m_brillance(m_brillance),
        m_transparence(transparence) {

    valueVerification();
}

void Materiaux::valueVerification() {
    if (m_transparence > 100) {
        m_transparence = 100;
    }
    if (m_transparence < 0) {
        m_transparence = 0;
    }

    if (m_indiceRefraction > 100) {
        m_indiceRefraction = 100;
    }
    if (m_indiceRefraction < 0) {
        m_indiceRefraction = 0;
    }

    if (m_brillance > 100) {
        m_brillance = 100;
    }
    if (m_brillance < 0) {
        m_brillance = 0;
    }

    if (m_coefReflection > 100) {
        m_coefReflection = 100;
    }
    if (m_coefReflection < 0) {
        m_coefReflection = 0;
    }

    m_transparence /= 100;
    m_indiceRefraction /= 100;
    m_brillance /= 100;
    m_coefReflection /= 100;
}

Materiaux::~Materiaux() { }


Materiaux& Materiaux::operator=(const Materiaux& m) {
    this->m_nom = m.m_nom;
    this->m_brillance = m.m_brillance;
    this->m_coefReflection = m.m_coefReflection;
    this->m_indiceRefraction = m.m_indiceRefraction;
    this->m_transparence = m.m_transparence;
    return (*this);
}

// TODO Eventuellement ajouter test sur la couleur
bool Materiaux::operator!=(const Materiaux& m) {
    return this->m_brillance != m.m_brillance ||
           this->m_coefReflection != m.m_coefReflection ||
           this->m_indiceRefraction != m.m_indiceRefraction ||
           this->m_transparence != m.m_transparence ||
           this->m_nom != m.m_nom;
}

bool Materiaux::operator==(const Materiaux& m) {
    return this->m_brillance == m.m_brillance &&
           this->m_coefReflection == m.m_coefReflection &&
           this->m_indiceRefraction == m.m_indiceRefraction &&
           this->m_transparence == m.m_transparence &&
           this->m_nom == m.m_nom;
}

void Materiaux::setIndiceRefraction(float v) {
    this->m_indiceRefraction = v;
}

void Materiaux::setBrillance(float v) {
    this->m_brillance = v;
}

std::string Materiaux::getName() const {
    return m_nom;
}

float Materiaux::getCoefReflection() const {
    return m_coefReflection;
}

float Materiaux::getBrillance() const {
    return m_brillance;
}

float Materiaux::getIndiceRefraction() const {
    return m_indiceRefraction;
}

//bool Materiaux::rayonReflechi(Ray const& r, Point origin, Vector normale, Ray& rayonReflechi) {
//
//    Vector direction;
//    if (m_coefReflection == 0) {
//        return false;
//    }
//    rayonReflechi.setOrigin(origin);
//
//    direction = r.getDirection();
//
////    Vector newDir(direction.x() - 2 * r.getDirection().produitScalaire(normale) * normale.x(),
////                  direction.y() - 2 * r.getDirection().produitScalaire(normale) * normale.y(),
////                  direction.z() - 2 * r.getDirection().produitScalaire(normale) * normale.z()
////    );
//
//    Vector newDir(direction - 2 * r.getDirection().produitScalaire(normale) * normale);
//
//    rayonReflechi.setDirection(newDir);
//
//    return true;
//
//}






