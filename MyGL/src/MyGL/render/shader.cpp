#include <MyGL/render/shader.h>

namespace mygl
{
    Var::Var() : p(NULL), data_type(0) {}
    Var::Var(const Var &var) : p(NULL), data_type(0) { *this = var; }
    Var::Var(const int &val) : p(new int(val)), data_type(MYGL_INT) {}
    Var::Var(const char &val) : p(new char(val)), data_type(MYGL_BYTE) {}
    Var::Var(const float &val) : p(new float(val)), data_type(MYGL_FLOAT) {}
    Var::Var(const double &val) : p(new double(val)), data_type(MYGL_DOUBLE) {}
    Var::Var(const vec2 &v2) : p(new vec2(v2)), data_type(MYGL_FLOAT_VEC2) {}
    Var::Var(const vec3 &v3) : p(new vec3(v3)), data_type(MYGL_FLOAT_VEC3) {}
    Var::Var(const vec4 &v4) : p(new vec4(v4)), data_type(MYGL_FLOAT_VEC4) {}
    Var::Var(const mat2 &m2) : p(new mat2(m2)), data_type(MYGL_FLOAT_MAT2) {}
    Var::Var(const mat3 &m3) : p(new mat3(m3)), data_type(MYGL_FLOAT_MAT3) {}
    Var::Var(const mat4 &m4) : p(new mat4(m4)), data_type(MYGL_FLOAT_MAT4) {}
    Var::Var(Texture2D *p_tex2d) : p(new Texture2D *(p_tex2d)), data_type(MYGL_TEXTURE_2D) {}
    Var::~Var()
    {
        Delete();
    }
    
    Var &Var::operator= (const Var &var)
    {
        if(var.data_type == MYGL_INT) *this = *(int *)var.p;
        else if(var.data_type == MYGL_BYTE) *this = *(char *)var.p;
        else if(var.data_type == MYGL_FLOAT) *this = *(float *)var.p;
        else if(var.data_type == MYGL_DOUBLE) *this = *(double *)var.p;
        else if(var.data_type == MYGL_FLOAT_VEC2) *this = *(vec2 *)var.p;
        else if(var.data_type == MYGL_FLOAT_VEC3) *this = *(vec3 *)var.p;
        else if(var.data_type == MYGL_FLOAT_VEC4) *this = *(vec4 *)var.p;
        else if(var.data_type == MYGL_FLOAT_MAT2) *this = *(mat2 *)var.p;
        else if(var.data_type == MYGL_FLOAT_MAT3) *this = *(mat3 *)var.p;
        else if(var.data_type == MYGL_FLOAT_MAT4) *this = *(mat4 *)var.p;
        else if(var.data_type == MYGL_TEXTURE_2D) *this = *(Texture2D **)var.p;
        return *this;
    }
    
    Var &Var::operator= (const int &val)
    {
        if(p == NULL) p = new int(val);
        else if(data_type == MYGL_INT) *(int *)p = val;
        else{ Delete(); p = new int(val); }
        data_type = MYGL_INT;
        return *this;
    }

    Var &Var::operator= (const char &val)
    {
        if(p == NULL) p = new char(val);
        else if(data_type == MYGL_BYTE) *(char *)p = val;
        else{ Delete(); p = new char(val); }
        data_type = MYGL_BYTE;
        return *this;
    }

    Var &Var::operator= (const float &val)
    {
        if(p == NULL) p = new float(val);
        else if(data_type == MYGL_FLOAT) *(float *)p = val;
        else{ Delete(); p = new float(val); }
        data_type = MYGL_FLOAT;
        return *this;
    }

    Var &Var::operator= (const double &val)
    {
        if(p == NULL) p = new double(val);
        else if(data_type == MYGL_DOUBLE) *(double *)p = val;
        else{ Delete(); p = new double(val); }
        data_type = MYGL_DOUBLE;
        return *this;
    }

    Var &Var::operator= (const vec2 &v2)
    {
        if(p == NULL) p = new vec2(v2);
        else if(data_type == MYGL_FLOAT_VEC2) *(vec2 *)p = v2;
        else{ Delete(); p = new vec2(v2); }
        data_type = MYGL_FLOAT_VEC2;
        return *this;
    }

    Var &Var::operator= (const vec3 &v3)
    {
        if(p == NULL) p = new vec3(v3);
        else if(data_type == MYGL_FLOAT_VEC3) *(vec3 *)p = v3;
        else{ Delete(); p = new vec3(v3); }
        data_type = MYGL_FLOAT_VEC3;
        return *this;
    }

    Var &Var::operator= (const vec4 &v4)
    {
        if(p == NULL) p = new vec4(v4);
        else if(data_type == MYGL_FLOAT_VEC4) *(vec4 *)p = v4;
        else{ Delete(); p = new vec4(v4); }
        data_type = MYGL_FLOAT_VEC4;
        return *this;
    }

    Var &Var::operator= (const mat2 &m2)
    {
        if(p == NULL) p = new mat2(m2);
        else if(data_type == MYGL_FLOAT_MAT2) *(mat2 *)p = m2;
        else{ Delete(); p = new mat2(m2); }
        data_type = MYGL_FLOAT_MAT2;
        return *this;
    }

    Var &Var::operator= (const mat3 &m3)
    {
        if(p == NULL) p = new mat3(m3);
        else if(data_type == MYGL_FLOAT_MAT3) *(mat3 *)p = m3;
        else{ Delete(); p = new mat3(m3); }
        data_type = MYGL_FLOAT_MAT3;
        return *this;
    }

    Var &Var::operator= (const mat4 &m4)
    {
        if(p == NULL) p = new mat4(m4);
        else if(data_type == MYGL_FLOAT_MAT4) *(mat4 *)p = m4;
        else{ Delete(); p = new mat4(m4); }
        data_type = MYGL_FLOAT_MAT4;
        return *this;
    }

    Var &Var::operator= (Texture2D *p_tex2d)
    {
        if(p == NULL) p = new Texture2D *(p_tex2d);
        else if(data_type == MYGL_TEXTURE_2D) *(Texture2D **)p = p_tex2d;
        else{ Delete(); p = new Texture2D *(p_tex2d); }
        data_type = MYGL_TEXTURE_2D;
        return *this;
    }

    void Var::Delete()
    {
        if(p != NULL) 
        {
            if(data_type == MYGL_INT) delete (int *)p;
            else if(data_type == MYGL_BYTE) delete (char *)p;
            else if(data_type == MYGL_FLOAT) delete (float *)p;
            else if(data_type == MYGL_DOUBLE) delete (double *)p;
            else if(data_type == MYGL_FLOAT_VEC2) delete (vec2 *)p;
            else if(data_type == MYGL_FLOAT_VEC3) delete (vec3 *)p;
            else if(data_type == MYGL_FLOAT_VEC4) delete (vec4 *)p;
            else if(data_type == MYGL_TEXTURE_2D) delete (Texture2D **)p;
            p = NULL;
        }
    }

    Shader::Shader() : vs(NULL), fs(NULL){}
    Shader::Shader(VertexShader vs, FragmentShader fs) : vs(vs), fs(fs) {}
    Shader::~Shader() {}

}