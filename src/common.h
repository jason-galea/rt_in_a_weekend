#ifndef COMMON_H
#define COMMON_H


// NOTE: DON'T INCLUDE ANY CUSTOM HEADERS HERE!


// Misc functions
/* Map float in range (0 --> 1) to int in range (0 --> 255) */
inline int map_float_to_rgb_int(float rgb_val) {
    return (int)(255.999 * rgb_val);
}


#endif
