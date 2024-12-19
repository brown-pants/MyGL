#ifndef __MAT_HPP__
#define __MAT_HPP__
#include "vec.hpp"

namespace mygl
{
    template<typename type, int rows, int columns>
    struct t_mat{
        t_mat()
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    data[r][c] = 0;
                }
            }
        }
        t_mat(const t_mat<type, rows, columns> &m)
        {
            *this = m;
        }
        t_mat(type scalar)
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    if(r == c) data[r][c] = scalar;
                    else data[r][c] = 0;
                }
            }
        }
        constexpr t_mat<type, rows, columns> &operator= (const t_mat<type, rows, columns> &m)
        {
            for(int r = 0; r < 4; r ++)
            {
                for(int c = 0; c < 4; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        constexpr bool operator== (const t_mat<type, rows, columns> &m) const
        {
            for(int r = 0; r < rows; r++)
            {
                if(this->data[r] != m.data[r]) return false;
            }
            return true;
        }
        constexpr t_vec<type, columns> &operator[] (int i)
        {
            assert(i >= 0 && i < rows);
            return data[i];
        }
        constexpr t_mat<type, rows, columns> operator+ (const t_mat<type, rows, columns> &m) const
        {
            t_mat<type, rows, columns> r_mat;
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    r_mat[r][c]= this->data[r].getValue(c) + m.data[r].getValue(c);
                }
            }
            return r_mat;
        }
        constexpr t_mat<type, rows, columns> operator- (const t_mat<type, rows, columns> &m) const
        {
            t_mat<type, rows, columns> r_mat;
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    r_mat[r][c] = this->data[r].getValue(c) - m.data[r].getValue(c);
                }
            }
            return r_mat;
        }
        constexpr t_mat<type, rows, columns> operator- () const
        {
            t_mat<type, rows, columns> r_mat;
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    r_mat[r][c] = -this->data[r].getValue(c);
                }
            }
            return r_mat;
        }
        constexpr t_mat<type, rows, columns> operator/ (const t_mat<type, rows, columns> &m) const
        {
            t_mat<type, rows, columns> r_mat;
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    r_mat[r][c] = this->data[r].getValue(c) / m.data[r].getValue(c);
                }
            }
            return r_mat;
        }
        template<int cols>
        constexpr t_mat<type, rows, cols> operator* (const t_mat<type, columns, cols> &m) const
        {
            t_mat<type, rows, cols> r_mat;
            for(int r1 = 0; r1 < rows; r1++)
            {
                t_vec<type, cols> t_vec;
                for(int c2 = 0; c2 < cols; c2++)
                {
                    type value = 0;
                    for(int c1 = 0; c1 < columns; c1++)
                    {
                        value += this->data[r1].getValue(c1) * m.data[c1].getValue(c2);
                    }
                    t_vec[c2] = value;
                }
                r_mat[r1] = t_vec;
            }
            return r_mat;
        }
        constexpr t_vec<type, rows> operator* (const t_vec<type, columns> &v) const
        {
            t_vec<type, rows> r_vec;
            for(int r = 0; r < rows; r++)
            {
                type value = 0;
                for(int c = 0; c < columns; c++)
                {
                    value += this->data[r].getValue(c) * v.getValue(c);
                }
                r_vec[r] = value;
            }
            return r_vec;
        }
        constexpr t_mat<type, rows, columns> operator* (type a) const
        {
            t_vec<type, rows> r_mat;
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    r_mat[r].getValue(c) = this->data[r].getValue(c) * a;
                }
            }
            return r_mat;
        }
        constexpr t_mat<type, rows, columns> &operator*= (type a)
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    this->data[r][c] = this->data[r].getValue(c) * a;
                }
            }
            return *this;
        }
        constexpr t_mat<type, rows, rows> &operator*= (const t_mat<type, rows, rows> &m)
        {
            *this = t_mat<type, rows, rows>(m) * *this;
            return *this;
        }
        constexpr t_mat<type, rows, columns> &operator+= (const t_mat<type, rows, columns> &m)
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    this->data[r][c] += m.data[r].getValue(c);
                }
            }
            return *this;
        }
        constexpr t_mat<type, rows, columns> &operator-= (const t_mat<type, rows, columns> &m)
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    this->data[r][c] -= m.data[r].getValue(c);
                }
            }
            return *this;
        }
        constexpr t_mat<type, rows, columns> &operator/= (const t_mat<type, rows, columns> &m)
        {
            for(int r = 0; r < rows; r ++)
            {
                for(int c = 0; c < columns; c ++)
                {
                    this->data[r][c] /= m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_vec<type, columns> data[rows];
    };

    template<typename type>
    struct t_mat2x2 : t_mat<type, 2, 2>{
        constexpr t_mat2x2<type> &operator= (const t_mat<type, 2, 2> &m)
        {
            for(int r = 0; r < 2; r ++)
            {
                for(int c = 0; c < 2; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat2x2() : t_mat<type, 2, 2>() {}
        t_mat2x2(const t_mat<type, 2, 2> &m) : t_mat<type, 2, 2>(m) {}
        t_mat2x2(type scalar) : t_mat<type, 2, 2>(scalar) {}
        t_mat2x2(type x1, type y1,
                 type x2, type y2)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[1].x = x2;
            this->data[1].y = y2;
        }
    };

    template<typename type>
    struct t_mat2x3 : t_mat<type, 2, 3>{
        constexpr t_mat2x3<type> &operator= (const t_mat<type, 2, 3> &m)
        {
            for(int r = 0; r < 2; r ++)
            {
                for(int c = 0; c < 3; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat2x3() : t_mat<type, 2, 3>() {}
        t_mat2x3(const t_mat<type, 2, 3> &m) : t_mat<type, 2, 3>(m) {}
        t_mat2x3(type scalar) : t_mat<type, 2, 3>(scalar) {}
        t_mat2x3(type x1, type y1, type z1, 
                 type x2, type y2, type z2)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
        }
    };

    template<typename type>
    struct t_mat2x4 : t_mat<type, 2, 4>{
        constexpr t_mat2x4<type> &operator= (const t_mat<type, 2, 4> &m)
        {
            for(int r = 0; r < 2; r ++)
            {
                for(int c = 0; c < 4; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat2x4() : t_mat<type, 2, 4>() {}
        t_mat2x4(const t_mat<type, 2, 4> &m) : t_mat<type, 2, 4>(m) {}
        t_mat2x4(type scalar) : t_mat<type, 2, 4>(scalar) {}
        t_mat2x4(type x1, type y1, type z1, type w1,
                 type x2, type y2, type z2, type w2)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[0].w = w1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
            this->data[1].w = w2;
        }
    };

    template<typename type>
    struct t_mat3x2 : t_mat<type, 3, 2>{
        constexpr t_mat3x2<type> &operator= (const t_mat<type, 3, 2> &m)
        {
            for(int r = 0; r < 3; r ++)
            {
                for(int c = 0; c < 2; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat3x2() : t_mat<type, 3, 2>() {}
        t_mat3x2(const t_mat<type, 3, 2> &m) : t_mat<type, 3, 2>(m) {}
        t_mat3x2(type scalar) : t_mat<type, 3, 2>(scalar) {}
        t_mat3x2(type x1, type y1,
                 type x2, type y2,
                 type x3, type y3)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[2].x = x3;
            this->data[2].y = y3;
        }
    };

    template<typename type>
    struct t_mat3x3 : t_mat<type, 3, 3>{
        constexpr t_mat3x3<type> &operator= (const t_mat<type, 3, 3> &m)
        {
            for(int r = 0; r < 3; r ++)
            {
                for(int c = 0; c < 3; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat3x3() : t_mat<type, 3, 3>() {}
        t_mat3x3(const t_mat<type, 3, 3> &m) : t_mat<type, 3, 3>(m) {}
        t_mat3x3(type scalar) : t_mat<type, 3, 3>(scalar) {}
        t_mat3x3(type x1, type y1, type z1,
                 type x2, type y2, type z2,
                 type x3, type y3, type z3)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
            this->data[2].x = x3;
            this->data[2].y = y3;
            this->data[2].z = z3;
        }
    };

    template<typename type>
    struct t_mat3x4 : t_mat<type, 3, 4>{
        constexpr t_mat3x4<type> &operator= (const t_mat<type, 3, 4> &m)
        {
            for(int r = 0; r < 3; r ++)
            {
                for(int c = 0; c < 4; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat3x4() : t_mat<type, 3, 4>() {}
        t_mat3x4(const t_mat<type, 3, 4> &m) : t_mat<type, 3, 4>(m) {}
        t_mat3x4(type scalar) : t_mat<type, 3, 4>(scalar) {}
        t_mat3x4(type x1, type y1, type z1, type w1, 
                 type x2, type y2, type z2, type w2,
                 type x3, type y3, type z3, type w3)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[0].w = w1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
            this->data[1].w = w2;
            this->data[2].x = x3;
            this->data[2].y = y3;
            this->data[2].z = z3;
            this->data[2].w = w3;
        }
    };

    template<typename type>
    struct t_mat4x2 : t_mat<type, 4, 2>{
        constexpr t_mat4x2<type> &operator= (const t_mat<type, 4, 2> &m)
        {
            for(int r = 0; r < 4; r ++)
            {
                for(int c = 0; c < 2; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat4x2() : t_mat<type, 4, 2>() {}
        t_mat4x2(const t_mat<type, 4, 2> &m) : t_mat<type, 4, 2>(m) {}
        t_mat4x2(type scalar) : t_mat<type, 4, 2>(scalar) {}
        t_mat4x2(type x1, type y1,
                 type x2, type y2,
                 type x3, type y3,
                 type x4, type y4)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[2].x = x3;
            this->data[2].y = y3;
            this->data[3].x = x4;
            this->data[3].y = y4;
        }
    };

    template<typename type>
    struct t_mat4x3 : t_mat<type, 4, 3>{
        constexpr t_mat4x3<type> &operator= (const t_mat<type, 4, 3> &m)
        {
            for(int r = 0; r < 4; r ++)
            {
                for(int c = 0; c < 3; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat4x3() : t_mat<type, 4, 3>() {}
        t_mat4x3(const t_mat<type, 4, 3> &m) : t_mat<type, 4, 3>(m) {}
        t_mat4x3(type scalar) : t_mat<type, 4, 3>(scalar) {}
        t_mat4x3(type x1, type y1, type z1,
                 type x2, type y2, type z2,
                 type x3, type y3, type z3,
                 type x4, type y4, type z4)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
            this->data[2].x = x3;
            this->data[2].y = y3;
            this->data[2].z = z3;
            this->data[3].x = x4;
            this->data[3].y = y4;
            this->data[3].z = z4;
        }
    };

    template<typename type>
    struct t_mat4x4 : t_mat<type, 4, 4>{
        constexpr t_mat4x4<type> &operator= (const t_mat<type, 4, 4> &m)
        {
            for(int r = 0; r < 4; r ++)
            {
                for(int c = 0; c < 4; c ++)
                {
                    this->data[r][c] = m.data[r].getValue(c);
                }
            }
            return *this;
        }
        t_mat4x4() : t_mat<type, 4, 4>() {}
        t_mat4x4(const t_mat<type, 4, 4> &m) : t_mat<type, 4, 4>(m) {}
        t_mat4x4(type scalar) : t_mat<type, 4, 4>(scalar) {}
        t_mat4x4(type x1, type y1, type z1, type w1,
                 type x2, type y2, type z2, type w2,
                 type x3, type y3, type z3, type w3,
                 type x4, type y4, type z4, type w4)
        {
            this->data[0].x = x1;
            this->data[0].y = y1;
            this->data[0].z = z1;
            this->data[0].w = w1;
            this->data[1].x = x2;
            this->data[1].y = y2;
            this->data[1].z = z2;
            this->data[1].w = w2;
            this->data[2].x = x3;
            this->data[2].y = y3;
            this->data[2].z = z3;
            this->data[2].w = w3;
            this->data[3].x = x4;
            this->data[3].y = y4;
            this->data[3].z = z4;
            this->data[3].w = w4;
        }
    };

    typedef t_mat2x2<float> mat2;
    typedef t_mat2x3<float> mat2x3;
    typedef t_mat2x4<float> mat2x4;

    typedef t_mat3x2<float> mat3x2;
    typedef t_mat3x3<float> mat3;
    typedef t_mat3x4<float> mat3x4;

    typedef t_mat4x2<float> mat4x2;
    typedef t_mat4x3<float> mat4x3;
    typedef t_mat4x4<float> mat4;

    typedef t_mat2x2<bool> bmat2;
    typedef t_mat2x3<bool> bmat2x3;
    typedef t_mat2x4<bool> bmat2x4;

    typedef t_mat3x2<bool> bmat3x2;
    typedef t_mat3x3<bool> bmat3;
    typedef t_mat3x4<bool> bmat3x4;

    typedef t_mat4x2<bool> bmat4x2;
    typedef t_mat4x3<bool> bmat4x3;
    typedef t_mat4x4<bool> bmat4;

    typedef t_mat2x2<int> imat2;
    typedef t_mat2x3<int> imat2x3;
    typedef t_mat2x4<int> imat2x4;

    typedef t_mat3x2<int> imat3x2;
    typedef t_mat3x3<int> imat3;
    typedef t_mat3x4<int> imat3x4;

    typedef t_mat4x2<int> imat4x2;
    typedef t_mat4x3<int> imat4x3;
    typedef t_mat4x4<int> imat4;

    typedef t_mat2x2<unsigned int> umat2;
    typedef t_mat2x3<unsigned int> umat2x3;
    typedef t_mat2x4<unsigned int> umat2x4;

    typedef t_mat3x2<unsigned int> umat3x2;
    typedef t_mat3x3<unsigned int> umat3;
    typedef t_mat3x4<unsigned int> umat3x4;

    typedef t_mat4x2<unsigned int> umat4x2;
    typedef t_mat4x3<unsigned int> umat4x3;
    typedef t_mat4x4<unsigned int> umat4;

    typedef t_mat2x2<double> dmat2;
    typedef t_mat2x3<double> dmat2x3;
    typedef t_mat2x4<double> dmat2x4;

    typedef t_mat3x2<double> dmat3x2;
    typedef t_mat3x3<double> dmat3;
    typedef t_mat3x4<double> dmat3x4;

    typedef t_mat4x2<double> dmat4x2;
    typedef t_mat4x3<double> dmat4x3;
    typedef t_mat4x4<double> dmat4;
}

#endif