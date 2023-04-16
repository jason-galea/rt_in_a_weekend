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
        Ray() {} // NO default values
        Ray(const Point3& origin_, Vec3& dir_) : origin(origin_), dir(dir_) {}

        // Functions
        const Point3 at(float t) {
            return origin + (dir * t);
        }
};


#endif
