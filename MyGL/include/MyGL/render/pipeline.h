#ifndef __PIPELINE_H__
#define __PIPELINE_H__

#include "../buffer/buffers.h"
#include "shader.h"

namespace mygl
{
    class Pipeline
    {
    public:
        static void DrawPixel(FrameBuffer *fbo, int width, int height, int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        static void Render(MyGLDrawMode mode, FrameBuffer *fbo, int width, int height, mat4 &viewportMat, Shader *shader, std::vector<std::unordered_map<int, Var>> &vertices, std::unordered_map<unsigned int, bool> &enabled);
    };
}

#endif