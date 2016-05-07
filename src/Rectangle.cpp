//
// Created by Narex on 05/04/2016.
//

#include "Rectangle.hpp"

Rectangle::Rectangle()
:   Shape()
{
}

Rectangle::Rectangle(Vector const& position, Vector const& rotation, Vector const& scale)
:   Shape(position, rotation, scale)
{
}

Rectangle::~Rectangle() {
}

Rectangle::operator std::string() const {
    return "rectangle => " + Shape::operator std::string();
}

// TODO
bool Rectangle::intersect(Ray &ray, float &dist) {

    // Idee algo ->
    // Diviser chaque cote en 2 triangle
    // Appliquer l'algorithme intersection ray / triangle sur chacun des triangle
    // -> 12 triangle au total
    // Surement moyen d'ameliorer

    //
    // Format du rectangle pour la construction
    // Repere de la forme
    //  y  z
    //  | /
    //  |/___ x
    // P7 ____ P6
    //   /   /|
//      /   / | P5
//  p3 /___/  /
//    |    | /
//    |____|/
//   p0    P1
    Point p0(origin);
    Point p1(origin.x() + width, origin.y(), origin.z());
    Point p2(origin.x(), origin.y() + height, origin.z());
    Point p3(origin.x() + width, origin.y() + height, origin.z());
    Point p4(origin.x(), origin.y(), origin.z() + depth);
    Point p5(origin.x() + width, origin.y(), origin.z() + depth);
    Point p6(origin.x() + width, origin.y() + height, origin.z() + depth);
    Point p7(origin.x(), origin.y() + height, origin.z() + depth);

    Triangle t1(p0, p2, p1);
    Triangle t2(p0, p2, p3);
    Triangle t3(p0, p1, p4);
    Triangle t4(p0, p7, p4);
    Triangle t5(p0, p7, p3);

    Triangle t6(p5, p6, p7);
    Triangle t7(p5, p4, p7);
    Triangle t8(p5, p4, p1);
    Triangle t9(p5, p2, p1);
    Triangle t10(p5, p6, p2);

    Triangle t11(p3, p2, p7);
    Triangle t12(p6, p2, p7);

    Triangle triangles[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12};

    for (Triangle t:triangles) {
        if (t.intersect(ray, dist)) {
            return true;
        }
    }


    return true;
}