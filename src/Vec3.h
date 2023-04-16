#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>


class Vec3 {
    public:
        // Vars
        float x;
        float y;
        float z;

        // Constuctors
        Vec3() : x(0), y(0), z(0) {} // Default values
        Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

        // Inverse operator
        const Vec3 operator - () {
            return Vec3(-x, -y, -z);
        }

        // Stream operator
        friend std::ostream& operator << (std::ostream &out, const Vec3 &v) {
            return out << v.x << ' ' << v.y << ' ' << v.z;
        }

        // Math operators
        friend Vec3 operator + (const Vec3 &v1, const Vec3 &v2) {
            return Vec3(
                v1.x + v2.x,
                v1.y + v2.y,
                v1.z + v2.z
            );
        }
        friend Vec3 operator - (const Vec3 &v1, const Vec3 &v2) {
            return Vec3(
                v1.x - v2.x,
                v1.y - v2.y,
                v1.z - v2.z
            );
        }
        friend Vec3 operator * (const Vec3 &v1, const Vec3 &v2) {
            return Vec3(
                v1.x * v2.x,
                v1.y * v2.y,
                v1.z * v2.z
            );
        }
        friend Vec3 operator * (const Vec3 &v, float t) {
            return Vec3(
                t * v.x,
                t * v.y,
                t * v.z
            );
        }
        friend Vec3 operator / (Vec3 v, float t) {
            return v * ( 1 / t );
        }

        // Math-equals operators
        Vec3& operator += (const Vec3 &v) {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }
        Vec3& operator -= (const Vec3 &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }
        Vec3& operator *= (const float t) {
            x *= t;
            y *= t;
            z *= t;
            return *this;
        }
        Vec3& operator /= (const float t) {
            return *this *= ( 1 / t );
        }

        // Misc. functions
        const float length_squared() {
            return x*x + y*y + z*z;
        }
        const float length() {
            return std::sqrt(length_squared());
        }
};

// Type aliases
using Point3 = Vec3;


#endif
