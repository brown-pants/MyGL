#ifndef __TEXTURE2D_H__
#define __TEXTURE2D_H__
#include "../math/vec.hpp"

namespace mygl
{
    class Texture2D
    {
    public:
        friend vec4 texture(Texture2D *, vec2);

        constexpr Texture2D &operator= (Texture2D &) = delete;
        Texture2D(Texture2D &) = delete;

        Texture2D();
        Texture2D(unsigned char *data, int width, int height, int channels);
        ~Texture2D();

        void setData(unsigned char *data, int width, int height, int channels);
        void deletebuf();

        inline const unsigned char *getbuf() const { return buffer; }
        
    private:
        unsigned char *buffer;
        int width, height, channels;
    };
    
    vec4 texture(Texture2D *tex, vec2 uv);
}

#endif