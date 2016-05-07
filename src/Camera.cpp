//
// Created by Narex on 07/05/2016.
//


#include "Camera.hpp"

Camera::Camera()
        : m_fov(60), m_depth(10) { }

Camera::Camera(Point const& position, Vector const& orientation)
        : m_position(position),
          m_orientation(orientation) { }

Camera::Camera(float fov, float depth, Point const& position, Vector const& orientation)
        : m_fov(fov),
          m_depth(depth),
          m_position(position),
          m_orientation(orientation) { }

Camera::~Camera() { }

float Camera::getFov() {
    return m_fov;
}

float Camera::getDepth() {
    return m_depth;
}

Point Camera::getPosition() {
    return m_position;
}

Vector Camera::getOrientation() {
    return m_orientation;
}

void Camera::setFov(float val) {
    m_fov = val;
}

void Camera::setDepth(float val) {
    m_depth = val;
}

void Camera::setPosition(Point position) {
    m_position = position;
}

void Camera::setOrientation(Vector orientation) {
    m_orientation = orientation;
}