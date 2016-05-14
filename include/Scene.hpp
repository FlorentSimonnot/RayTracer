//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_SCENE_HPP
#define PROJECT_SCENE_HPP

#include "Camera.hpp"
#include <vector>
#include <memory>

class Ray;
class Shape;
class Object;
class Camera;
class Light;

/// Carateristique d'une primitive en un point donné
struct MaterialPoint{
    /// Normale de la primitive en un point
    Vector m_normal;
    /// Couleur du point
    Vector m_color;
    /// "Couleur" de la réflexion
    Vector m_reflect;
};

class Scene {
private:
	std::vector<std::unique_ptr<Object>> m_objects;
    std::vector<Shape*> m_shapes;
    std::vector<Light*> m_lights;

    Camera* m_camera;

    bool testCollision(const Ray& ray, float dist) const;
public:
    Scene(std::vector<std::unique_ptr<Object>>& objects);
    ~Scene();

    Shape const *getFirstCollision(Ray const& ray, float depth,float &distHit) const;

    Vector computColor(Point const& p,MaterialPoint &caracteristics) const;

    void constructionArbreSpherEnglobant();

    std::vector<Shape *> getShapes() const ;

    Camera const& getCamera() const;

    void moveCamera(Vector const& dv);
    void rotateCamera();

};


#endif //PROJECT_SCENE_HPP
