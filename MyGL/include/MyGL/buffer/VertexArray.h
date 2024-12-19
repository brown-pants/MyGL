#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__

#include "buffers.h"
#include "../enum/MyGLEnum.h"
#include <vector>
#include <map>

namespace mygl
{
    class VertexArray
    {
    public:
        friend class Debug;
        friend class Renderer;

        constexpr VertexArray &operator= (VertexArray &) = delete;
        VertexArray(VertexArray &) = delete;

        VertexArray();
        ~VertexArray();
        
        void addVertexAttrib(Buffer &vbo, unsigned int index, int size, MyGLDataType type, bool normalized, size_t stride, const void *pointer);
        void setElementBuffer(Buffer &ebo);

    private:
        struct VertexAttrib{
            VertexAttrib(unsigned int index, int size, MyGLDataType type, bool normalized, size_t stride, const void *pointer)
            :index(index), size(size), type(type), normalized(normalized), stride(stride), pointer(pointer) {}
            unsigned int index;
            int size;
            MyGLDataType type;
            bool normalized;
            size_t stride;
            const void *pointer;
        };
        std::map<Buffer *, std::vector<VertexAttrib>> vas;
        Buffer *ebo;
    };
}

#endif