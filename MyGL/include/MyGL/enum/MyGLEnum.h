#ifndef __MYGLENUM_H__
#define __MYGLENUM_H__

    enum MyGLDataType
    {
        MYGL_BYTE           = 0x1400,
        MYGL_UNSIGNED_BYTE  = 0x1401,
        MYGL_SHORT          = 0x1402,
        MYGL_UNSIGNED_SHORT = 0x1403,
        MYGL_INT            = 0x1404,
        MYGL_UNSIGNED_INT   = 0x1405,
        MYGL_FLOAT          = 0x1406,
        MYGL_BOOL           = 0x8B56,
        MYGL_DOUBLE         = 0x140A,
        MYGL_FLOAT_VEC2     = 0x8B50,
        MYGL_FLOAT_VEC3     = 0x8B51,
        MYGL_FLOAT_VEC4     = 0x8B52,
        MYGL_FLOAT_MAT2     = 0x8B5A,
        MYGL_FLOAT_MAT3     = 0x8B5B,
        MYGL_FLOAT_MAT4     = 0x8B5C

    };

    enum MyGLBufferType
    {
        MYGL_COLOR_BUFFER_BIT   = 0x00004000,
        MYGL_DEPTH_BUFFER_BIT   = 0x00000100,
        MYGL_STENCIL_BUFFER_BIT = 0x00000400
    };

    enum MyGLTextureType
    {
        MYGL_TEXTURE_1D       = 0x0DE0,
        MYGL_TEXTURE_2D       = 0x0DE1,
        MYGL_TEXTURE_CUBE_MAP = 0x8513
    };

    enum MyGLDrawMode
    {
        MYGL_POINTS = 0x0000,
        MYGL_LINES = 0x0001,
        MYGL_LINE_LOOP = 0x0002,
        MYGL_LINE_STRIP = 0x0003,
        MYGL_TRIANGLES = 0x0004,
        MYGL_TRIANGLE_STRIP = 0x0005,
        MYGL_TRIANGLE_FAN = 0x0006
    };

    enum MyGLEnableValue
    {
        MYGL_DEPTH_TEST = 0x0B71
    };

#endif