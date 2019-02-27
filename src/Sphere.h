#ifndef SPHERE_H
#define SPHERE_H

#include "Point.h"
#include "Vec.h"

class Sphere
{
public:
    double r; // radius
    Point pos;

    Sphere(double, Point);
    bool intersects(Vec);
};

#endif