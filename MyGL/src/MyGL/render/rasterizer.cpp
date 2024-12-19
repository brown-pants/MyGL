#include <MyGL/render/rasterizer.h>
#include <MyGL/math/funcs.hpp>

namespace mygl
{
    void Rasterizer::Line(std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> &results, 
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v1,
                        const std::pair<vec3, std::unordered_map<std::string, Var>> &v2)
    {
        bool flipY = false, swapXY = false;
        vec3 beginPos = v1.first, endPos = v2.first;
        std::unordered_map<std::string, Var> beginOut = v1.second, endOut = v2.second;
        if(beginPos.x > endPos.x)
        {
            vec3 tmp_pos = beginPos;
            beginPos = endPos;
            endPos = tmp_pos;
            auto tmp_out = beginOut;
            beginOut = endOut;
            endOut = tmp_out;
        }

        //frist point
        results.push_back(std::pair<vec3, std::unordered_map<std::string, Var>>(beginPos, beginOut));
        
        if(beginPos.y > endPos.y)
        {
            flipY = true;
            beginPos.y *= -1.0f;
            endPos.y *= -1.0f;
        }
        int dx = endPos.x - beginPos.x;
        int dy = endPos.y - beginPos.y;
        if(dy > dx)
        {
            swapXY = true;
            std::swap(beginPos.x, beginPos.y);
            std::swap(endPos.x, endPos.y);
            std::swap(dx, dy);
        }
        ivec2 curPos(beginPos.x, beginPos.y);
        int p = 2 * dy - dx;

        //starting from the second point
        for(int i = 0; i < dx; i++)
        {
            //raster
            ivec2 resultPos;
            if(p > 0){
                curPos.y += 1;
                p -= 2 * dx;
            }
            p += 2 * dy;
            curPos.x += 1;
            resultPos = curPos;
            if(swapXY == true){
                std::swap(resultPos.x, resultPos.y);
            }
            if(flipY == true){
                resultPos.y *= -1;
            }

            //get weight value
            float weight = 1.0f;
            if(beginPos.x != endPos.x){
                weight = 1.0f * (curPos.x - beginPos.x) / (endPos.x - beginPos.x);
            }
            else if(beginPos.y != endPos.y){
                weight = 1.0f * (curPos.y - beginPos.y) / (endPos.y - beginPos.y);
            }

            //interpolant z
            float resultZ;
            resultZ = weight * endPos.z + (1.0f - weight) * beginPos.z;

            //interpolant vertex shader out
            std::unordered_map<std::string, Var> resultOut;
            for(auto it : beginOut)
            {
                Var beginVar = it.second;
                Var endVar = endOut.find(it.first)->second;
                Var resultVar;
                if(beginVar.type() == MYGL_INT)
                {
                    resultVar = (int)(endVar.value<int>() * weight + beginVar.value<int>() * (1.0f - weight));
                }
                else if(beginVar.type() == MYGL_BYTE)
                {
                    resultVar = (char)(endVar.value<char>() * weight + beginVar.value<char>() * (1.0f - weight));
                }
                else if(beginVar.type() == MYGL_FLOAT)
                {
                    resultVar = endVar.value<float>() * weight + beginVar.value<float>() * (1.0f - weight);
                }
                else if(beginVar.type() == MYGL_DOUBLE)
                {
                    resultVar = endVar.value<double>() * weight + beginVar.value<double>() * (1.0f - weight);
                }
                else if(beginVar.type() == MYGL_FLOAT_VEC2)
                {
                    resultVar = endVar.value<vec2>() * weight + beginVar.value<vec2>() * (1.0f - weight);
                }
                else if(beginVar.type() == MYGL_FLOAT_VEC3)
                {
                    resultVar = endVar.value<vec3>() * weight + beginVar.value<vec3>() * (1.0f - weight);
                }
                else if(beginVar.type() == MYGL_FLOAT_VEC4)
                {
                    resultVar = endVar.value<vec4>() * weight + beginVar.value<vec4>() * (1.0f - weight);
                }
                resultOut.insert(std::pair<std::string, Var>(it.first,resultVar));
            }
            
            //push result
            results.push_back(std::pair<vec3, std::unordered_map<std::string, Var>>(vec3(resultPos.x, resultPos.y, resultZ), resultOut));

        }
    }

    void Rasterizer::Triangle(std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> &results, 
                            const std::pair<vec3, std::unordered_map<std::string, Var>> &v1,
                            const std::pair<vec3, std::unordered_map<std::string, Var>> &v2,
                            const std::pair<vec3, std::unordered_map<std::string, Var>> &v3)
    {
        vec3 pos1 = v1.first, pos2 = v2.first, pos3 = v3.first;
        //bounding box
        int box_left = pos1.x, box_right = pos1.x, box_up = pos1.y, box_bottom = pos1.y;
        if(pos2.x < box_left) box_left = pos2.x;
        if(pos3.x < box_left) box_left = pos3.x;
        if(pos2.x > box_right) box_right = pos2.x;
        if(pos3.x > box_right) box_right = pos3.x;
        if(pos2.y < box_bottom) box_bottom = pos2.y;
        if(pos3.y < box_bottom) box_bottom = pos3.y;
        if(pos2.y > box_up) box_up = pos2.y;
        if(pos3.y > box_up) box_up = pos3.y;

        //traverse the pixels inside bounding box
        for(int x = box_left; x < box_right; x++)
        {
            for(int y = box_bottom; y < box_up; y++)
            {
                vec3 p1p2 = pos2 - pos1;
                vec3 p2p3 = pos3 - pos2;
                vec3 p3p1 = pos1 - pos3;
                vec3 p1pxy = vec3(x, y, 1) - pos1;
                vec3 p2pxy = vec3(x, y, 1) - pos2;
                vec3 p3pxy = vec3(x, y, 1) - pos3;

                p1p2.z = 0.0f;
                p2p3.z = 0.0f;
                p3p1.z = 0.0f;
                p1pxy.z = 0.0f;
                p2pxy.z = 0.0f;
                p3pxy.z = 0.0f;
                
                vec3 p1p2_X_p1pxy = cross(p1p2, p1pxy);
                vec3 p2p3_X_p2pxy = cross(p2p3, p2pxy);
                vec3 p3p1_X_p3pxy = cross(p3p1, p3pxy);

                //whether the pixel are within the triangle
                bool sign1 = p1p2_X_p1pxy.z > 0.0f;
                bool sign2 = p2p3_X_p2pxy.z > 0.0f;
                bool sign3 = p3p1_X_p3pxy.z > 0.0f;
                if(sign1 == sign2 && sign2 == sign3)
                {
                    //S is the area of triangle with v1 v2 v3 vertices
                    float S = length(cross(p1p2, p3p1));
                    //barycentric coordinate(a, b, c)
                    float a = length(p2p3_X_p2pxy) / S;
                    float b = length(p3p1_X_p3pxy) / S;
                    float c = length(p1p2_X_p1pxy) / S;

                    //interpolant z
                    float resultZ;
                    resultZ = pos1.z * a + pos2.z * b + pos3.z * c;

                    //interpolant vertex shader out
                    std::unordered_map<std::string, Var> resultOut;
                    for(auto it : v1.second)
                    {
                        Var v1_out = it.second;
                        Var v2_out = v2.second.find(it.first)->second;
                        Var v3_out = v3.second.find(it.first)->second;
                        Var resultVar;
                        if(v1_out.type() == MYGL_INT)
                        {
                            resultVar = (int)(v1_out.value<int>() * a + v2_out.value<int>() * b + v3_out.value<int>() * c);
                        }
                        else if(v1_out.type() == MYGL_BYTE)
                        {
                            resultVar = (char)(v1_out.value<char>() * a + v2_out.value<char>() * b + v3_out.value<char>() * c);
                        }
                        else if(v1_out.type() == MYGL_FLOAT)
                        {
                            resultVar = v1_out.value<float>() * a + v2_out.value<float>() * b + v3_out.value<float>() * c;
                        }
                        else if(v1_out.type() == MYGL_DOUBLE)
                        {
                            resultVar = v1_out.value<double>() * a + v2_out.value<double>() * b + v3_out.value<double>() * c;
                        }
                        else if(v1_out.type() == MYGL_FLOAT_VEC2)
                        {
                            resultVar = v1_out.value<vec2>() * a + v2_out.value<vec2>() * b + v3_out.value<vec2>() * c;
                        }
                        else if(v1_out.type() == MYGL_FLOAT_VEC3)
                        {
                            resultVar = v1_out.value<vec3>() * a + v2_out.value<vec3>() * b + v3_out.value<vec3>() * c;
                        }
                        else if(v1_out.type() == MYGL_FLOAT_VEC4)
                        {
                            resultVar = v1_out.value<vec4>() * a + v2_out.value<vec4>() * b + v3_out.value<vec4>() * c;
                        }
                        resultOut.insert(std::pair<std::string, Var>(it.first,resultVar));
                    }
                    results.push_back(std::pair<vec3, std::unordered_map<std::string, Var>>(vec3(x, y, resultZ), resultOut));
                }
            }
        }
    }
    
}