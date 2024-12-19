#include <MyGL/texture/texture2d.h>
#include <memory.h>
#include <math.h>

namespace mygl
{
    Texture2D::Texture2D() : buffer(NULL), width(0), height(0), channels(0) {}

    Texture2D::Texture2D(unsigned char *data, int width, int height, int channels) : width(width), height(height), channels(channels)
    {
        assert(data != NULL);
        buffer = new unsigned char[width * height * channels];
        memcpy(buffer, data, width * height * channels * sizeof(unsigned char));
    }

    Texture2D::~Texture2D() { deletebuf(); }
    
    void Texture2D::setData(unsigned char *data, int width, int height, int channels)
    {
        assert(data != NULL);
        deletebuf();
        this->width = width;
        this->height = height;
        this->channels = channels;
        this->buffer = new unsigned char[width * height * channels];
        memcpy(buffer, data, width * height * channels * sizeof(unsigned char));
    }

    void Texture2D::deletebuf()
    {
        if(buffer != NULL) 
        {
            delete buffer;
            buffer = NULL;
        }
    }

    vec4 texture(Texture2D *tex, vec2 uv)
    {
        int x = uv.x * tex->width;
        int y = uv.y * tex->height;
        unsigned char r = tex->buffer[y * tex->width * tex->channels + x * tex->channels];
        unsigned char g = tex->buffer[y * tex->width * tex->channels + x * tex->channels + 1];
        unsigned char b = tex->buffer[y * tex->width * tex->channels + x * tex->channels + 2];
        unsigned char a = tex->channels == 4 ? tex->buffer[y * tex->width * tex->channels + x * tex->channels + 3] : 255;

        return vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
    }
}