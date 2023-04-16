#include <cmath>

#include "vec3.h"


// Inverse operator
/* Return new vec3 with inverse values of current instance */
const vec3 vec3::operator - () {
    return vec3(-xyz[0], -xyz[1], -xyz[2]);
}


// Stream operator
inline std::ostream& operator << (std::ostream &out, const vec3 &v) {
    return out << v.xyz[0] << ' ' << v.xyz[1] << ' ' << v.xyz[2];
}


// Math operators
inline vec3 operator + (const vec3 &u, const vec3 &v) {
    return vec3(u.xyz[0] + v.xyz[0], u.xyz[1] + v.xyz[1], u.xyz[2] + v.xyz[2]);
}
inline vec3 operator - (const vec3 &u, const vec3 &v) {
    return vec3(u.xyz[0] - v.xyz[0], u.xyz[1] - v.xyz[1], u.xyz[2] - v.xyz[2]);
}
inline vec3 operator * (const vec3 &u, const vec3 &v) {
    return vec3(u.xyz[0] * v.xyz[0], u.xyz[1] * v.xyz[1], u.xyz[2] * v.xyz[2]);
}
inline vec3 operator * (float t, const vec3 &v) {
    return vec3(t*v.xyz[0], t*v.xyz[1], t*v.xyz[2]);
}
inline vec3 operator * (const vec3 &v, float t) {
    return t * v;
}
inline vec3 operator / (vec3 v, float t) {
    return (1/t) * v;
}


// Math-equals operators
vec3& vec3::operator += (const vec3 &v) {
    xyz[0] += v.xyz[0];
    xyz[1] += v.xyz[1];
    xyz[2] += v.xyz[2];
    return *this;
}
vec3& vec3::operator -= (const vec3 &v) {
    xyz[0] -= v.xyz[0];
    xyz[1] -= v.xyz[1];
    xyz[2] -= v.xyz[2];
    return *this;
}
vec3& vec3::operator *= (const float t) {
    xyz[0] *= t;
    xyz[1] *= t;
    xyz[2] *= t;
    return *this;
}
vec3& vec3::operator /= (const float t) {
    return *this *= 1/t;
}


// Misc. functions
/* Why is this useful? */
float vec3::length() const {
    return sqrt(length_squared());
}
/* Why is this useful? */
float vec3::length_squared() const {
    return pow(xyz[0], 2) + pow(xyz[1], 2) + pow(xyz[2], 2);
}
inline float dot(const vec3 &u, const vec3 &v) {
    return u.xyz[0] * v.xyz[0]
        + u.xyz[1] * v.xyz[1]
        + u.xyz[2] * v.xyz[2];
}
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.xyz[1] * v.xyz[2] - u.xyz[2] * v.xyz[1],
                u.xyz[2] * v.xyz[0] - u.xyz[0] * v.xyz[2],
                u.xyz[0] * v.xyz[1] - u.xyz[1] * v.xyz[0]);
}
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}
