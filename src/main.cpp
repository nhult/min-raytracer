#include <fstream>
#include <iostream>

#include "Point.h"
#include "Vec.h"
#include "Plane.h"
#include "Sphere.h"
#include "Color.h"

int main() {
    Point camera_p { 0, 0, 0 };
    Vec p0 { 200, 0, 0, camera_p }; // Direction and distance of the plane from camera point to the middle of the plane
    Plane plane { 800, 600, p0 }; // Define image height and width as a plane

    std::ofstream out("image.ppm");
    out << "P3\n" << plane.w << ' ' << plane.h << '\n' << 255 << '\n';

    Color COLOR_BLACK { 0, 0, 0 };
    Color COLOR_WHITE { 255, 255, 255 };
    
    Sphere sphere { 50, Point(600, 0, 0) };
    Vec sphere_vec { 600, 0, 0, camera_p };

    for (int zp = 0 - (plane.h / 2); zp < (0 + (plane.h / 2)); zp++) {
        for (int yp = 0 + (plane.w / 2); yp > (0 - (plane.w / 2)); yp--) {

            // Shoot a ray through each pixel of the plane
            Vec ray_vec { 200, yp, zp, camera_p };
            Vec ray_dir = ray_vec.normal();

            // Check if the ray intersects with anything
            double t = ray_dir.dot(sphere_vec);
            Vec p = /* camera_p + */ ray_dir.multiply_constant(t);
            Vec y { sphere.pos.x - p.i, sphere.pos.y - p.j, sphere.pos.z - p.k, sphere.pos };

            // Case 1: Distance between the sphere's center and the closest point of the ray is larger than the sphere's radius. No intersection.
            if (y.len() > sphere.r) { out << COLOR_WHITE.r << ' ' << COLOR_WHITE.g << ' ' << COLOR_WHITE.b << '\n'; }
            else { out << COLOR_BLACK.r << ' ' << COLOR_BLACK.g << ' ' << COLOR_BLACK.b << '\n'; }
        }
    }

    return 0;
}
