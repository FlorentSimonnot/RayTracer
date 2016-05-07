//
// Created by Narex on 05/04/2016.
//

#include "Cylinder.hpp"
#include <cmath>
#include <limits>



Cylinder::Cylinder()
        : Shape() {
}


Cylinder::Cylinder(Vector const& position, Vector const& rotation, Vector const& scale)
:   Shape(position, rotation, scale)
{

}

Cylinder::~Cylinder() {
}

float Cylinder::getRadius() {
    return m_scale.x();
}

float Cylinder::getHeight() {
    return m_scale.z();
}

Cylinder::operator std::string() const {
    return "cylinder => " + Shape::operator std::string();
}

// Cylindre avec sa hauteur sur l'axe des X
// TODO A finir
bool Cylinder::intersect(const Ray& ray, float& dist) {
    Vector ray_dir(0, ray.getDirection().y(), ray.getDirection().x());
    Vector ray_or(0, ray.getOrigin().y(), ray.getOrigin().x());

    float a = ray_dir.produitScalaire(ray_dir);
    float b = ray_dir.produitScalaire(ray_or);
    float c = ray_or.produitScalaire(ray_or) - getRadius() * getRadius();

    float delta = b * b - 4 * a * c;

    if (delta < 0) {
        dist = std::numeric_limits<float>::max();;// TODO Mettre une grande valeur ou rien du tout
    }
    else if (delta == 0) {

    }

    else {
        float t1 = (float) (-b + sqrt(delta)) / a;
        float t2 = (float) (-b - sqrt(delta)) / a;
        float t = 0;

        if ((t1 <= t2 && t1 > std::numeric_limits<float>::epsilon()) ||
            (t2 < t1 && t2 < std::numeric_limits<float>::epsilon())) {
            t = t1;
        } else if ((t2 < t1 && t2 > std::numeric_limits<float>::epsilon()) ||
                   (t1 < t2 && t1 < std::numeric_limits<float>::epsilon())) {
            t = t2;
        }

        //TODO Peut etre A changer
        Point p = t * ray.getDirection() + ray.getOrigin();
        dist = p.distance(ray.getOrigin());
    }


    // Code source trouve en ligne
//    if (delta < 0)    {
//        d = MAXDOUBLE;
//        if ((pos2[1] * pos2[1] + pos2[2] * pos2[2]) < (leRayon * leRayon))	{
//            if (((longueur != 0.0))&& (pos2[0] > longueur || (pos2[0] >= 0.0 && pos2[0] < longueur))) {
//                if (dir2[0] != 0){
//                    t = (longueur - pos2[0]) / dir2[0];
//                    p[0] = longueur;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon)&& ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)){
//                        d = distance (p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//            if (((longueur != 0.0))&& (pos2[0] < 0.0 || (pos2[0] > 0.0 && pos2[0] <= longueur))){
//                if (dir2[0] != 0){
//                    t = (0.0 - pos2[0]) / dir2[0];
//                    p[0] = 0.0;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon) && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)){
//                        d = distance (p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//        }
//    }
//    else{
//        t1 = (-b + sqrt (delta)) / a;
//        t2 = (-b - sqrt (delta)) / a;
//        if (t1 <= epsilon && t2 <= epsilon)
//            d = MAXDOUBLE;
//        else{
//            if ((t1 <= t2 && t1 > epsilon) || (t2 < t1 && t2 < epsilon))
//                t = t1;
//            else if ((t2 < t1 && t2 > epsilon) || (t1 < t2 && t1 < epsilon))
//                t = t2;
//
//            p[0] = t * dir2[0] + pos2[0];
//            p[1] = t * dir2[1] + pos2[1];
//            p[2] = t * dir2[2] + pos2[2];
//            p[3] = 1.0;
//            d = distance (p, pos2);
//
//            if (((longueur != 0.0)) && (p[0] > longueur)|| (pos2[0] > longueur && (pos2[1] * pos2[1] + pos2[2] * pos2[2]) <= (leRayon * leRayon))){
//                if (dir2[0] != 0){
//                    t = (longueur - pos2[0]) / dir2[0];
//                    p[0] = longueur;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon) && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)){
//                        d = distance (p, pos2);
//                    }
//                    else
//                        d = MAXDOUBLE;
//                }
//                else
//                    d = MAXDOUBLE;
//            }
//
//            if (((longueur != 0.0)) && (p[0] < 0.0) || (pos2[0] < 0  && (pos2[1] * pos2[1] + pos2[2] * pos2[2]) <=  (leRayon * leRayon)))	{
//                if (dir2[0] != 0){
//                    t = (0.0 - pos2[0]) / dir2[0];
//                    p[0] = 0.0;
//                    p[1] = t * dir2[1] + pos2[1];
//                    p[2] = t * dir2[2] + pos2[2];
//                    p[3] = 1.0;
//                    if ((t > epsilon) && ((p[1] * p[1] + p[2] * p[2]) <= leRayon * leRayon)){
//                        d = distance (p, pos2);
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
