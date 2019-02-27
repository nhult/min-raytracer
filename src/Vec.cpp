#include "Vec.h"

Vec::Vec(double i, double j, double k, Point o) : i{i}, j{j}, k{k}, o{o} { }

double Vec::len()
{
    return sqrt(sqr(i) + sqr(j) + sqr(k));
}

Vec Vec::multiply_constant(double t)
{
    return Vec(t * i, t * j, t * k, o);
}

Vec Vec::normal()
{
    double length = len();
    return Vec((i / length), (j / length), (k / length), o);
}

double Vec::dot(Vec v2)
{
    return (i * v2.i) + (j * v2.j) + (k * v2.k);
}
