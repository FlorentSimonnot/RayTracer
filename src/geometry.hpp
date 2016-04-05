//
// Created by narex on 03/04/16.
//

#ifndef PROJECT_GEOMETRY_HPP
#define PROJECT_GEOMETRY_HPP

#include <cmath>

#define SQR(a) a*a
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

// Faire une classe mere de Point et vecteur

class ParentPointVector {
private:
    float x;
    float y;
    float z;
public:
    ParentPointVector();
    ParentPointVector(float x, float y, float z);

    ~ParentPointVector();

    ParentPointVector operator+(const ParentPointVector &p);

    ParentPointVector operator-(const ParentPointVector &p);

    bool operator==(const ParentPointVector &p);

    bool operator!=(const ParentPointVector &p);

    float getX();
    float getY();
    float getZ();
    ParentPointVector operator=(const ParentPointVector &p);
};


class Point : public  ParentPointVector{
private:
    float x;
    float y;
    float z;
public:
    Point(float x, float y, float z);
    ~Point();

    float distance(const Point &p);
    Point operator+(const Point &p);
//    Point addVector(const Vector &v);

//    Point substractVector(const Vector &v);

};

class Vector : public ParentPointVector {
private:
    float x;
    float y;
    float z;
public:
    Vector(float x, float y, float z);

    ~Vector();

    Vector operator*(const Vector &v); // produit vectoriel

    Vector multiBy(float value);

    Vector nullVector();

//    Vector fromPoints(const Point &p, const Point &p2);


};

///////////////////////////////////
class Ray {
private:
    Point origin_;
    Vector direction_;

public:
    Ray(Point &origin, Vector &direction);

    ~Ray();

    Point& getOrigin();

    Vector& getDirection();
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
    Point center_;
    float radius_;

public:
    Sphere(Point center, float radius);

    virtual ~Sphere();

    bool intersect(Ray &ray, float &dist);
    Point& getCenter();

    float getRadius();
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
    Cylinder(float radius, float height);

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
    Rectangle(Point3d &origin, float width, float height);

    virtual ~Rectangle();

    bool intersect(Ray &ray, float &dist);

};


#endif //PROJECT_GEOMETRY_HPP
