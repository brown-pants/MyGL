#ifndef __FUNCS_HPP__
#define __FUNCS_HPP__
#include "vec.hpp"
#include "mat.hpp"

#include <math.h>
#include <algorithm>

#define MYGL_PAI 3.1415927f

namespace mygl
{
    template<typename type, int len>
    type dot(const t_vec<type, len> &vec1, const t_vec<type, len> &vec2)
    {
        type value = vec1.getValue(0) * vec2.getValue(0);
        for(int i = 1; i < len; i++){
            value += vec1.getValue(i) * vec2.getValue(i);
        }
        return value;
    }

    template<typename type, int len>
    float length(const t_vec<type, len> &v)
    {
        float r = 0;
        for(int i = 0; i < len; i++)
        {
            r += v.getValue(i) * v.getValue(i);
        }
        return sqrt(r);
    }

    template<typename type, int len>
    t_vec<type, len> normalize(const t_vec<type, len> &v)
    {
        type l = length(v);
        return v / l;
    }

    template<typename type, int rows, int columns>
    t_mat<type, columns, rows> transpose(const t_mat<type, rows, columns> &m)
    {
        t_mat<type, columns, rows> r_mat;
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < columns; col++)
            {
                r_mat[col][row] = m.data[row].getValue(col);
            }
        }
        return r_mat;
    }

    template<typename type>
    t_vec<type, 3> cross(const t_vec<type, 3> &vec1, const t_vec<type, 3> &vec2)
    {
        return t_vec<type, 3>(vec1.y * vec2.z - vec1.z * vec2.y, 
                              vec1.z * vec2.x - vec1.x * vec2.z, 
                              vec1.x * vec2.y - vec1.y * vec2.x);
    }

    template<typename type, int row>
    static t_mat<type, row, row> inverse(const t_mat<type, row, row> &m)
    {

    }

    static vec3 reflect(const vec3 &pos, const vec3 &normal)
    {
        vec3 i = normalize(pos);
        vec3 n = normalize(normal);
        return n * 2 * dot(n, i) - i;
    }
    
    static float radians(float angle)
    {
        return MYGL_PAI / 180.0f * angle;
    }
    
}
#endif