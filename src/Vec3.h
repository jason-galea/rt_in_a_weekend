#ifndef VEC3_H
#define VEC3_H

#include <cmath> // Just for "pow()"
#include <iostream>


class Vec3 {
    float xyz [3]; // Private by default

    public:
        // Constuctor
        Vec3(float x = 0, float y = 0, float z = 0) {
            xyz[0] = x;
            xyz[1] = y;
            xyz[2] = z;
        }

        // Getters
        // const float * xyz() { return xyz; } // Is this useful?
        const float x() { return xyz[0]; }
        const float y() { return xyz[1]; }
        const float z() { return xyz[2]; }

        // // Array access operators
        // float operator[](int i) const { return xyz[i]; } // Return value
        // float& operator[](int i) { return xyz[i]; } // Return reference

        // Inverse operator
        /* Return new Vec3 with inverse values of current instance */
        const Vec3 operator - () {
            return Vec3(-xyz[0], -xyz[1], -xyz[2]);
        }

        // // Stream operator
        // inline friend std::ostream& operator << (std::ostream &out, const Vec3 &v) {
        //     return out << v.xyz[0] << ' ' << v.xyz[1] << ' ' << v.xyz[2];
        // }

        // Math operators
        inline friend Vec3 operator + (const Vec3 &u, const Vec3 &v) {
            return Vec3(u.xyz[0] + v.xyz[0], u.xyz[1] + v.xyz[1], u.xyz[2] + v.xyz[2]);
        }
        inline friend Vec3 operator - (const Vec3 &u, const Vec3 &v) {
            return Vec3(u.xyz[0] - v.xyz[0], u.xyz[1] - v.xyz[1], u.xyz[2] - v.xyz[2]);
        }
        inline friend Vec3 operator * (const Vec3 &u, const Vec3 &v) {
            return Vec3(u.xyz[0] * v.xyz[0], u.xyz[1] * v.xyz[1], u.xyz[2] * v.xyz[2]);
        }
        inline friend Vec3 operator * (float t, const Vec3 &v) {
            return Vec3(t*v.xyz[0], t*v.xyz[1], t*v.xyz[2]);
        }
        inline friend Vec3 operator * (const Vec3 &v, float t) {
            return t * v;
        }
        inline friend Vec3 operator / (Vec3 v, float t) {
            return (1/t) * v;
        }

        // Math-equals operators
        Vec3& operator += (const Vec3 &v) {
            xyz[0] += v.xyz[0];
            xyz[1] += v.xyz[1];
            xyz[2] += v.xyz[2];
            return *this;
        }
        Vec3& operator -= (const Vec3 &v) {
            xyz[0] -= v.xyz[0];
            xyz[1] -= v.xyz[1];
            xyz[2] -= v.xyz[2];
            return *this;
        }
        Vec3& operator *= (const float t) {
            xyz[0] *= t;
            xyz[1] *= t;
            xyz[2] *= t;
            return *this;
        }
        Vec3& operator /= (const float t) {
            return *this *= 1/t;
        }

        // Misc. functions
        const float length() { // Why is this useful?
            return sqrt(length_squared());
        }
        const float length_squared() { // Why is this useful?
            return pow(xyz[0], 2) + pow(xyz[1], 2) + pow(xyz[2], 2);
        }
        inline float dot(const Vec3 &u, const Vec3 &v) {
            return (u.xyz[0] * v.xyz[0]) + (u.xyz[1] * v.xyz[1]) + (u.xyz[2] * v.xyz[2]);
        }
        /*
            Wait, what the hell?
            Don't these three calculations always result in 0?
            (x * y) - (y * x) == 0?
        */
        inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
            return Vec3(
                (u.xyz[1] * v.xyz[2]) - (u.xyz[2] * v.xyz[1]),
                (u.xyz[2] * v.xyz[0]) - (u.xyz[0] * v.xyz[2]),
                (u.xyz[0] * v.xyz[1]) - (u.xyz[1] * v.xyz[0])
            );
        }
        inline Vec3 unit_vector(Vec3 v) {
            return v / v.length();
        }
};

// Type aliases
using Point3 = Vec3;
using Colour = Vec3;


#endif
