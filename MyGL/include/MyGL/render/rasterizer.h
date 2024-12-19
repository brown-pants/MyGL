#ifndef __RASTERIZER_H__
#define __RASTERIZER_H__

#include "shader.h"

namespace mygl
{
    class Rasterizer
    {
    public:
        static void Line(std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> &results, 
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v1,
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v2);
                        
        static void Triangle(std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> &results, 
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v1,
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v2,
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v3);
    };
}

#endif