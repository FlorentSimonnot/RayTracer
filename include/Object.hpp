//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJECT_HPP
#define PROJECT_OBJECT_HPP

#include <string>

class Object {    
public:
    Object();
    Object(Object const& o);
    virtual ~Object();

    virtual operator std::string() const = 0;
};

#endif //PROJECT_OBJECT_HPP
