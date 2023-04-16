#ifndef COMMON_H
#define COMMON_H

#include "Vec3.h"


/* Map float in range (0 --> 1) to int in range (0 --> 255) */
int map_float_to_rgb_int(float rgb_val) {
    return (int)(255.999 * rgb_val);
}

// NOTE: Currently, this function is not tied to any class
// NOTE: Colour should be a child class of Vec3, not an alias
/* Write colour values of given colour (vec3), mapped to RGB values (0 --> 255) */
void write_colour(std::ostream &out, Colour c) {
// void Colour::write_colour(std::ostream &out, Colour c) {
    out << map_float_to_rgb_int(c.x()) << " "
        << map_float_to_rgb_int(c.y()) << " "
        << map_float_to_rgb_int(c.z()) << "\n";
}


#endif
