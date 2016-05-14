//
// Created by Narex on 05/05/2016.
//

#include <Shape.hpp>
#include <math.h>
#include <stdlib.h>
#include <Light.hpp>
#include <PPMExporter.hpp>
#include <MaterialPoint.hpp>

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
//    Camera camera = Camera(50, Point(-5, 0, 0), Vector(1, 0, 0));
    Point p = camera.position();
    for (auto const& s:scene.getShapes()) {
        s->setCamera_Pos(p);
        s->precalcul(); // sert à sphere / cylindre / sphere englobante
    }
    // Optimisation de calcul
    float winHeightTemp = WINDOW_HEIGHT / 2.f;
    float winWidthTemp = WINDOW_WIDTH / 2.f;

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

                ////

                computColor(ray, color, scene, camera.depth());

//                float dist;
//                Shape const *shape = scene.getFirstCollision(ray, camera.depth(), dist);
//                if (shape) {
//                    color += shape->getColor();
//                }
                /////

            }
            color = moyenneColor(color);
            m_gui.setPixel(i, j, color);
//            std::cout << "color = " << std::string(color) << std::endl;
//            ppme.writePixel(color);
        }
    }
    m_gui.render();
    scanf("%*c");
}

Vector RayTracer::moyenneColor(Vector const& colors) const {
    float divide = (float) 1. / m_nbRayons;
    return Vector((float) round(colors.x() * divide),
                  (float) round(colors.y() * divide),
                  (float) round(colors.z() * divide));
}

void RayTracer::computColor(Ray const& ray, Vector& color, Scene const& scene, float cameraDepth) {
    float dist;

    Shape const *shape = scene.getFirstCollision(ray, cameraDepth, dist);
    if (shape) {
        MaterialPoint caracteristics;
        caracteristics.setPointIntersection(ray.getOrigin() + dist * ray.getDirection());
        caracteristics.setNormal(shape->getNormalFromPoint(ray, dist));
        caracteristics.setColor(shape->getColor());

        float facteur = 0;


        /// TEST UNIQUEMENT ////
        Light light(Point(-5, 0, 0), Vector(0, 0, 0));
        Vector tempo = light.getCenter() - caracteristics.pointIntersection();
        tempo *= 1. / tempo.norm();
        facteur += fmaxf(caracteristics.normal().produitScalaire(tempo), 0);
        facteur = (float) ((0.8 * facteur) / (float) 1.f + 0.2);
        color += facteur * caracteristics.color();

        ////////FIN TEST UNIQUEMENT ///////////////
        // TODO BON CODE
        //        for (auto const& l:scene.getLights()) {
//            Vector tempo = l->getCenter() - caracteristics.pointIntersection();
//            tempo *= 1./tempo.norm();
//            facteur += fmaxf(caracteristics.normal().produitScalaire(tempo),0);
//        }
//        facteur = (float)((0.8*facteur) / (float)scene.getLights().size() +0.2);
//        color += facteur * caracteristics.color();



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
}