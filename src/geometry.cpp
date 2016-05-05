//
// Created by narex on 03/04/16.
//
#include <iostream>
#include "geometry.hpp"


int main(void) {

    Point a(1., 2., 3.);
    std::cout << "test1\n";
    Point b(1., 2., 4.);
    std::cout << "test\n";


    if (a == b) {
        std::cout << "test3\n";
    }
    else {
        std::cout << "test4\n";
    }
    std::cout << "a " << a.getX() << "\n";
    std::cout << "a " << a.getY() << "\n";
    std::cout << "a " << a.getZ() << "\n";


//    Point c(0, 0, 0);
//
//    c = a + b;
//    std::cout << c.getX() << "\n";
//    std::cout << c.getY() << "\n";
//    std::cout << c.getZ() << "\n";


//    std::cout << (a + b).getX() << "\n";
//    std::cout << (a + b).getY() << "\n";
//    std::cout << (a + b).getZ() << "\n";
//    std::cout << c.getX() << "\n";
    //std::cout << a+b;

    return 0;
}