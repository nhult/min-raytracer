#ifndef VEC_H
#define VEC_H

#include <math.h>

#include "Point.h"

class Vec
{
public:
    int i, j, k;
    Point o;
    
    Vec(int, int, int, Point);
    double len();
    
    Vec multiply_constant(double);
    Vec normal();
    double dot(Vec);

    /*
    Vec operator+(const Vec &v2) const { return Vec(i + v2.i, j + v2.j, k + v2.k); }
    Vec operator-(const Vec &v2) const { return Vec(i - v2.i, j - v2.j, k - v2.k); }
    */
};

inline int sqr(int n) { return n*n; }

#endif