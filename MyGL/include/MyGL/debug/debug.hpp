#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "../math/mat.hpp"
#include "../buffer/VertexArray.h"
#include <iostream>

namespace mygl
{
    class Debug
    {
    public:
    //math
        template<typename type, int rows, int columns>
        static void printMat(const mygl::t_mat<type, rows, columns> & m, const char *name = "");
       
        template<typename type, int length>
        static void printVec(const mygl::t_vec<type, length> & v, const char *name = "");

    //buffer
        static void showVAO(VertexArray &vao,  const char *name = "")
        {
            std::cout << std::endl;
            std::cout << "-----------------------------------" << "VAO " << name << "-----------------------------------" << std::endl;
            std::cout << "ebo address:" << vao.ebo << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            for(auto iter : vao.vas)
            {
                std::cout << "vbo address:" << iter.first->getbuf() << std::endl;
                for(auto it : iter.second)
                {
                    const char *type = it.type == MYGL_BYTE ? "byte": it.type == MYGL_UNSIGNED_BYTE ? "unsigned byte" :
                    it.type == MYGL_SHORT ? "short" : it.type == MYGL_UNSIGNED_SHORT ? "unsigned short" : 
                    it.type == MYGL_INT ? "int" : it.type == MYGL_UNSIGNED_INT ? "unsigned int" :
                    it.type == MYGL_FLOAT ? "float" : "error";
                    std::cout << "index:" << it.index << " ; size:" << it.size << " ; type:" << type << 
                    " ; normalized:" << it.normalized << " ; stride:" << it.stride << " ; pointer:" << it.pointer << std::endl;
                }
                std::cout << "-----------------------------------------------------------------------------" << std::endl;
            }
        }
    
    };

}

#include "debug.inl"

#endif