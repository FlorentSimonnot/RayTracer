//
// Created by Narex on 05/04/2016.
//

#include "../include/Objet.hpp"

Objet::Objet(void) {
    epsilon = 0.001;
    indiceRefraction = 1.0;
    brillance = 1.0;


}

Objet::~Objet() { }

void Objet::setColor(int color) {
    this->color_ = color;
}

void Objet::setIndiceRefraction(double v) {
    this->indiceRefraction = v;
}

void Objet::setBrillance(double v) {
    this->brillance = v;
}

double Objet::getEpsilon() {
    return epsilon;
}

double Objet::getBrillance() {
    return brillance;
}

double Objet::getIndiceRefraction() {
    return indiceRefraction;
}

int Objet::getColor() {
    return color_;
}

double Objet::getCoefReflection() {
    return coefReflection;
}

bool Objet::rayonReflechi(Ray *r, Point origin, Vector normale, Ray *rayonReflechi) {

    Vector direction;
    if (getCoefReflection() == 0) {
        return false;
    }
    rayonReflechi->setOrigin(i);
    rayonReflechi->setDedans(r->estDedans());

    direction = r->getDirection();
    direction.setX( direction.getX() - 2*r->getDirection().produitScalaire(normale) * normale.getX());
    direction.setY( direction.getY() - 2*r->getDirection().produitScalaire(normale) * normale.getY());
    direction.setZ( direction.getZ() - 2*r->getDirection().produitScalaire(normale) * normale.getZ());

    rayonReflechi->setDirection(direction);

    return true;


}
