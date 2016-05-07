//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_SCENE_HPP
#define PROJECT_SCENE_HPP

#include "Camera.hpp"
#include "Object.hpp"
#include <vector>
#include <Ray.hpp>
class Scene {
private:
    std::vector<Shape>& m_Shapes;

public:
    Scene();

    Scene(std::vector<Shape>& shapes);
    ~Scene();

    float getFirstCollision(Ray const& ray,float& dist);

    bool addShape(Shape const& shape);

    Shape& getShape(float index);

    void constructionArbreSpherEnglobant();

};


#endif //PROJECT_SCENE_HPP
