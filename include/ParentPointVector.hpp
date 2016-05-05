//
// Created by Narex on 05/04/2016.
//

#ifndef PROJECT_PARENTPOINTVECTOR_HPP
#define PROJECT_PARENTPOINTVECTOR_HPP

#define SQR(a) a*a

class ParentPointVector {
protected:
    double x;
    double y;
    double z;
public:
    ParentPointVector(void);
    ParentPointVector(double x, double y, double z);

    ~ParentPointVector();
    ParentPointVector operator+(const ParentPointVector &p);
    ParentPointVector operator-(const ParentPointVector &p);
    bool operator==(const ParentPointVector &p);
    bool operator!=(const ParentPointVector &p);
    ParentPointVector operator=(const ParentPointVector &p);

    void setX(double v) ;
    void setY(double v) ;
    void setZ(double v) ;
    double getX() const;
    double getY() const;
    double getZ() const;
};


#endif //PROJECT_PARENTPOINTVECTOR_HPP
