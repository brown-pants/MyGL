#ifndef __TRANSFORM_HPP__
#define __TRANSFORM_HPP__
#include "funcs.hpp"

namespace mygl
{
/*-------------------------------model-------------------------------*/
    static mat4 scale(const mat4 &m, const vec3 &v)
    {
        return mat4(v.x, 0.0f, 0.0f, 0.0f,
                    0.0f, v.y, 0.0f, 0.0f,
                    0.0f, 0.0f, v.z, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f) * m;
    }

    static mat4 translate(const mat4 &m, const vec3 &v)
    {
        return mat4(1.0f, 0.0f, 0.0f, v.x,
                    0.0f, 1.0f, 0.0f, v.y,
                    0.0f, 0.0f, 1.0f, v.z,
                    0.0f, 0.0f, 0.0f, 1.0f) * m;
    }
/*---------------------------------view---------------------------------*/
    static mat4 lookAt(const vec3 &position, const vec3 &focus, const vec3 up)
    {
        vec3 front = normalize(focus - position);
        vec3 right = normalize(cross(front, up));
        return mat4(right.x, right.y, right.z, -position.x * right.x - position.y * right.y - position.z * right.z,
                    up.x, up.y, up.z, - position.x * up.x - position.y * up.y - position.z * up.z,
                    -front.x, -front.y, -front.z, position.x * front.x + position.y * front.y + position.z * front.z,
                    0.0f, 0.0f, 0.0f, 1.0f);
    }
/*------------------------------projection------------------------------*/
    static mat4 ortho(float left, float right, float bottom, float top, float near, float far)
    {
        return mat4(2.0f / (right - left), 0.0f, 0.0f, -(right + left) / (right - left),
                    0.0f, 2.0f / (top - bottom), 0, -(top + bottom) / (top - bottom),
                    0.0f, 0.0f, 2.0f / (near - far), -(near + far) / (near - far),
                    0.0f, 0.0f, 0.0f, 1.0f);
    }

    static mat4 perspective(float fovy, float aspect, float zNear, float zFar)
    {
        return mat4(1.0f);
    }
}

#endif