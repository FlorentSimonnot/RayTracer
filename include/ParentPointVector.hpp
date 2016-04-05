//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_PARENTPOINTVECTOR_HPP
#define PROJECT_PARENTPOINTVECTOR_HPP

#define SQR(a) a*a

class ParentPointVector {
protected:
    float x;
    float y;
    float z;
public:
    ParentPointVector(void);
    ParentPointVector(float x, float y, float z);

    ~ParentPointVector();
    ParentPointVector operator+(const ParentPointVector &p);
    ParentPointVector operator-(const ParentPointVector &p);
    bool operator==(const ParentPointVector &p);
    bool operator!=(const ParentPointVector &p);
    ParentPointVector operator=(const ParentPointVector &p);
    float getX() const;
    float getY() const;
    float getZ() const;
};


#endif //PROJECT_PARENTPOINTVECTOR_HPP
