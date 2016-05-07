//
// Created by Narex on 05/05/2016.
//


#include "Scene.hpp"

Scene::Scene() : m_width(1280), m_height(720), m_depth(100) { }

Scene::Scene(float width, float height, float depth)
        : m_width(width), m_height(height), m_depth(depth) { }

Scene::~Scene() { }

void Scene::constructionArbreSpherEnglobant() {


//    Object *tempo;
//    // Copy de la liste des objets
//    memcpy(&tempo,&m_objets, sizeof(m_objets));
//
//    float listAxe[] = {m_width,m_height,m_depth};
//    for(float axe:listAxe){
//
//        qsort(tempo, sizeof(tempo),sizeof(int),compare);
//        for(int i=0;i<axe;i++){
//
//        }
//
//    }
}

int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}