#include <MyGL/render/pipeline.h>
#include <MyGL/render/rasterizer.h>
#include <math.h>

namespace mygl
{
    void Pipeline::DrawPixel(FrameBuffer *fbo, int width, int height, int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        fbo->ColorBuffer[y * width * 4 + x * 4] = r;
        fbo->ColorBuffer[y * width * 4 + x * 4 + 1] = g;
        fbo->ColorBuffer[y * width * 4 + x * 4 + 2] = b;
        fbo->ColorBuffer[y * width * 4 + x * 4 + 3] = a;
    }

    void Pipeline::Render(MyGLDrawMode mode, FrameBuffer *fbo, int width, int height, mat4 &viewportMat, Shader *shader, std::vector<std::unordered_map<int, Var>> &vertices, std::unordered_map<unsigned int, bool> &enabled)
    {
        auto drawLine = [&](std::unordered_map<int, mygl::Var> &v1, std::unordered_map<int, mygl::Var> &v2){
            vec4 mygl_Position[2];
            std::unordered_map<std::string, Var> vertexShader_out[2];
            shader->vs(mygl_Position[0], v1, shader->uniform, vertexShader_out[0]);
            shader->vs(mygl_Position[1], v2, shader->uniform, vertexShader_out[1]);
            mygl_Position[0] /= mygl_Position[0].w;
            mygl_Position[1] /= mygl_Position[1].w;
            for(int i = 0; i < 2; i++)
            {//clip vertices
                if(mygl_Position[i].x >= -1.0f && mygl_Position[i].x <= 1.0f && 
                   mygl_Position[i].y >= -1.0f && mygl_Position[i].y <= 1.0f && 
                   mygl_Position[i].z >= -1.0f && mygl_Position[i].z <= 1.0f) break;
                else if(i == 1) return;
            }
            vec3 screenPos[2] = { vec3(viewportMat * mygl_Position[0]),
                                  vec3(viewportMat * mygl_Position[1]) };
            std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> results;
            Rasterizer::Line(results, std::pair<vec3, std::unordered_map<std::string, Var>>(screenPos[0], vertexShader_out[0]),
                                      std::pair<vec3, std::unordered_map<std::string, Var>>(screenPos[1], vertexShader_out[1]));
            for(auto it : results)
            {
                if(it.first.x < 0.0f || it.first.x >= width || 
                   it.first.y < 0.0f || it.first.y >= height || 
                   it.first.z < 0.0f || it.first.z > 1.0f) continue;
                bool discard = false;
                vec3 pos = it.first;
                vec4 mygl_FragColor, mygl_FragCoord;
                if(enabled[MYGL_DEPTH_TEST] == true)
                {
                    if(pos.z > fbo->DepthBuffer[(int)pos.y * width + (int)pos.x])
                        fbo->DepthBuffer[(int)pos.y * width + (int)pos.x] = pos.z;
                    else continue;
                }
                mygl_FragCoord = vec4(pos, 1.0f);
                shader->fs(mygl_FragColor, mygl_FragCoord, shader->uniform, it.second, discard);
                if(!discard)
                {
                    DrawPixel(fbo, width, height, pos.x, pos.y, 
                    round(255 * mygl_FragColor.r), round(255 * mygl_FragColor.g),
                    round(255 * mygl_FragColor.b), round(255 * mygl_FragColor.a));
                }
            }
        };

        auto drawTriangle = [&](std::unordered_map<int, mygl::Var> &v1, std::unordered_map<int, mygl::Var> &v2, std::unordered_map<int, mygl::Var> &v3){
            vec4 mygl_Position[3];
            std::unordered_map<std::string, Var> vertexShader_out[3];
            shader->vs(mygl_Position[0], v1, shader->uniform, vertexShader_out[0]);
            shader->vs(mygl_Position[1], v2, shader->uniform, vertexShader_out[1]);
            shader->vs(mygl_Position[2], v3, shader->uniform, vertexShader_out[2]);
            mygl_Position[0] /= mygl_Position[0].w;
            mygl_Position[1] /= mygl_Position[1].w;
            mygl_Position[2] /= mygl_Position[2].w;
            for(int i = 0; i < 3; i++)
            {//clip vertices
                if(mygl_Position[i].x >= -1.0f && mygl_Position[i].x <= 1.0f && 
                   mygl_Position[i].y >= -1.0f && mygl_Position[i].y <= 1.0f && 
                   mygl_Position[i].z >= -1.0f && mygl_Position[i].z <= 1.0f) break;
                else if(i == 2) return;
            }
            vec3 screenPos[3] = { vec3(viewportMat * mygl_Position[0]),
                                  vec3(viewportMat * mygl_Position[1]),
                                  vec3(viewportMat * mygl_Position[2]) };
            std::vector<std::pair<vec3, std::unordered_map<std::string, Var>>> results;
            Rasterizer::Triangle(results, std::pair<vec3, std::unordered_map<std::string, Var>>(screenPos[0], vertexShader_out[0]),
                                          std::pair<vec3, std::unordered_map<std::string, Var>>(screenPos[1], vertexShader_out[1]),
                                          std::pair<vec3, std::unordered_map<std::string, Var>>(screenPos[2], vertexShader_out[2]));
            for(auto it : results)
            {
                if(it.first.x < 0.0f || it.first.x >= width || 
                   it.first.y < 0.0f || it.first.y >= height || 
                   it.first.z < 0.0f || it.first.z > 1.0f) continue;
                bool discard = false;
                vec3 pos = it.first;
                vec4 mygl_FragColor, mygl_FragCoord;
                if(enabled[MYGL_DEPTH_TEST] == true)
                {
                    if(pos.z > fbo->DepthBuffer[(int)pos.y * width + (int)pos.x])
                        fbo->DepthBuffer[(int)pos.y * width + (int)pos.x] = pos.z;
                    else continue;
                }
                mygl_FragCoord = vec4(pos, 1.0f);
                shader->fs(mygl_FragColor, mygl_FragCoord, shader->uniform, it.second, discard);
                if(!discard)
                {
                    DrawPixel(fbo, width, height, pos.x, pos.y, 
                    round(255 * mygl_FragColor.r),round(255 * mygl_FragColor.g), 
                    round(255 * mygl_FragColor.b),round(255 * mygl_FragColor.a));
                }
            }
        };
        
        if(mode == MYGL_POINTS)
        {
            for(auto it : vertices)
            {
                bool discard = false;
                vec4 mygl_Position, mygl_FragColor, mygl_FragCoord;
                std::unordered_map<std::string, Var> vertexShader_out;
                shader->vs(mygl_Position, it, shader->uniform, vertexShader_out);
                mygl_Position /= mygl_Position.w;
                if(mygl_Position.x < 0.0f || mygl_Position.x >= width || 
                   mygl_Position.y < 0.0f || mygl_Position.y >= height || 
                   mygl_Position.z < 0.0f || mygl_Position.z > 1.0f) continue;
                mygl_FragCoord = viewportMat * mygl_Position;
                vec3 screenPos = vec3(mygl_FragCoord);
                if(enabled[MYGL_DEPTH_TEST] == true)
                {
                    if(screenPos.z > fbo->DepthBuffer[(int)screenPos.y * width + (int)screenPos.x])
                        fbo->DepthBuffer[(int)screenPos.y * width + (int)screenPos.x] = screenPos.z;
                    else continue;
                }
                shader->fs(mygl_FragColor, mygl_FragCoord, shader->uniform, vertexShader_out, discard);
                if(!discard) 
                {
                    DrawPixel(fbo, width, height, screenPos.x, screenPos.y, 
                    round(255 * mygl_FragColor.r), round(255 * mygl_FragColor.g), 
                    round(255 * mygl_FragColor.b), round(255 * mygl_FragColor.a));
                }
            }
        }
        else if(mode == MYGL_LINES)
        {
            for(auto it = vertices.begin(); it < vertices.end() && (it + 1) < vertices.end(); it += 2)
            {
                drawLine(*it, *(it + 1));
            }
        }
        else if(mode == MYGL_LINE_STRIP)
        {
            for(auto it = vertices.begin() + 1; it < vertices.end(); it ++)
            {
                drawLine(*(it - 1), *it);
            }
        }
        else if(mode == MYGL_LINE_LOOP)
        {
            for(auto it = vertices.begin() + 1; it < vertices.end(); it ++)
            {
                drawLine(*(it - 1), *it);
            }
            drawLine(*(vertices.rbegin()), *(vertices.begin()));
        }
        else if(mode == MYGL_TRIANGLES)
        {
            for(auto it = vertices.begin(); it < vertices.end() && (it + 1) < vertices.end() && (it + 2) < vertices.end(); it += 3)
            {
                drawTriangle(*it, *(it + 1), *(it + 2));
            }
        }
        else if(mode == MYGL_TRIANGLE_STRIP)
        {
            for(auto it = vertices.begin() + 2; it < vertices.end(); it ++)
            {
                drawTriangle(*(it - 2), *(it - 1), *it);
            }
        }
        else if(mode == MYGL_TRIANGLE_FAN)
        {
            for(auto it = vertices.begin() + 1; it < vertices.end() && it + 1 < vertices.end(); it++)
            {
                drawTriangle(*vertices.begin(), *it, *(it + 1));
            }
        }
    }
}
