#include <Engine/camera.h>

namespace engine
{
    Camera::Camera(const mygl::vec3 &position, const mygl::vec3 &front, const mygl::vec3 &up)
    :position(position), front(front), up(up) {}

    Camera::~Camera() {}

    mygl::mat4 Camera::getViewMatrix()
    {
        return mygl::lookAt(position, position + front, up);
    }
}