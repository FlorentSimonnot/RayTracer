//
// Created by narex on 03/04/16.
//

#ifndef PROJECT_GEOMETRY_HPP
#define PROJECT_GEOMETRY_HPP

#include <cmath>
typedef struct {
    float x;
    float y;
    float z;
} Point3d;

typedef struct {
    float x;
    float y;
    float z;
} Direction3d;

///////////////////////////////////
class Ray {
private:
    Point3d origin_;
    Direction3d direction_; // TODO voir si utiliser vector de libg3x ou non

public:
    Ray(Point3d &origin, Direction3d &direction);

    ~Ray();

    Point3d origin();

    Direction3d direction();
};

/*
class Primitive {
public:
    Primitive();

    virtual ~Primitive();

    virtual bool intersect(Ray &ray, float &dist);

//    virtual void computeColorNormal(Ray &ray, float dist, Color &color, Vector3df &normal);
};*/


///////////////////////////////////

class Sphere {
private:
    Point3d center_;
    float radius_;

public:
    Sphere(Point3d &center, float &radius);

    virtual ~Sphere();

    bool intersect(Ray &ray, float &dist);
};

///////////////////////////////////

class Triangle {
private:
    Point3d point_1_;
    Point3d point_2_;
    Point3d point_3_;

public:
    Triangle(Point3d &point_1, Point3d &point_2, Point3d &point_3);

    virtual ~Triangle();

    bool intersect(Ray &ray, float &dist);

};

///////////////////////////////////

class Cylinder {
private:
    float radius_;
    float height_;


public:
    Cylinder(float radius,float height);

    virtual ~Cylinder();

    bool intersect(Ray &ray, float &dist);

};


///////////////////////////////////

class Rectangle {
private:
    Point3d origin_;
    float width_;
    float height_;

public:
    Rectangle(Point3d &origin,float width,float height);

    virtual ~Rectangle();

    bool intersect(Ray &ray, float &dist);

};


#endif //PROJECT_GEOMETRY_HPP
