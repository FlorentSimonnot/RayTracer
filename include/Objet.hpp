//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_OBJET_HPP
#define PROJECT_OBJET_HPP

#include "Ray.hpp"


// TODO
class Objet{

//private:
//    Color color; // Se servir de la couleur definit dans la librairie graphique
public:
//    Objet(void);
//    Objet(const Objet &c);
    virtual ~Objet();
    virtual Objet operator=(const Objet &p);
    virtual bool intersect(Ray &ray, float &dist);

//    virtual void computeColorNormal(Ray &ray, float dist, Color &color, Vector3df &normal);
};


#endif //PROJECT_OBJET_HPP
