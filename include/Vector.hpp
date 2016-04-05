//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#include "ParentPointVector.hpp"

class Vector : public ParentPointVector {
private:
    Vector operator=(const ParentPointVector &p);

public:
    Vector(void);

    Vector(float x, float y, float z);

    ~Vector();

    Vector operator=(const Vector &p);

    Vector operator+(const Vector &p);

    Vector operator-(const Vector &p);

    Vector operator*(const Vector &v); // produit vectoriel

    Vector multiBy(float value);

    Vector nullVector();

//    Vector fromPoints(const Point &p, const Point &p2);


};


#endif //PROJECT_VECTOR_H
