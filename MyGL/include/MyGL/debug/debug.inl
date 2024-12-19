#include <iostream>
#include "debug.hpp"

namespace mygl
{
    template<typename type, int rows, int columns>
    void Debug::printMat(const mygl::t_mat<type, rows, columns> & m, const char *name)
    {
        std::cout << std::endl;
        std::cout << "matrix" << rows << 'x' << columns << " " << name << ':' << std::endl;
        for(int i = 0;i < rows;i++)
        {
            for(int j = 0;j < columns;j++)
            {
                if(j == 0) std::cout << "| ";
                std::cout << m.data[i].getValue(j) << " ";
            }
            std::cout << '|' << std::endl;
        }
    }

    template<typename type, int length>
    void Debug::printVec(const mygl::t_vec<type, length> & v, const char *name)
    {
        std::cout << std::endl;
        std::cout << "vector" << length << " " << name << ':' << std::endl << "( ";
        for(int i = 0;i<length;i++)
        {
            std::cout << v.getValue(i) ;
            if(i != length - 1) std::cout << ", ";
        }
        std::cout << " )" << std::endl;
    }

}