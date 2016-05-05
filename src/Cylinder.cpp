//
// Created by Narex on 05/04/2016.
//

#include "Cylinder.hpp"
#include <cmath>


Cylinder::Cylinder()
        : m_center(), m_radius(1.f), m_height(1.f) {
}

Cylinder::Cylinder(Point const &center, float radius, float height)
        : m_center(center), m_radius(radius), m_height(height) {
}

Cylinder::~Cylinder() {
}

float Cylinder::getRadius() {
    return m_radius;
}

float Cylinder::getHeight() {
    return m_height;
}

// Cylindre avec sa hauteur sur l'axe des X
bool Cylinder::intersect(Ray &ray, float &dist) {
    Vector ray_dir(0, ray.getDirection().y(), ray.getDirection().x());
    Vector ray_or(0, ray.getOrigin().y(), ray.getOrigin().x());

    float a = ray_dir.produitScalaire(ray_dir);
    float b = ray_dir.produitScalaire(ray_or);
    float c = ray_or.produitScalaire(ray_or) - m_radius * m_radius;

    float delta = b * b - 4 * a * c;

    if (delta < 0) {


    }
    else if (delta == 0) {

    }

    else {
        float t1 = (float) (-b + sqrt(delta)) / a;
        float t2 = (float) (-b - sqrt(delta)) / a;
    }


    // Code source trouve en ligne
//    if (delta < 0) {
//        d = MAXDOUBLE;
//        if ((pos2[1] * pos2[1] + pos2[2] * pos2[2]) < (leRayon * leRayon)) {
//            if (((longueur != 0.0))
//                && (pos2[0] > longueur
//                    || (pos2[0] >= 0.0 && pos2[0] < longueur))) {
//                if (dir2[0] != 0) {
//                    t = (longueur - pos2[0]) / dir2[0];
//                    p[0] = longueur;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon)
//                        && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)) {
//                        d = distance(p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//
//            if (((longueur != 0.0))
//                && (pos2[0] < 0.0 || (pos2[0] > 0.0 && pos2[0] <= longueur))) {
//                if (dir2[0] != 0) {
//                    t = (0.0 - pos2[0]) / dir2[0];
//                    p[0] = 0.0;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon)
//                        && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)) {
//                        d = distance(p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//        }
//    }
//    else {
//        t1 = (-b + sqrt(delta)) / a;
//        t2 = (-b - sqrt(delta)) / a;
//
//        if (t1 <= epsilon && t2 <= epsilon)
//            d = MAXDOUBLE;
//        else {
//            if ((t1 <= t2 && t1 > epsilon) || (t2 < t1 && t2 < epsilon))
//                t = t1;
//            else if ((t2 < t1 && t2 > epsilon) || (t1 < t2 && t1 < epsilon))
//                t = t2;
//
//            p[0] = t * dir2[0] + pos2[0];
//            p[1] = t * dir2[1] + pos2[1];
//            p[2] = t * dir2[2] + pos2[2];
//            p[3] = 1.0;
//            d = distance(p, pos2);
//
//            if (((longueur != 0.0)) && (p[0] > longueur) ||
//                (pos2[0] > longueur && (pos2[1] * pos2[1] + pos2[2] * pos2[2]) <= (leRayon * leRayon))) {
//                if (dir2[0] != 0) {
//                    t = (longueur - pos2[0]) / dir2[0];
//                    p[0] = longueur;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon)
//                        && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)) {
//                        d = distance(p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//
//            if (((longueur != 0.0)) && (p[0] < 0.0)
//                || (pos2[0] < 0
//                    && (pos2[1] * pos2[1] + pos2[2] * pos2[2]) <=
//                       (leRayon * leRayon))) {
//                if (dir2[0] != 0) {
//                    t = (0.0 - pos2[0]) / dir2[0];
//                    p[0] = 0.0;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon)
//                        && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)) {
//                        d = distance(p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//        }
//    }


    return true;
}