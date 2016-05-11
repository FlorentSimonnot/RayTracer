//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#include <ostream>

class Matrice;

class Vector {    
private:
    float m_x, m_y, m_z;

public:
    Vector();
    Vector(float x, float y, float z);
    virtual ~Vector();

    float x() const;
    float y() const;
    float z() const;

    float norm() const;
    float produitScalaire(Vector const& o) const;

    Vector& operator=(Vector const& o);

    Vector operator+(Vector const& o) const;
    Vector operator-(Vector const& o) const;
    Vector operator*(Vector const& o) const;
    Vector operator*(float f) const;

    Vector& operator+=(Vector const& o);
    Vector& operator-=(Vector const& o);
    Vector& operator*=(Vector const& o);
    Vector& operator*=(float f);
    Vector& operator-();

    bool operator==(Vector const& o) const;
    bool operator!=(Vector const &o) const;
    operator std::string() const;

    Vector crossProduct(Vector const& o) const;

    Vector rotationVector(float angle, Vector const& axe) const;

    float calculAngle(Vector const& o) const;
};

Vector operator*(float f, Vector const& v);

#endif //PROJECT_VECTOR_H
