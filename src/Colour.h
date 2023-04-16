#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#include "common.h"
#include "Vec3.h"


class Colour: public Vec3 {
    public:
        // Constuctor
        Colour(float x = 0, float y = 0, float z = 0) {
            xyz[0] = x;
            xyz[1] = y;
            xyz[2] = z;
        }

        // Misc. functions
        /* Write colour values of given colour (vec3), mapped to RGB values (0 --> 255) */
        void write_colour(std::ostream &out, Colour c) {
            out << map_float_to_rgb_int(c.x()) << " "
                << map_float_to_rgb_int(c.y()) << " "
                << map_float_to_rgb_int(c.z()) << "\n";
        }



};


#endif
