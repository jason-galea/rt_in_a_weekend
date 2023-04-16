#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#include "common.h"
#include "Vec3.h"


class Colour: public Vec3 {
    public:
        // Constuctor
        Colour(float x_ = 0, float y_ = 0, float z_ = 0) {
            x = x_;
            y = y_;
            z = z_;
        }

        // Misc. functions
        /* Write colour values of given colour (vec3), mapped to RGB values (0 --> 255) */
        void write_colour(std::ostream &out) {
            out << map_float_to_rgb_int(x) << " "
                << map_float_to_rgb_int(y) << " "
                << map_float_to_rgb_int(z) << "\n";
            // // NOTE: Tabs are worth it for ~9% larger PPM files
            // out << map_float_to_rgb_int(x) << "\t"
            //     << map_float_to_rgb_int(y) << "\t"
            //     << map_float_to_rgb_int(z) << "\t\t";
        }
};


#endif
