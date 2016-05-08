//
// Created by Narex on 07/05/2016.
//

#ifndef SYNTHESE_IMAGE_BOUNDINGVOLUME_HPP
#define SYNTHESE_IMAGE_BOUNDINGVOLUME_HPP

#include <Point.hpp>
class BoundingVolume {
private:
    Point m_center;
    float m_radius;
public:
    BoundingVolume();
    BoundingVolume(Point center,float radius);
    ~BoundingVolume();
};


#endif //SYNTHESE_IMAGE_BOUNDINGVOLUME_HPP
