//
// Created by Narex on 05/04/2016.
//

#include "Vector.hpp"


Vector::Vector()
:   m_x(0.f), m_y(0.f), m_z(0.f) 
{
}

Vector::Vector(float x, float y, float z)
:   m_x(x), m_y(y), m_z(z)
{
}

Vector::~Vector() {
}

Vector& Vector::operator=(Vector const& o) {
    m_x = o.m_x;
    m_y = o.m_y;
    m_z = o.m_z;

    return *this;
}

Vector Vector::operator+(Vector const& o) const {
    return Vector(m_x + o.m_x, m_y + o.m_y, m_z + o.m_z);
}

Vector Vector::operator-(Vector const& o) const {
    return Vector(m_x - o.m_x, m_y - o.m_y, m_z - o.m_z);
}

Vector Vector::operator*(Vector const& o) const {
    return Vector(m_x * o.m_x, m_y * o.m_y, m_z * o.m_z);
}

Vector Vector::operator*(float f) const {
    return Vector(m_x * f, m_y * f, m_z * f);
}

Vector& Vector::operator+=(Vector const& o) {
    m_x += o.m_x;
    m_y += o.m_y;
    m_z += o.m_z;

    return *this;
}

Vector& Vector::operator-=(Vector const& o) {
    m_x -= o.m_x;
    m_y -= o.m_y;
    m_z -= o.m_z;

    return *this;    
}

Vector& Vector::operator*=(Vector const& o) {
    m_x *= o.m_x;
    m_y *= o.m_y;
    m_z *= o.m_z;

    return *this;
}

Vector& Vector::operator*=(float f) {
    m_x *= f;
    m_y *= f;
    m_z *= f;

    return *this;    
}

Vector operator*(float f, Vector const& v) {
    return v * f;
}