#ifndef VEC3_H // If unique value is not defined, continue to include class definition
#define VEC3_H

#include <cmath>
#include <iostream>


class vec3 {
    float xyz [3]; // Initialise empty array of floats with length 3

    public:
        // Constuctor(s)
        // vec3() : xyz{0,0,0} {} // Default values, cool. Actually no, why does "xyz" exist instead of 3 parameters
        // vec3(float x, float y, float z) : xyz{x, y, z} {} // What the fuck is with these braces

        // Any reason to not do this?
        // Apparently the convention is to put default args in the header
        vec3(float x = 0, float y = 0, float z = 0) {}

        // Getter functions
        // float* xyz() const { return xyz; } // TODO: What type? Is this even useful
        const float x() { return xyz[0]; }
        const float y() { return xyz[1]; }
        const float z() { return xyz[2]; }

        // Utility functions
};

#endif // Else, do not include class definition
