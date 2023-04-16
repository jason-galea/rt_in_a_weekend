#ifndef VEC3_H // If unique value is not defined, continue to include class definition
#define VEC3_H

#include <cmath>
#include <iostream>


class vec3 {
    float xyz [3];

    public:
        // Constuctor (IMPLEMENTATION)
        vec3(float x = 0, float y = 0, float z = 0) {
            xyz[0] = x;
            xyz[1] = y;
            xyz[2] = z;
        }

        // Getters (IMPLEMENTATION)
        // const float * xyz() { return xyz; } // Is this useful?
        const float x() { return xyz[0]; }
        const float y() { return xyz[1]; }
        const float z() { return xyz[2]; }

        // Array access operator (IMPLEMENTATION)
        float vec3::operator[](int i) const { return xyz[i]; } // Return value
        float& vec3::operator[](int i) { return xyz[i]; } // Return reference

        // Inverse operator
        const vec3 operator - () {}

        // Stream operator
        friend std::ostream& operator << (std::ostream &out, const vec3 &v) {}
        
        // Math operators
        friend vec3 operator + (const vec3 &u, const vec3 &v) {}
        friend vec3 operator - (const vec3 &u, const vec3 &v) {}
        friend vec3 operator * (const vec3 &u, const vec3 &v) {}
        friend vec3 operator * (float t, const vec3 &v) {}
        friend vec3 operator * (const vec3 &v, float t) {}
        friend vec3 operator / (vec3 v, float t) {}

        // Math-equals operators
        vec3& operator += (const vec3 &v) {}
        vec3& operator -= (const vec3 &v) {}
        vec3& operator *= (const float t) {}
        vec3& operator /= (const float t) {}

        // Misc. functions
        float length() const {}
        float length_squared() const {}
        friend float dot(const vec3 &u, const vec3 &v) {}
        friend vec3 cross(const vec3 &u, const vec3 &v) {}
        friend vec3 unit_vector(vec3 v) {}

        
};

// Type aliases
using point3 = vec3;
using colour = vec3;


#endif // Else, do not include class definition
