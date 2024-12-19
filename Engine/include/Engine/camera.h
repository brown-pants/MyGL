#ifndef __CAMERA_H__
#define __CAMERA_H__
#include <MyGL/mygl.h>

namespace engine
{
    //camera look at -z 
    class Camera
    {
    public:
        Camera(const mygl::vec3 &position = mygl::vec3(0.0f, 0.0f, 0.0f), const mygl::vec3 &front = mygl::vec3(0.0f, 0.0f,-1.0f), const mygl::vec3 &up = mygl::vec3(0.0f, 1.0f, 0.0f));
        ~Camera();
        mygl::vec3 up;
        mygl::vec3 front;
        mygl::vec3 position;
        mygl::mat4 getViewMatrix();

    private:
    };
}

#endif