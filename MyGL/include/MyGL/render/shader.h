#ifndef __SHADER_H__
#define __SHADER_H__
#include "../math/mat.hpp"
#include "../enum/MyGLEnum.h"
#include "../texture/texture2d.h"
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>

#define LAYOUT_IN(location, type, name) type const &name = layout_in.find(location)->second.value<type>()
#define UNIFORM(type, name)             type const &name = uniform.find(#name)->second.value<type>()
#define OUT(type, name)                 type       &name = out.insert(std::pair<std::string, Var>(#name, type())).first->second.value<type>()
#define IN(type, name)                  type const &name = in.find(#name)->second.value<type>()
#define UNIFORM(type, name)             type const &name = uniform.find(#name)->second.value<type>()

#define MYGL_VERTEX_SHADER [](      mygl::vec4                         &mygl_Position, \
                              const std::unordered_map<int, mygl::Var>           &layout_in,     \
                              const std::unordered_map<std::string, mygl::Var>   &uniform,       \
                                    std::unordered_map<std::string, mygl::Var>   &out)           
                                    
#define MYGL_FRAGMENT_SHADER [](      mygl::vec4                       &mygl_FragColor, \
                                const mygl::vec4                       &mygl_FragCoord, \
                                const std::unordered_map<std::string, mygl::Var> &uniform,        \
                                const std::unordered_map<std::string, mygl::Var> &in,             \
                                      bool                             &discard)

namespace mygl
{
    class Var
    {
    public:
        Var();
        Var(const Var &var);
        Var(const int &val);
        Var(const char &val);
        Var(const float &val);
        Var(const double &val);
        Var(const vec2 &v2);
        Var(const vec3 &v3);
        Var(const vec4 &v4);
        Var(const mat2 &m2);
        Var(const mat3 &m3);
        Var(const mat4 &m4);
        Var(Texture2D *p_tex2d);
        ~Var();
        
        Var &operator= (const Var &var);
        Var &operator= (const int &val);
        Var &operator= (const char &val);
        Var &operator= (const float &val);
        Var &operator= (const double &val);
        Var &operator= (const vec2 &v2);
        Var &operator= (const vec3 &v3);
        Var &operator= (const vec4 &v4);
        Var &operator= (const mat2 &m2);
        Var &operator= (const mat3 &m3);
        Var &operator= (const mat4 &m4);
        Var &operator= (Texture2D *p_tex2d);

        template<typename type>
        inline type &value() const { return *(type *)p; }
        inline unsigned int type() const { return data_type; }
        void Delete();

    private:
        void *p;
        unsigned int data_type;
    };

    class Shader
    {
    public:
        friend class Pipeline;
/*-----------------------------------Shader Type-----------------------------------*/
        typedef
        std::function<void(vec4                             &mygl_Position, 
                           const std::unordered_map<int, Var>         &layout_in,
                           const std::unordered_map<std::string, Var> &uniform,
                                 std::unordered_map<std::string, Var> &out)
                     >VertexShader;

        typedef
        std::function<void(      vec4                       &mygl_FragColor, 
                           const vec4                       &mygl_FragCoord,
                           const std::unordered_map<std::string, Var> &uniform,
                           const std::unordered_map<std::string, Var> &in,
                                 bool                       &discard)
                     >FragmentShader;
/*----------------------------------------------------------------------------------*/
        Shader();
        Shader(VertexShader vs, FragmentShader fs);
        ~Shader();

        inline void setVertexShader(VertexShader vs) {this->vs = vs;}
        inline void setFragmentShader(FragmentShader fs) {this->fs = fs;}

        template<typename type>
        void setUniformValue(const std::string &name, const type &value);

    private:
        VertexShader vs;
        FragmentShader fs;
        std::unordered_map<std::string, Var> uniform;
    };

    template<typename type>
    void Shader::setUniformValue(const std::string &name, const type &value)
    {
        if(this->uniform.find(name) != this->uniform.end()){
            this->uniform.find(name)->second = value;
        }
        else{
            this->uniform.insert(std::pair<std::string, Var>(name, value));
        }
    }
}

#endif