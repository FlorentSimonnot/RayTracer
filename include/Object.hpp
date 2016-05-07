//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJECT_HPP
#define PROJECT_OBJECT_HPP

#include "Ray.hpp"
class Object {    
public:
    Object();
    Object(const Object & o);
    virtual ~Object();
};

#endif //PROJECT_OBJECT_HPP
