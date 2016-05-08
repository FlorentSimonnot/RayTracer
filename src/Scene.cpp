//
// Created by Narex on 05/05/2016.
//



#include <limits>
#include <Shape.hpp>
#include <iostream>
#include "Scene.hpp"

Scene::Scene() : m_shapes() { }

Scene::Scene(std::vector<std::unique_ptr<Object>>& objects)
:   m_objects(std::move(objects)), m_shapes()
{
    for (auto& o: m_objects) {
        Shape *s = dynamic_cast<Shape*>(o.get());
        if (s != nullptr) {
            m_shapes.emplace_back(s);
        }
    }
}

Scene::~Scene() {
}

Shape const* Scene::getFirstCollision(Ray const& ray, float& dist) const {
    float min_dist;
    Shape const *shape = nullptr;

    for (auto const& s: m_shapes) {
        if (s->intersect(ray, dist)) {
            if (!shape || min_dist > dist) {
                min_dist = dist;
                shape = s;
            }
        }
    }

    return shape;
}

void Scene::test() {
    for (auto const& s: m_shapes) {
        std::cout << std::string(*s) << std::endl;
    }
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