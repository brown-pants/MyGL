#ifndef __MYGL_H__
#define __MYGL_H__
/*
    MyGL uses right-hand coordinate system.
         y
         |     
         |_____ x
        /
       z
*/
//enum
#include "enum/MyGLEnum.h"

//math
#include "math/vec.hpp"
#include "math/mat.hpp"
#include "math/funcs.hpp"
#include "math/transform.hpp"

//buffer
#include "buffer/buffers.h"
#include "buffer/VertexArray.h"

//render
#include "render/shader.h"
#include "render/pipeline.h"
#include "render/renderer.h"
#include "render/rasterizer.h"

//texture
#include "texture/texture2d.h"
#include "texture/textureCubeMap.h"

//debug
#include "debug/debug.hpp"

#endif