//
// Created by Narex on 05/05/2016.
//



#include <limits>
#include <Shape.hpp>
#include "Scene.hpp"

Scene::Scene() : m_Shapes() { }

Scene::Scene(std::vector<Shape>& shapes) :
        m_Shapes(shapes) { }

Scene::~Scene() {
    for (std::vector<Shape>::const_iterator it = m_Shapes.begin(); it != m_Shapes.end(); ++it)
        delete *it;
}

//
float Scene::getFirstCollision(Ray const& ray, float& dist) {

    float min_dist = std::numeric_limits<float>::max();
    float min_shape = -1;

    for (std::vector<Shape>::iterator it = m_Shapes.begin(); it != m_Shapes.end(); ++it) {
        if ((*it).intersect(ray, dist)) {
            min_shape = it - m_Shapes.begin();
            min_dist = dist;
        }
    }

    if (min_shape == -1)
        return -1;
    else {
        dist = min_dist;
        return min_shape;
    }

}

bool Scene::addShape(Shape const& shape) {

    for (std::vector<Shape>::iterator it = m_Shapes.begin(); it != m_Shapes.end(); ++it) {
        if ((*it) == shape) {
            return false;
        }
    }
    m_Shapes.push_back(shape);
    return true;
}

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