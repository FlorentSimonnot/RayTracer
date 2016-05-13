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

class Scene {
private:
	std::vector<std::unique_ptr<Object>> m_objects;
    std::vector<Shape*> m_shapes;
    Camera* m_camera;

public:
    Scene(std::vector<std::unique_ptr<Object>>& objects);
    ~Scene();

    // Return color of the pixel.
    Shape const* getFirstCollision(Ray const& ray,float depth) const;

    void constructionArbreSpherEnglobant();

    std::vector<Shape *> getShapes() const ;

    Camera const& getCamera() const;

    void moveCamera(Vector const& dv);
    void rotateCamera();

};


#endif //PROJECT_SCENE_HPP
