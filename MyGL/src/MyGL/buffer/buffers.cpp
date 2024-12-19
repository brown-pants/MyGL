#include <MyGL/buffer/buffers.h>
#include <memory.h>

namespace mygl
{
    Buffer::Buffer() : buffer(NULL), data_size(0) {}
    Buffer::Buffer(size_t size, void *data) : buffer(new char[size]), data_size(size) 
    { 
        if(data == NULL) memset(buffer, 0, size);
        else memcpy(buffer, data, size);
    }
    Buffer::~Buffer() { deletebuf(); }
    
    void Buffer::deletebuf()
    {
        if(buffer != NULL)
        {
            delete static_cast<char *>(buffer);
            buffer = NULL;
        }
    }

    void Buffer::setData(size_t size, void *data)
    {
        deletebuf();
        this->data_size = size;
        buffer = new char[size];
        if(data == NULL) memset(buffer, 0, size);
        else memcpy(buffer, data, size);
    }
    
    void Buffer::subData(size_t offset, size_t size, void *data)
    {
        memcpy(static_cast<char *>(buffer) + offset, data, size);
    }
}