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
          m_shapes(),
          m_lights(),
          m_camera(nullptr) {
    for (auto& o: m_objects) {
        if (Shape *s = dynamic_cast<Shape *>(o.get())) {
            m_shapes.emplace_back(s);
        } else if (Camera *c = dynamic_cast<Camera *>(o.get())) {
            m_camera = c;
        } else if (Light *l = dynamic_cast<Light *>(o.get())) {
            m_lights.emplace_back(l);
        }
    }

    if (!m_camera) {
        std::cerr << "Warning: no camera has been set." << std::endl;
        exit(1);
    }
}

Scene::~Scene() {
}

Shape const *Scene::getFirstCollision(Ray const& ray, float depth, float& distHit) const {
    float dist;
    Shape const *shape = nullptr;

    distHit = depth;
    for (auto const& s: m_shapes) {
        if (s->getBoundingVolume().intersect(ray, distHit) && s->intersect(ray, dist) && dist < distHit && dist > 0.0001) {
            distHit = dist;
            shape = s;
        }
    }
    return shape;
}

bool Scene::getShadowCollision(Ray const& ray, float depth, Shape const* shape) const {
    float dist;

    for (auto const& s: m_shapes) {
        if (shape != s && s->getBoundingVolume().intersect(ray, depth) && s->intersect_shadow(ray, dist) && dist < depth && dist > 0.0001) {
            return true;
        }
    }
    return false;
}

std::vector<Shape *> const& Scene::getShapes() const {
    return m_shapes;
}

std::vector<Light *> const& Scene::getLights() const {
    return m_lights;
}

void Scene::test() const {
    for (auto const& o: m_objects) {
        std::cout << std::string(*o) << std::endl;
    }
}

//bool Scene::testCollision(const Ray& ray, float dist) const {
//    float t_dist;
//    for (auto const& s: m_shapes) {
//        if (s->intersect(ray, t_dist) && (t_dist > std::numeric_limits<float>::epsilon()) && t_dist < dist) {
//            return true;
//        }
//    }
//    return false;
//}
//
//Vector Scene::computColor(Point const& p, MaterialPoint& caracteristics) const {
//    Vector t_color(0, 0, 0);
//    for (auto const& l: m_lights) {
//        Vector path = l->getCenter() - p;
//        float pathSize = path.norm();
//        path *= (1.f / pathSize);
//        Ray ray(p, path);
//        if (testCollision(ray, pathSize)) {
//            continue;
//        }
//        float cosphi = path.produitScalaire(caracteristics.m_normal);
//        if (cosphi < 0.)
//            continue;
//        t_color += (caracteristics.m_color * cosphi).crossProduct(l->computColor(ray, pathSize));
//    }
//    return t_color;
//}

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

//Scene::Scene(Scene const& s)
//        : m_objects(std::move(s.m_objects)),
//          m_shapes(s.m_shapes),
//          m_lights(s.m_lights),
//          m_camera(s.m_camera) {
//}
//
//Scene& Scene::operator=(Scene const& s) {
////    m_objects = std::move(s.m_objects);
//    m_shapes = s.m_shapes;
//    m_lights = s.m_lights;
//    m_camera = s.m_camera;
//    return *this;
//}