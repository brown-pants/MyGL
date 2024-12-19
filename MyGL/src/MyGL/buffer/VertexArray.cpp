#include <MyGL/buffer/VertexArray.h>

namespace mygl
{
    VertexArray::VertexArray() : ebo(NULL) {}

    VertexArray::~VertexArray() {}

    void VertexArray::addVertexAttrib(Buffer &vbo, unsigned int index, int size, MyGLDataType type, bool normalized, size_t stride, const void *pointer)
    {
        auto iter = vas.find(&vbo);
        if(iter != vas.end()){
            iter->second.push_back(VertexAttrib(index, size, type, normalized, stride, pointer));
        }
        else{
            std::vector<VertexAttrib> arr;
            arr.push_back(VertexAttrib(index, size, type, normalized, stride, pointer));
            vas.insert(std::pair<Buffer *, std::vector<VertexAttrib>>(&vbo, arr));
        }
    }
        
    void VertexArray::setElementBuffer(Buffer &ebo)
    {
        this->ebo = &ebo;
    }
}
