#ifndef __BUFFERS_H__
#define __BUFFERS_H__
#include <cstddef>
#include "../math/vec.hpp"

namespace mygl
{
    class Buffer //VertexBuffer or ElementBuffer
    {
    public:
        constexpr Buffer &operator= (Buffer &) = delete;
        Buffer(Buffer &) = delete;

        Buffer();
        Buffer(size_t size, void *data = NULL);
        ~Buffer();

        void deletebuf();
        void setData(size_t size, void *data = NULL);
        void subData(size_t offset, size_t size, void *data);

        inline const void *getbuf() const { return buffer; }
        inline size_t size() const { return data_size; }

    private:
        void *buffer;
        size_t data_size;
    };

    struct FrameBuffer
    {
        unsigned char *ColorBuffer;
        float *DepthBuffer;
    };
}

#endif