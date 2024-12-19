#include <MyGL/render/renderer.h>
#include <MyGL/buffer/VertexArray.h>
#include <MyGL/render/pipeline.h>

#include <math.h>
#include <assert.h>
#include <iostream>

namespace mygl
{
    Renderer::Renderer(FrameBuffer &fbo, int screen_width, int screen_height) : vao(NULL), shader(NULL), fbo(&fbo), screen_width(screen_width), screen_height(screen_height) 
    {
        enabled[MYGL_DEPTH_TEST] = false;
    }

    Renderer::~Renderer() {}

    void Renderer::Clear(unsigned int mask)
    {
        if((mask >> 14 & 1 ) == 1)
        {
            for(int x = 0; x < screen_width; x++)
            {
                for(int y = 0; y < screen_height; y++)
                {
                    Pipeline::DrawPixel(fbo, screen_width, screen_height, x, y, round(255 * clearColor.r), round(255 * clearColor.g), round(255 * clearColor.b), round(255 * clearColor.a));
                }
            }
        }
        if((mask >> 8 & 1) == 1)
        {
            for(int y = 0; y < screen_height; y++)
            {
                for(int x = 0; x < screen_width; x++)
                {
                    fbo->DepthBuffer[y * screen_width + x] = -1.0f;
                }
            }
        }
        if((mask >> 10 & 1) == 1)
        {
            //std::cout << "clear stencil buffer" << std::endl;
        }
    }
    void Renderer::ClearColor(float r, float g, float b, float a)
    {
        clearColor.r = r; clearColor.g = g; clearColor.b = b; clearColor.a = a;
    }

    void Renderer::viewport(int x, int y, int width, int height)
    {
        viewportMat[0] = vec4(width / 2, 0, 0, width / 2 + x);
        viewportMat[1] = vec4(0, height / 2, 0, height / 2 + y);
        viewportMat[2] = vec4(0, 0, 0.5, 0.5);//z -> (0, 1)
        viewportMat[3] = vec4(0, 0, 0, 1);
    }

    void Renderer::getVertexArray(VertexArray *vao, int frist, int vertex_count, std::vector<std::unordered_map<int, Var>> &array)
    {
        std::vector<std::pair<int, Var>> all_layout;
        int indices_count = 0;

        //deal of vao
        for(auto iter : vao->vas)
        {
            Buffer *vbo = iter.first;
            for(auto it : iter.second)
            {
                //just supported type(float vec1 vec2 vec3 vec4)
                assert(it.type == MYGL_FLOAT && it.size >=1 && it.size <=4);
                
                indices_count++;

                const void *buf_p = (const void *)((const char *)vbo->getbuf() + (intptr_t)it.pointer);//find buffer pointer
                buf_p = (const void *)((const char *)buf_p + frist * it.stride);//find frist data pointer
                
                for(int i = 0; i < vertex_count; i++)
                {
                    Var var;
                    if(it.type == MYGL_FLOAT && it.size == 1) 
                        var = *(float *)buf_p;
                    else if(it.type == MYGL_FLOAT && it.size == 2)
                        var = vec2(*(float *)buf_p, *((float *)(buf_p) + 1));
                    else if(it.type == MYGL_FLOAT && it.size == 3)
                        var = vec3(*(float *)buf_p, *((float *)(buf_p) + 1), *((float *)(buf_p) + 2));
                    else if(it.type == MYGL_FLOAT && it.size == 4)
                        var = vec4(*(float *)buf_p, *((float *)(buf_p) + 1), *((float *)(buf_p) + 2), *((float *)(buf_p) + 3));

                    all_layout.push_back(std::pair<int, Var>(it.index, var));
                    buf_p = (const void *)((const char *)buf_p + it.stride);//buf_p += stride
                }
            }
        }

        for(int i = 0; i < vertex_count; i++)
        {
            std::unordered_map<int, Var> vertex;
            for(int j = i; j < indices_count * vertex_count; j += vertex_count)
            {
                vertex.insert(all_layout[j]);
            }
            array.push_back(vertex);
        }
    }

    void Renderer::drawArrays(MyGLDrawMode mode, int frist, int count)
    {
        assert(vao != NULL && shader != NULL);
        
        std::vector<std::unordered_map<int, Var>> vertices;
        getVertexArray(vao, frist, count, vertices);
        Pipeline::Render(mode, fbo, screen_width, screen_height, viewportMat, shader, vertices, enabled);
    }

    void Renderer::drawElement(MyGLDrawMode mode, int count, MyGLDataType type, const void *indices)
    {
        assert(type == MYGL_UNSIGNED_INT);
        assert(vao != NULL && shader != NULL);
        assert(vao->ebo != NULL || indices != NULL);

        std::vector<std::unordered_map<int, Var>> vertex_array;
        if(vao->vas.size() != 0)
            getVertexArray(vao, 0, vao->vas.begin()->first->size() / vao->vas.begin()->second.begin()->stride, vertex_array);
        
        unsigned int *index_array;
        if(vao->ebo != NULL){
            index_array = (unsigned int *)((char *)vao->ebo->getbuf() + (intptr_t)indices);
        }
        else{
            index_array = (unsigned int *)indices;
        }

        std::vector<std::unordered_map<int, Var>> vertices;
        for(int i = 0; i < count; i++)
        {
            vertices.push_back(vertex_array[index_array[i]]);
        }
        Pipeline::Render(mode, fbo, screen_width, screen_height, viewportMat, shader, vertices, enabled);
        
    }
}