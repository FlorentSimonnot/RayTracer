//
// Created by Narex on 05/04/2016.
//

#include "Cylinder.hpp"

Cylinder::Cylinder() : radius(1), height(1) { }

Cylinder::Cylinder(float radius, float height)
        : radius(radius),
          height(height) { }

Cylinder::~Cylinder() {

}

float Cylinder::getRadius() {
    return radius;
}

float Cylinder::getHeight() {
    return height;
}

// Cylindre avec sa hauteur sur l'axe des X
bool Cylinder::intersect(Ray &ray, float &dist) {

//    float a = SQR(ray.getDirection().y())
//              + SQR(ray.getDirection().z());
//    float b = ray.getDirection().y() * ray.getOrigin().y()
//              + ray.getDirection().z() * ray.getOrigin().z();
//    float c = SQR(ray.getOrigin().y())
//              + SQR(ray.getOrigin().z())
//              - SQR(getRadius());
//
//    float delta = b * b - 4 * a * c;
//
//    if (delta < 0) {
//
//
//    }
//    else if (delta == 0){
//
//    }
//    else{
//        double t1 = (-b + sqrt(delta)) / a;
//        double t2 = (-b - sqrt(delta)) / a;
//    }


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