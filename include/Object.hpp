//
// Created by Narex on 04/05/2016.
//

#ifndef PROJECT_OBJECT_HPP
#define PROJECT_OBJECT_HPP

class Object {
private:
    int color_;

public:
    Object(void);

    Object(const Object &c);

    ~Object();

    void setColor(int color);
    int getColor();

};

#endif //PROJECT_OBJECT_HPP
