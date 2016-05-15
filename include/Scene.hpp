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



class Scene {
private:
	std::vector<std::unique_ptr<Object>> m_objects;
    std::vector<Shape*> m_shapes;
    std::vector<Light*> m_lights;
    Camera* m_camera;

//    bool testCollision(const Ray& ray, float dist) const;
public:
    Scene(std::vector<std::unique_ptr<Object>>& objects);
    ~Scene();

	Scene(Scene const& s);
	Scene& operator=(Scene const& s);

    Shape const *getFirstCollision(Ray const& ray, float depth,float &distHit) const;

//    Vector computColor(Point const& p,MaterialPoint &caracteristics) const;

    void constructionArbreSpherEnglobant();

    std::vector<Shape*> const& getShapes() const ;
    std::vector<Light*> const& getLights() const ;

    Camera const& getCamera() const;

    void moveCamera(Vector const& dv);
    void rotateCamera();

    void test() const;

};


#endif //PROJECT_SCENE_HPP
