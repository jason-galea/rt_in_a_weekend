#ifndef COLOUR_H
#define COLOUR_H

#include <iostream>

#include "common.h"
#include "Vec3.h"


// class Colour: public Vec3 {
//     public:
//         // Vars
//         float x;
//         float y;
//         float z;
        
//         // Constuctors
//         // Colour(float x_ = 0, float y_ = 0, float z_ = 0) {
//         //     x = x_;
//         //     y = y_;
//         //     z = z_;
//         // }
//         Colour()
//             : x(0), y(0), z(0) {} // Default values
//         Colour(float x_, float y_, float z_)
//             : x(x_), y(y_), z(z_) {}

//         // Misc. functions
//         /* Write colour values of given colour (vec3), mapped to RGB values (0 --> 255) */
//         void write_colour(std::ostream& out) {
//             out << map_float_to_rgb_int(x) << " "
//                 << map_float_to_rgb_int(y) << " "
//                 << map_float_to_rgb_int(z) << "\n";
//             // // NOTE: Tabs are worth it for ~9% larger PPM files
//             // out << map_float_to_rgb_int(x) << "\t"
//             //     << map_float_to_rgb_int(y) << "\t"
//             //     << map_float_to_rgb_int(z) << "\t\t";
//         }
// };


// Static colours
const struct {
    const Colour Black = Colour(0, 0, 0);
    const Colour Red = Colour(1, 0, 0);
    const Colour Green = Colour(0, 1, 0);
    const Colour Blue = Colour(0, 0, 1);
    const Colour White = Colour(1, 1, 1);
} Colours;


// Loose functions relating to Colour
/* Write colour values of given colour (vec3), mapped to RGB values (0 --> 255) */
inline void write_colour(std::ostream& out, const Colour& v) {
    out << map_float_to_rgb_int(v.x) << " "
        << map_float_to_rgb_int(v.y) << " "
        << map_float_to_rgb_int(v.z) << " ";
}


#endif
