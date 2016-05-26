//
// Created by Narex on 05/04/2016.
//

#include "Vector.hpp"
#include <cmath>

#include "Matrice.hpp"

#define FLOAT_EQ(a, b) (fabs(a - b) < 0.00001f)
#define FLOAT_NOT_EQ(a, b) (fabs(a - b) > 0.00001f)

Vector::Vector()
        : m_x(0.f), m_y(0.f), m_z(0.f) {
}

Vector::Vector(float x, float y, float z)
        : m_x(x), m_y(y), m_z(z) {
}

Vector::Vector(Vector const &v)
        : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z) {
}

Vector::~Vector() {
}

float Vector::x() const {
    return m_x;
}

float Vector::y() const {
    return m_y;
}

float Vector::z() const {
    return m_z;
}

float Vector::norm() const {
    return (float) sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

float Vector::produitScalaire(Vector const& o) const {
    return m_x * o.m_x + m_y * o.m_y + m_z * o.m_z;
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

Vector::operator std::string() const {
    return '(' + std::to_string(m_x) + ", " + std::to_string(m_y) + ", " + std::to_string(m_z) + ')';
}

bool Vector::operator==(Vector const& o) const {
    return FLOAT_EQ(m_x, o.m_x) && FLOAT_EQ(m_y, o.m_y) && FLOAT_EQ(m_z, o.m_z);
}

bool Vector::operator!=(Vector const& o) const {
    return FLOAT_NOT_EQ(m_x, o.m_x) || FLOAT_NOT_EQ(m_y, o.m_y) || FLOAT_NOT_EQ(m_z, o.m_z);
}

Vector Vector::crossProduct(Vector const& o) const {
    return Vector(m_y * o.z() - m_z * o.y(),
                  m_z * o.x() - m_x * o.z(),
                  m_x * o.y() - m_y * o.x());
}

Vector Vector::rotationVector(float angle, Vector const& axe) const {

    Matrice rotation(angle, axe);
    float x = this->produitScalaire(rotation.getLigne1());
    float y = this->produitScalaire(rotation.getLigne2());
    float z = this->produitScalaire(rotation.getLigne3());

    return Vector(x, y, z);
}

Vector Vector::rotationVector(Matrice const& rotation) const {
    float x = this->produitScalaire(rotation.getLigne1());
    float y = this->produitScalaire(rotation.getLigne2());
    float z = this->produitScalaire(rotation.getLigne3());
    return Vector(x, y, z);
}

Vector Vector::operator-() {
    return (Vector(-m_x, -m_y, -m_z));
}

float Vector::calculAngle(Vector const& o) const {
    if (*this == Vector(0, 0, 0) || o == Vector(0, 0, 0)) {
        return 0;
    }
    return acosf(this->produitScalaire(o) / (this->norm() * o.norm()));
}

void Vector::setX(float v) {
    this->m_x = v;
}

void Vector::setY(float v) {
    this->m_y = v;
}

void Vector::setZ(float v) {
    this->m_z = v;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << '(' << v.m_x;
    out << ", " << v.m_y;
    out << ", " << v.m_z << ')';
    return out;
}

