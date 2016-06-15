//
// Created by Narex on 07/05/2016.
//

#include "Matrice.hpp"
#include "Camera.hpp"

Camera::Camera()
        : m_depth(10),
          m_position(0, 0, 0),
          m_orientation(1, 0, 0),
          m_orientation_down(),
          m_orientation_right() {
    updateOrientation();
}

Camera::Camera(Point const& position, Vector const& orientation)
        : m_depth(10),
          m_position(position),
          m_orientation(orientation),
          m_orientation_down(),
          m_orientation_right() {
    updateOrientation();
}

Camera::Camera(float depth, Point const& position, Vector const& orientation)
        : m_depth(depth),
          m_position(position),
          m_orientation(orientation),
          m_orientation_down(),
          m_orientation_right() {

    updateOrientation();

}

Camera::~Camera() { }

Camera::operator std::string() const {
    return "camera";
}

void Camera::updateOrientation() {
    if (m_orientation.x() || m_orientation.y()) {
        m_orientation_right = Vector(-m_orientation.y(), m_orientation.x(), 0);
    } else {
        m_orientation_right = Vector(1, 0, 0);
    }
    m_orientation_down = m_orientation.crossProduct(m_orientation_right);
    if (m_orientation_down.z() < 0) {
        m_orientation_down = -m_orientation_down;
        m_orientation_right = -m_orientation_right;
    }
    // TODO Ajouter la possibilite de voir en biais
}
//float Camera::getFov() {
//    return m_fov;
//}

//float Camera::width() {
//    return m_width;
//}
//
//float Camera::height() {
//    return m_height;
//}

float Camera::depth() const {
    return m_depth;
}

Point Camera::position() const {
    return m_position;
}

Vector Camera::orientation() const {
    return m_orientation;
}

Vector Camera::orientation_down() const {
    return m_orientation_down;
}


Vector Camera::orientation_right() const {
    return m_orientation_right;
}
//void Camera::setFov(float val) {
//    m_fov = val;
//}

void Camera::setDepth(float val) {
    m_depth = val;
}

void Camera::setPosition(Point position) {
    m_position = position;
}

void Camera::setOrientation(Vector orientation) {
    m_orientation = orientation;
}

void Camera::move(Camera::Direction dir) {
    switch (dir) {
    case Camera::Direction::up:
        m_position += 0.1 * m_orientation_down;
        break;
    case Camera::Direction::down:
        m_position -= 0.1 * m_orientation_down;
        break;
    case Camera::Direction::left:
        m_position -= 0.1 * m_orientation_right;
        break;
    case Camera::Direction::right:
        m_position += 0.1 * m_orientation_right;
        break;
    case Camera::Direction::backward:
        m_position -= 0.1 * m_orientation;
        break;
    case Camera::Direction::forward:
        m_position += 0.1 * m_orientation;
        break;
    }
}


void Camera::rotate(Camera::Direction dir) {
    switch (dir) {
    case Camera::Direction::up:
        m_orientation = m_orientation.rotationVector(0.13, m_orientation_right);
        m_orientation_down = m_orientation_down.rotationVector(0.13, m_orientation_right);
        break;
    case Camera::Direction::down:
        m_orientation = m_orientation.rotationVector(-0.13, m_orientation_right);
        m_orientation_down = m_orientation_down.rotationVector(-0.13, m_orientation_right);
        break;
    case Camera::Direction::left:
        m_orientation = m_orientation.rotationVector(0.13, m_orientation_down);
        m_orientation_right = m_orientation_right.rotationVector(0.13, m_orientation_down);
        break;
    case Camera::Direction::right:
        m_orientation = m_orientation.rotationVector(-0.13, m_orientation_down);
        m_orientation_right = m_orientation_right.rotationVector(-0.13, m_orientation_down);
        break;
    default:
        break;
    }
}


