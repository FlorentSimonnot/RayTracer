//
// Created by Narex on 05/05/2016.
//

#include "../include/Materiaux.hpp"

Materiaux::Materiaux() {

    indiceRefraction = 1.0;
    brillance = 1.0;
    coefReflection = 1.0;
    coefReflectionInv = 1 - coefReflection;

}

Materiaux::~Materiaux() { }


Materiaux Materiaux::operator=(const Materiaux &m) {
    this->brillance = m.brillance;
    this->coefReflection = m.coefReflection;
    this->indiceRefraction = m.indiceRefraction;
    this->coefReflectionInv = m.coefReflectionInv;
    return (*this);
}

// TODO Eventuellement ajouter test sur la couleur
bool Materiaux::operator!=(const Materiaux &m) {
    return this->brillance != m.brillance ||
           this->coefReflection != m.coefReflection ||
           this->indiceRefraction != m.indiceRefraction ||
           this->coefReflectionInv != m.coefReflectionInv;

}

bool Materiaux::operator==(const Materiaux &m) {
    return this->brillance == m.brillance &&
           this->coefReflection == m.coefReflection &&
           this->indiceRefraction == m.indiceRefraction &&
           this->coefReflectionInv == m.coefReflectionInv;
}

void Materiaux::setIndiceRefraction(float v) {
    this->indiceRefraction = v;
}

void Materiaux::setBrillance(float v) {
    this->brillance = v;
}

void Materiaux::setColor(int color) {
    this->color = color;
}

int Materiaux::getColor() {
    return color;
}

float Materiaux::getCoefReflection() {
    return coefReflection;
}

float Materiaux::getCoefReflectionInv() {
    return 1 - coefReflection;
}

float Materiaux::getBrillance() {
    return brillance;
}

float Materiaux::getIndiceRefraction() {
    return indiceRefraction;
}

bool Materiaux::rayonReflechi(Ray &r, Point origin, Vector normale, Ray *rayonReflechi) {

    Vector direction;
    if (getCoefReflection() == 0) {
        return false;
    }
    rayonReflechi->setOrigin(origin);

    direction = r.getDirection();

    Vector newDir(direction.x() - 2 * r.getDirection().produitScalaire(normale) * normale.x(),
                  direction.y() - 2 * r.getDirection().produitScalaire(normale) * normale.y(),
                  direction.z() - 2 * r.getDirection().produitScalaire(normale) * normale.z()
    );
    rayonReflechi->setDirection(newDir);

    return true;

}






