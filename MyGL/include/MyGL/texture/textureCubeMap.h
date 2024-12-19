#ifndef __TEXTURECUBEMAP_H__
#define __TEXTURECUBEMAP_H__
#include "../math/vec.hpp"

namespace mygl
{
    class TextureCubeMap
    {
    public:
        friend vec4 texture(TextureCubeMap *, vec3);

        TextureCubeMap();
        ~TextureCubeMap();
        
    private:
    };

    vec4 texture(TextureCubeMap *tex, vec3 uvw);
}

#endif