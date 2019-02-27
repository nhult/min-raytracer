#ifndef PLANE_H
#define PLANE_H

#include "Vec.h"

class Plane
{
public:
    int w, h;

    // Vector from camera point to the center of the plane
    Vec p0;

    Plane(int, int, Vec);
};

#endif