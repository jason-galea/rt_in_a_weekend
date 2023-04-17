#ifndef RAY_H
#define RAY_H

#include <iostream>

#include "common.h"
#include "Vec3.h"
#include "Colour.h"


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
bool did_ray_hit_sphere(const Point3& center, float radius, const Ray& r) {
    Vec3 oc = r.origin - center; // ???
    float a = dot_product(r.dir, r.dir); // Get "magnitude" of ray direction vector?
    float b =  2.0 * dot_product(oc, r.dir); // ???
    float c = dot_product(oc, oc) - (radius*radius);
    float discriminant = (b*b) - 4*a*c; // Should only even equal 0|1|2, right?
    return (discriminant > 0);
}

/* TEMPORARY function to produce a liner gradient based on the SCALED y component */
inline Colour ray_colour(const Ray& r) {
    if ( did_ray_hit_sphere(Point3(0, 0, -1), 0.5, r) )
        return Colours.Red;

    Vec3 unit_dir = unit_vector(r.dir); // Vector describing the direction from ??? to ???
    float t = 0.5*(unit_dir.y + 1.0); // Arbitrary point based on "y", scaled within (-1, 1)

    return (Colours.White * (1 - t)) + (Colours.Blue * t); // TODO: Describe me please!
}


#endif
