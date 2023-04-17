#ifndef RAY_H
#define RAY_H

#include <iostream>

// #include "common.h"
#include "Vec3.h"


class Ray {
    public:
        // Vars
        Point3 origin;
        Vec3 dir;

        // Constuctors
        Ray() {} // No default values
        Ray(const Point3& origin_, const Vec3& dir_)
            : origin(origin_), dir(dir_) {}

        // Functions
        const Point3 at(const float t) {
            return origin + (dir * t);
        }
};


// Loose functions relating to Ray
/* TEMPORARY function to produce a liner gradient based on the SCALED y component */
inline Colour ray_colour(const Ray& r) {
    Vec3 unit_dir = unit_vector(r.dir); // Vector describing the direction from ??? to ???
    Colour white = Colour(1, 1, 1);
    Colour blue = Colour(0.5, 0.7, 1);
    auto t = 0.5*(unit_dir.y + 1.0); // Arbitrary point based on "y", scaled within (-1, 1)

    return white*(1 - t) + blue*t; // TODO: Describe me please!
}


#endif
