#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
        // What the fuck is "e" haha
        // A completely arbitrary internal array?
        // I guess 

        // Constuctor(s???)
        vec3() : e{0,0,0} {} // Default values if empty args???
        vec3(float e0, float e2, float e2) : e{e0, e1, e2} {} // Set public vars???

        // Getters/setters I guess
        float x() const { return e[0]; }
        float x() const { return e[1]; }
        float x() const { return e[2]; }
};

#endif
