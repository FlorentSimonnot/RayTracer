//
// Created by narex on 03/04/16.
//

#ifndef PROJECT_GEOMETRY_HPP
#define PROJECT_GEOMETRY_HPP

typedef struct Point {
    float x;
    float y;
    float z;
}Point;


typedef struct {
    Point

}Rayon;

typedef struct {
    Point centre;
    float rayon;

}Sphere;

typedef struct {
    Point sommet_1;
    Point sommet_2;
    Point sommet_3;

}Triangle;


typedef struct {


}Cylindre;



typedef struct {
    Point point_1;
    float width;
    float height;
//    float



}Rectangle;


#endif //PROJECT_GEOMETRY_HPP
