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

class Scene {
private:
	std::vector<std::unique_ptr<Object>> m_objects;
    std::vector<Shape*> m_shapes;

public:
    Scene();
    Scene(std::vector<std::unique_ptr<Object>>& objects);
    ~Scene();


void test();

    // Return color of the pixel.
    Shape const* getFirstCollision(Ray const& ray,float& dist) const;

    void constructionArbreSpherEnglobant();

};


#endif //PROJECT_SCENE_HPP
