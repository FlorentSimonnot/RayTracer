//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

class Vector {
private:
    float m_x, m_y, m_z;

public:
    Vector();
    Vector(float x, float y, float z);
    virtual ~Vector();

    Vector& operator=(Vector const& o);

    Vector operator+(Vector const& o) const;
    Vector operator-(Vector const& o) const;
    Vector operator*(Vector const& o) const;
    Vector operator*(float f) const;

    Vector& operator+=(Vector const& o);
    Vector& operator-=(Vector const& o);
    Vector& operator*=(Vector const& o);
    Vector& operator*=(float f);
};

Vector operator*(float f, Vector const& v);

#endif //PROJECT_VECTOR_H
