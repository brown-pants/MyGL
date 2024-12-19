#ifndef __VEC_HPP__
#define __VEC_HPP__
#include <assert.h>

namespace mygl
{
    template<typename type, int rows, int columns>
    struct t_mat;

    template<typename type, int length>
    struct t_vec {};

    template<typename type>
    struct t_vec<type, 2> {
        t_vec() : x(0), y(0) {}
        t_vec(type x, type y) : x(x), y(y) {}
        t_vec(const t_vec<type, 3> &v3) : x(v3.x), y(v3.y) {}
        t_vec(const t_vec<type, 4> &v4) : x(v4.x), y(v4.y) {}
        type getValue(int i) const
        {
            assert(i >= 0 && i < 2);
            return i == 0 ? x : y;
        }
        constexpr bool operator== (const t_vec<type, 2> &v2) const
        {
            return this->x == v2.x && this->y == v2.y;
        }
        constexpr bool operator!= (const t_vec<type, 2> &v2) const
        {
            return this->x != v2.x || this->y != v2.y;
        }
        constexpr type &operator[] (int i)
        {
            assert(i >= 0 && i < 2);
            return i == 0 ? x : y;
        }
        constexpr t_vec<type, 2> operator+ (const t_vec<type, 2> &v2) const
        {
            return t_vec<type, 2>(this->x + v2.x, this->y + v2.y);
        }
        constexpr t_vec<type, 2> operator- (const t_vec<type, 2> &v2) const
        {
            return t_vec<type, 2>(this->x - v2.x, this->y - v2.y);
        }
        constexpr t_vec<type, 2> operator- () const
        {
            return t_vec<type, 2>(-this->x, -this->y);
        }
        constexpr t_vec<type, 2> operator* (const t_vec<type, 2> &v2) const
        {
            return t_vec<type, 2>(this->x * v2.x, this->y * v2.y);
        }
        constexpr t_vec<type, 2> operator* (type a) const
        {
            return t_vec<type, 2>(this->x * a, this->y * a);
        }
        constexpr t_vec<type, 2> operator/ (type a) const
        {
            return t_vec<type, 2>(this->x / a, this->y / a);
        }
        
        template<int cols>
        constexpr t_vec<type, cols> operator* (const t_mat<type, 2, cols> &m) const;

        constexpr t_vec<type, 2> &operator*= (const t_mat<type, 2, 2> &m);

        constexpr t_vec<type, 2> operator/ (const t_vec<type, 2> &v2) const
        {
            return t_vec<type, 2>(this->x / v2.x, this->y / v2.y);
        }
        constexpr t_vec<type, 2> &operator+= (const t_vec<type, 2> &v2)
        {
            this->x += v2.x;
            this->y += v2.y;
            return *this;
        }
        constexpr t_vec<type, 2> &operator-= (const t_vec<type, 2> &v2)
        {
            this->x -= v2.x;
            this->y -= v2.y;
            return *this;
        }
        constexpr t_vec<type, 2> &operator*= (const t_vec<type, 2> &v2)
        {
            this->x *= v2.x;
            this->y *= v2.y;
            return *this;
        }
        constexpr t_vec<type, 2> &operator/= (const t_vec<type, 2> &v2)
        {
            this->x /= v2.x;
            this->y /= v2.y;
            return *this;
        }
        constexpr t_vec<type, 2> &operator*= (type a)
        {
            this->x *= a;
            this->y *= a;
            return *this;
        }
        constexpr t_vec<type, 2> &operator/= (type a)
        {
            this->x /= a;
            this->y /= a;
            return *this;
        }
        union {
            struct {type x, y;};
            struct {type r, g;};
        };
    };

    template<typename type>
    struct t_vec<type, 3> {
        t_vec() : x(0), y(0), z(0) {}
        t_vec(type x, type y, type z) : x(x), y(y), z(z) {}
        t_vec(const t_vec<type, 2> &v2, type z) : x(v2.x), y(v2.y), z(z) {}
        t_vec(const t_vec<type, 4> &v4) : x(v4.x), y(v4.y), z(v4.z) {}
        type getValue(int i) const
        {
            assert(i >= 0 && i < 3);
            return i == 0 ? x : i == 1 ? y : z;
        }
        constexpr bool operator== (const t_vec<type, 3> &v3) const
        {
            return this->x == v3.x && this->y == v3.y && this->z == v3.z;
        }
        constexpr bool operator!= (const t_vec<type, 3> &v3) const
        {
            return this->x != v3.x || this->y != v3.y || this->z != v3.z;
        }
        constexpr type &operator[] (int i)
        {
            assert(i >= 0 && i < 3);
            return i == 0 ? x : i == 1 ? y : z;
        }
        constexpr t_vec<type, 3> operator+ (const t_vec<type, 3> &v3) const
        {
            return t_vec<type, 3>(this->x + v3.x, this->y + v3.y, this->z + v3.z);
        }
        constexpr t_vec<type, 3> operator- (const t_vec<type, 3> &v3) const
        {
            return t_vec<type, 3>(this->x - v3.x, this->y - v3.y, this->z - v3.z);
        }
        constexpr t_vec<type, 3> operator- () const
        {
            return t_vec<type, 3>(-this->x, -this->y, -this->z);
        }
        constexpr t_vec<type, 3> operator* (const t_vec<type, 3> &v3) const
        {
            return t_vec<type, 3>(this->x * v3.x, this->y * v3.y, this->z * v3.z);
        }
        constexpr t_vec<type, 3> operator* (type a) const
        {
            return t_vec<type, 3>(this->x * a, this->y * a, this->z * a);
        }
        constexpr t_vec<type, 3> operator/ (type a) const
        {
            return t_vec<type, 3>(this->x / a, this->y / a, this->z / a);
        }

        template<int cols>
        constexpr t_vec<type, cols> operator* (const t_mat<type, 3, cols> &m) const;

        constexpr t_vec<type, 3> &operator*= (const t_mat<type, 3, 3> &m);


        constexpr t_vec<type, 3> operator/ (const t_vec<type, 3> &v3) const
        {
            return t_vec<type, 3>(this->x / v3.x, this->y / v3.y, this->z / v3.z);
        }
        constexpr t_vec<type, 3> &operator+= (const t_vec<type, 3> &v3)
        {
            this->x += v3.x;
            this->y += v3.y;
            this->z += v3.z;
            return *this;
        }
        constexpr t_vec<type, 3> &operator-= (const t_vec<type, 3> &v3)
        {
            this->x -= v3.x;
            this->y -= v3.y;
            this->z -= v3.z;
            return *this;
        }
        constexpr t_vec<type, 3> &operator*= (const t_vec<type, 3> &v3)
        {
            this->x *= v3.x;
            this->y *= v3.y;
            this->z *= v3.z;
            return *this;
        }
        constexpr t_vec<type, 3> &operator*= (type a)
        {
            this->x *= a;
            this->y *= a;
            this->z *= a;
            return *this;
        }
        constexpr t_vec<type, 3> &operator/= (type a)
        {
            this->x /= a;
            this->y /= a;
            this->z /= a;
            return *this;
        }
        constexpr t_vec<type, 3> &operator/= (const t_vec<type, 3> &v3)
        {
            this->x /= v3.x;
            this->y /= v3.y;
            this->z /= v3.z;
            return *this;
        }
        union {
            struct {type x, y, z;};
            struct {type r, g, b;};
        };
    };

    template<typename type>
    struct t_vec<type, 4> {
        t_vec() : x(0), y(0), z(0), w(0) {}
        t_vec(type x, type y, type z, type w) : x(x), y(y), z(z), w(w) {}
        t_vec(const t_vec<type, 3> &v3, type w) : x(v3.x), y(v3.y), z(v3.z), w(w) {}
        t_vec(const t_vec<type, 2> &v2, type z, type w) : x(v2.x), y(v2.y), z(z), w(w) {}
        type getValue(int i) const
        {
            assert(i >= 0 && i < 4);
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }
        constexpr bool operator== (const t_vec<type, 4> &v4) const
        {
            return this->x == v4.x && this->y == v4.y && this->z == v4.z && this->w == v4.w;
        }
        constexpr bool operator!= (const t_vec<type, 4> &v4) const
        {
            return this->x != v4.x || this->y != v4.y || this->z != v4.z || this->w != v4.w;
        }
        constexpr type &operator[] (int i)
        {
            assert(i >= 0 && i < 4);
            return i == 0 ? x : i == 1 ? y : i == 2 ? z : w;
        }
        constexpr t_vec<type, 4> operator+ (const t_vec<type, 4> &v4) const
        {
            return t_vec<type, 4>(this->x + v4.x, this->y + v4.y, this->z + v4.z, this->w + v4.w);
        }
        constexpr t_vec<type, 4> operator- (const t_vec<type, 4> &v4) const
        {
            return t_vec<type, 4>(this->x - v4.x, this->y - v4.y, this->z - v4.z, this->w - v4.w);
        }
        constexpr t_vec<type, 4> operator- () const
        {
            return t_vec<type, 4>(-this->x, -this->y, -this->z, -this->w);
        }
        constexpr t_vec<type, 4> operator* (const t_vec<type, 4> &v4) const
        {
            return t_vec<type, 4>(this->x * v4.x, this->y * v4.y, this->z * v4.z, this->w * v4.w);
        }
        constexpr t_vec<type, 4> operator* (type a) const
        {
            return t_vec<type, 4>(this->x * a, this->y * a, this->z * a, this->w * a);
        }
        constexpr t_vec<type, 4> operator/ (type a) const
        {
            return t_vec<type, 4>(this->x / a, this->y / a, this->z / a, this->w / a);
        }

        template<int cols>
        constexpr t_vec<type, cols> operator* (const t_mat<type, 4, cols> &m) const;

        constexpr t_vec<type, 4> &operator*= (const t_mat<type, 4, 4> &m);

        constexpr t_vec<type, 4> operator/ (const t_vec<type, 4> &v4) const
        {
            return t_vec<type, 4>(this->x / v4.x, this->y / v4.y, this->z / v4.z, this->w / v4.w);
        }
        constexpr t_vec<type, 4> &operator+= (const t_vec<type, 4> &v4)
        {
            this->x += v4.x;
            this->y += v4.y;
            this->z += v4.z;
            this->w += v4.w;
            return *this;
        }
        constexpr t_vec<type, 4> &operator-= (const t_vec<type, 4> &v4)
        {
            this->x -= v4.x;
            this->y -= v4.y;
            this->z -= v4.z;
            this->w -= v4.w;
            return *this;
        }
        constexpr t_vec<type, 4> &operator*= (const t_vec<type, 4> &v4)
        {
            this->x *= v4.x;
            this->y *= v4.y;
            this->z *= v4.z;
            this->w *= v4.w;
            return *this;
        }
        constexpr t_vec<type, 4> &operator*= (type a)
        {
            this->x *= a;
            this->y *= a;
            this->z *= a;
            this->w *= a;
            return *this;
        }
        constexpr t_vec<type, 4> &operator/= (type a)
        {
            this->x /= a;
            this->y /= a;
            this->z /= a;
            this->w /= a;
            return *this;
        }
        constexpr t_vec<type, 4> &operator/= (const t_vec<type, 4> &v4)
        {
            this->x /= v4.x;
            this->y /= v4.y;
            this->z /= v4.z;
            this->w /= v4.w;
            return *this;
        }
        union {
            struct {type x, y, z, w;};
            struct {type r, g, b, a;};
        };
    };
    

    typedef t_vec<float, 2> vec2 ;
    typedef t_vec<float, 3> vec3 ;
    typedef t_vec<float, 4> vec4 ;

    typedef t_vec<bool, 2> bvec2 ;
    typedef t_vec<bool, 3> bvec3 ;
    typedef t_vec<bool, 4> bvec4 ;

    typedef t_vec<int, 2> ivec2 ;
    typedef t_vec<int, 3> ivec3 ;
    typedef t_vec<int, 4> ivec4 ;

    typedef t_vec<unsigned int, 2> uvec2 ;
    typedef t_vec<unsigned int, 3> uvec3 ;
    typedef t_vec<unsigned int, 4> uvec4 ;
    
    typedef t_vec<double, 2> dvec2 ;
    typedef t_vec<double, 3> dvec3 ;
    typedef t_vec<double, 4> dvec4 ;
}


#include "mat.hpp"
        
namespace mygl
{
    template<typename type>
    template<int cols>
    constexpr t_vec<type, cols> t_vec<type, 2>::operator* (const t_mat<type, 2, cols> &m) const
    {
        t_vec<type, cols> r_vec;
        for(int c2 = 0; c2 < cols; c2++)
        {
            type value = 0;
            for(int c1 = 0; c1 < 2; c1++)
            {
                value += this->getValue(c1) * m.data[c1].getValue(c2);
            }
            r_vec[c2] = value;
        }
        return r_vec;
    }

    template<typename type>
    template<int cols>
    constexpr t_vec<type, cols> t_vec<type, 3>::operator* (const t_mat<type, 3, cols> &m) const
    {
        t_vec<type, cols> r_vec;
        for(int c2 = 0; c2 < cols; c2++)
        {
            type value = 0;
            for(int c1 = 0; c1 < 3; c1++)
            {
                value += this->getValue(c1) * m.data[c1].getValue(c2);
            }
            r_vec[c2] = value;
        }
        return r_vec;
    }


    template<typename type>
    template<int cols>
    constexpr t_vec<type, cols> t_vec<type, 4>::operator* (const t_mat<type, 4, cols> &m) const
    {
        t_vec<type, cols> r_vec;
        for(int c2 = 0; c2 < cols; c2++)
        {
            type value = 0;
            for(int c1 = 0; c1 < 4; c1++)
            {
                value += this->getValue(c1) * m.data[c1].getValue(c2);
            }
            r_vec[c2] = value;
        }
        return r_vec;
    }

    template<typename type>
    constexpr t_vec<type, 2> &t_vec<type, 2>::operator*= (const t_mat<type, 2, 2> &m)
    {
        *this = *this * m;
        return *this;
    }

    template<typename type>
    constexpr t_vec<type, 3> &t_vec<type, 3>::operator*= (const t_mat<type, 3, 3> &m)
    {
        *this = *this * m;
        return *this;
    }

    template<typename type>
    constexpr t_vec<type, 4> &t_vec<type, 4>::operator*= (const t_mat<type, 4, 4> &m)
    {
        *this = *this * m;
        return *this;
    }
}

#endif