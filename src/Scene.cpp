//
// Created by Narex on 05/05/2016.
//



#include <limits>
#include <Shape.hpp>
#include <iostream>
#include "Scene.hpp"
#include "Light.hpp"

Scene::Scene(std::vector<std::unique_ptr<Object>>& objects)
        : m_objects(std::move(objects)),
          m_shapes(), m_lights(),
          m_camera(nullptr) 
{
    for (auto& o: m_objects) {
        Shape *s = dynamic_cast<Shape *>(o.get());
        if (s != nullptr) {
            m_shapes.emplace_back(s);

        } else {
            Camera *c = dynamic_cast<Camera*>(o.get());
            if (c != nullptr) {
                m_camera = c;

            } else {
                Light *l = dynamic_cast<Light *>(o.get());
                if( l != nullptr ){
                    m_lights.emplace_back(l);
                }

            }
        }
    }

    if (!m_camera) {
        std::cerr << "Warning: no camera has been set." << std::endl;
    }
}

Scene::~Scene() {
}

Shape const *Scene::getFirstCollision(Ray const& ray, float depth) const {
    float min_dist = std::numeric_limits<float>::max(), dist;
    Shape const *shape = nullptr;

    for (auto const& s: m_shapes) {
        if (s->intersect(ray, dist)) {
            if ((!shape || (min_dist > dist && (dist > std::numeric_limits<float>::epsilon())))
                && dist <= depth) {
                min_dist = dist;
                shape = s;
//                std::cout << "type ID = " << typeid(s).name() << std::endl;
            }
        }
    }

    return shape;
}

std::vector<Shape*> const& Scene::getShapes() const {
    return m_shapes;
}

std::vector<Light*> const& Scene::getLights() const {
    return m_lights;
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

Camera const& Scene::getCamera() const {
    return *m_camera;
}

void Scene::moveCamera(Vector const& dv) {
    m_camera->setPosition(m_camera->position() + dv);
}

void Scene::rotateCamera() {
    //TODO
}