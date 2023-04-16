#ifndef COMMON_H
#define COMMON_H

#include "Vec3.h"
#include "Colour.h"
#include "Ray.h"


// Misc functions
/* Map float in range (0 --> 1) to int in range (0 --> 255) */
inline int map_float_to_rgb_int(float rgb_val) {
    return (int)(255.999 * rgb_val);
}


// Relating to Vec3
inline float dot(const Vec3 &v1, const Vec3 &v2) {
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3(
        (v1.y * v2.z) - (v1.z * v2.y),
        (v1.z * v2.x) - (v1.x * v2.z),
        (v1.x * v2.y) - (v1.y * v2.x)
    );
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}


// Relating to Ray
// TODO: Give vars meaningful names
Colour ray_colour(const Ray& r) {
    Vec3 unit_dir = unit_vector(r.dir);
    auto t = 0.5*(unit_dir.y + 1);
    KEEP_WRITING_FROM_HERE_LOL
}


#endif
