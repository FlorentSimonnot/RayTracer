//
// Created by Narex on 05/05/2016.
//

#ifndef PROJECT_SCENE_HPP
#define PROJECT_SCENE_HPP

#include "Camera.hpp"
class Scene {
private:
    Camera camera;

    Object *objets;
public:
    Scene();
    ~Scene();

};


#endif //PROJECT_SCENE_HPP
