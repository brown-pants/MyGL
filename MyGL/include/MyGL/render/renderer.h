#ifndef __RENDERER_H__
#define __RENDERER_H__
#include "../buffer/VertexArray.h"
#include "../buffer/buffers.h"
#include "../enum/MyGLEnum.h"
#include "shader.h"

namespace mygl
{
    class Renderer
    {
    public:
        Renderer() = delete;
        Renderer(FrameBuffer &fbo, int screen_width = 800, int screen_height = 600);
        ~Renderer();

        void Clear(unsigned int mask);
        void ClearColor(float r, float g, float b, float a);

        inline void enable(MyGLEnableValue cap) { enabled[cap] = true; }
        inline void disable(MyGLEnableValue cap) { enabled[cap] = false; }

        inline void bindFrameBuffer(FrameBuffer &fbo) { this->fbo = &fbo; }
        inline void bindVertexArray(VertexArray &vao) { this->vao = &vao; }
        inline void bindShader(Shader &shader) { this->shader = &shader; }
        
        void viewport(int x, int y, int width, int height);
        inline void screenChanged(int width, int height) {screen_width = width; screen_height = height;}

        void drawArrays(MyGLDrawMode mode, int frist, int count);
        void drawElement(MyGLDrawMode mode, int count, MyGLDataType type, const void *indices);

    private:
        void getVertexArray(VertexArray *vao, int frist, int vertex_count, std::vector<std::unordered_map<int, Var>> &array);

        FrameBuffer *fbo;
        VertexArray *vao;
        Shader *shader;
        vec4 clearColor;
        int screen_width;
        int screen_height;
        mat4 viewportMat;

        std::unordered_map<unsigned int, bool> enabled;
    };
}

#endif