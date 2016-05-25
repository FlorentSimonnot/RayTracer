//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>
#include <math.h>
#include <stdlib.h>
#include <Light.hpp>
#include <PPMExporter.hpp>
#include <MaterialPoint.hpp>
#include <iostream>

#include "RayTracer.hpp"


RayTracer::RayTracer(int nbRayon)
        : m_pas((float) 1.57 / WINDOW_WIDTH),
          m_gui(),
          m_nbRayons(nbRayon) {
}

RayTracer::~RayTracer() { }

void RayTracer::draw(Scene const& scene, PPMExporter& ppme) {
    Camera camera = scene.getCamera();
//    scene.test();
//	(void)ppme;
    Point p = camera.position();
    for (auto const& s:scene.getShapes()) {
        s->setCamera_Pos(p);
        s->precalcul(); // sert à sphere / cylindre / sphere englobante
    }
    // Optimisation de calcul
    float winHeightTemp = WINDOW_HEIGHT / 2.f;
    float winWidthTemp = WINDOW_WIDTH / 2.f;

    if (m_nbRayons < 4 && m_nbRayons > 1) {
        m_nbRayons = 1;
    }
    for (int j = 0; j < WINDOW_HEIGHT; ++j) {

        // Optimisation de calcul
        float angle_y = -m_pas * (j - winHeightTemp);
        for (int i = 0; i < WINDOW_WIDTH; ++i) {
            float angle_x = -m_pas * (i - winWidthTemp);

            Vector color(0, 0, 0);
            for (int k = 0; k < m_nbRayons; k++) {
                float off_x = 0;
                float off_y = 0;
                if (m_nbRayons > 3) {
                    off_x = (float) ((static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) - 0.5) * m_pas;
                    off_y = (float) ((static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) - 0.5) * m_pas;
                }

                camera.orientation() *= 1. / camera.orientation().norm();
                Vector directionTempo(
                        camera.orientation()
                                .rotationVector((angle_x + off_x) * cosf(angle_y + off_y),
                                                camera.orientation_down())
                                .rotationVector(angle_y + off_y,
                                                camera.orientation_right())
                );
                directionTempo *= 1. / directionTempo.norm();

                Ray ray(p, directionTempo);

                color += computColor(ray, scene, camera.depth());

//                float dist;
//                Shape const *shape = scene.getFirstCollision(ray, camera.depth(), dist);
//                if (shape) {
//                    color += shape->getColor();
//                }
                /////

            }
            color = moyenneColor(color);
            m_gui.setPixel(i, j, color);
            ppme.writePixel(color);
        }
    }
    m_gui.render();
}

void RayTracer::draw(Scene const& scene) {
    Camera camera = scene.getCamera();
//    scene.test();
    Point p = camera.position();
    for (auto const& s:scene.getShapes()) {
        s->setCamera_Pos(p);
        s->precalcul(); // sert à sphere / cylindre / sphere englobante
    }
    // Optimisation de calcul
    float winHeightTemp = WINDOW_HEIGHT / 2.f;
    float winWidthTemp = WINDOW_WIDTH / 2.f;

    if (m_nbRayons < 4 && m_nbRayons > 1) {
        m_nbRayons = 1;
    }
    for (int j = 0; j < WINDOW_HEIGHT; ++j) {

        // Optimisation de calcul
        float angle_y = -m_pas * (j - winHeightTemp);
        for (int i = 0; i < WINDOW_WIDTH; ++i) {
            float angle_x = -m_pas * (i - winWidthTemp);

            Vector color(0, 0, 0);
            for (int k = 0; k < m_nbRayons; k++) {
                float off_x = 0;
                float off_y = 0;
                if (m_nbRayons > 3) {
                    off_x = (float) ((static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) - 0.5) * m_pas;
                    off_y = (float) ((static_cast<float> (rand()) / static_cast<float> (RAND_MAX)) - 0.5) * m_pas;
                }

                camera.orientation() *= 1. / camera.orientation().norm();
                Vector directionTempo(
                        camera.orientation()
                                .rotationVector((angle_x + off_x) * cosf(angle_y + off_y),
                                                camera.orientation_down())
                                .rotationVector(angle_y + off_y,
                                                camera.orientation_right())
                );
                directionTempo *= 1. / directionTempo.norm();

                Ray ray(p, directionTempo);

                color += computColor(ray, scene, camera.depth());

//                float dist;
//                Shape const *shape = scene.getFirstCollision(ray, camera.depth(), dist);
//                if (shape) {
//                    color += shape->getColor();
//                }
                /////
            }
            color = moyenneColor(color);
            m_gui.setPixel(i, j, color);
        }
    }
    m_gui.render();
}


Vector RayTracer::moyenneColor(Vector const& colors) const {
    float divide = (float) 1. / m_nbRayons;
    return Vector((float) round(colors.x() * divide),
                  (float) round(colors.y() * divide),
                  (float) round(colors.z() * divide));
}

Vector RayTracer::computColor(Ray const& ray, Scene const& scene, float cameraDepth) {
    float dist;
    Vector color (0, 0, 0);

    Shape const *shape = scene.getFirstCollision(ray, cameraDepth, dist);
    if (shape) {
        MaterialPoint caracteristics;
        caracteristics.setPointIntersection(ray.getOrigin() + dist * ray.getDirection());
        caracteristics.setNormal(shape->getNormalFromPoint(ray, dist));
        caracteristics.setColor(shape->getColor());

        float facteur, scalaire;
        Vector refl = ray.getDirection() - 2 * caracteristics.normal().produitScalaire(ray.getDirection()) * caracteristics.normal();
        Vector ambient, diffuse, specular;

        /// TEST UNIQUEMENT ////
//        Light light(Point(-5, 0, 0), Vector(0, 0, 0));
//        Vector tempo = light.getCenter() - caracteristics.pointIntersection();
//        tempo *= 1. / tempo.norm();
//        facteur += fmaxf(caracteristics.normal().produitScalaire(tempo), 0);
//        facteur = (float) ((0.8 * facteur) / (float) 1.f + 0.2);
//        color += facteur * caracteristics.color();

        ambient = 0.2 * caracteristics.color();
        color += ambient;

        for (auto const& l:scene.getLights()) {
            Vector lightDir = l->getCenter() - caracteristics.pointIntersection();
            float lightNorm = lightDir.norm();
            lightDir *= 1 / lightNorm;
            Ray lightRay = Ray(caracteristics.pointIntersection(), lightDir);
            if (!scene.getShadowCollision(lightRay, lightNorm)) {
                scalaire = caracteristics.normal().produitScalaire(lightDir);
                if (scalaire > 0) {
                    diffuse = scalaire * caracteristics.color();
                    diffuse.setX(fminf(diffuse.x(), l->getColor().x()));
                    diffuse.setY(fminf(diffuse.y(), l->getColor().y()));
                    diffuse.setZ(fminf(diffuse.z(), l->getColor().z()));
                    color += 0.8 * diffuse;
                    scalaire = refl.produitScalaire(lightDir);
                    if (scalaire > 0) {
                        facteur = 0.2 * pow(scalaire, 50);
                        specular = facteur * l->getColor();
                        color += specular;
                    }
                }
            }
        }
        color.setX(color.x() < 0 ? 0 : (color.x() > 0xff ? 0xff : color.x()));
        color.setY(color.y() < 0 ? 0 : (color.y() > 0xff ? 0xff : color.y()));
        color.setZ(color.z() < 0 ? 0 : (color.z() > 0xff ? 0xff : color.z()));

//        color = scene.computColor(, caracteristics);
//        if (level < m_nbReflexions) {
//            Point p = ray.getOrigin() + dist * ray.getDirection();
//            Vector dir =
//                    ray.getDirection() - (ray.getDirection() * caracteristics.m_normal) * 2 * caracteristics.m_normal;
//            Ray ray_sec(p, dir);
//            ray_sec.getDirection() *= 1. / ray_sec.getDirection().norm();
//            ray_sec.setDirection(ray_sec.getDirection() * (1.f / ray_sec.getDirection().norm()));
//
//            Vector color_sec(0, 0, 0);
//            computColor(ray_sec, color_sec, level + 1, scene, cameraDepth);
//
//            // color += mult(color_sec, caracteristics.reflect);
//            color += color_sec.crossProduct(caracteristics.m_reflect);
//        }
    }
    return (color);
}
