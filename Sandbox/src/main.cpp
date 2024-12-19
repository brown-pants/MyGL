#include <iostream>
#include <MyGL/mygl.h>
#include <Engine/window.h>
#include <Engine/camera.h>
#include <stb_image.h>

void LoadTexture2D(const char *path, mygl::Texture2D &tex)
{

    int tex_width, tex_height, tex_channels;
    unsigned char *data = stbi_load(path, &tex_width, &tex_height, &tex_channels, 0);
    std::cout << "width:" << tex_channels << std::endl;
    std::cout << "height:" << tex_height << std::endl;
    std::cout << "channels:" << tex_channels << std::endl;
    if(data == NULL) std::cout << "Failed to load texture" << std::endl;
    tex.setData(data, tex_width, tex_height, tex_channels);
    stbi_image_free(data);
}

class MyWindow : public engine::Window
{
public:
    MyWindow(const char *title, int width, int height) : Window(title, width, height)
    {
        float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
        };
        vbo.setData(sizeof(vertices), vertices);
        
        vao.addVertexAttrib(vbo, 0, 3, MYGL_FLOAT, false, 8 * sizeof(float), (void*)0);
        vao.addVertexAttrib(vbo, 1, 3, MYGL_FLOAT, false, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.addVertexAttrib(vbo, 2, 2, MYGL_FLOAT, false, 8 * sizeof(float), (void*)(6 * sizeof(float)));

        shader.setVertexShader(
        MYGL_VERTEX_SHADER
        {
            using namespace mygl;
            LAYOUT_IN(0, vec3, aPos);
            LAYOUT_IN(1, vec3, aNormal);
            LAYOUT_IN(2, vec2, aTexCoords);

            UNIFORM(double, time);
            UNIFORM(mat4, projection);
            UNIFORM(mat4, model);
            UNIFORM(mat4, view);

            OUT(vec2, TexCoords);
            OUT(vec3, FragPos);
            OUT(vec3, Normal);
            TexCoords = aTexCoords;
            FragPos = model * vec4(aPos, 1);
            Normal = normalize(model * vec4(aNormal, 1));
            
            mygl_Position = projection * view * model * vec4(aPos, 1);

        });

        shader.setFragmentShader(
        MYGL_FRAGMENT_SHADER
        {
            using namespace mygl;
            UNIFORM(Texture2D *, Diffuse);
            UNIFORM(Texture2D *, Specular);
            UNIFORM(vec3, LightPos);
            UNIFORM(vec3, LightColor);
            UNIFORM(vec3, ViewPos);
            IN(vec2, TexCoords);
            IN(vec3, FragPos);
            IN(vec3, Normal);
             
            vec3 LightDir = normalize(LightPos - FragPos);
            float diff = std::max(dot(LightDir, Normal), 0.2f);
            vec3 diffuse = LightColor * diff;
            float specularStrength = 0.8f;
            vec3 viewDir = normalize(ViewPos - FragPos);
            vec3 reflectDir = reflect(-LightDir, Normal);
            float spec = pow(std::max(dot(viewDir, reflectDir), 0.0f), 32);
            vec3 specular = vec3(1.0f, 1.0f, 1.0f) * specularStrength * spec;

            vec3 diffuseColor = diffuse * vec3(texture(Diffuse, TexCoords));
            vec3 specularColor = specular * vec3(texture(Specular, TexCoords));
            
            mygl_FragColor = vec4(diffuseColor + specularColor, 1.0f);
        });
        LoadTexture2D("./textures/container2.png", diffuse);
        LoadTexture2D("./textures/container2_specular.png", specular);

        mygl::vec3 LightPos(400, 400, -300);
        mygl::vec3 LightColor(1, 1, 1);
        shader.setUniformValue("Diffuse", &diffuse);
        shader.setUniformValue("Specular", &specular);
        shader.setUniformValue("LightPos", LightPos);
        shader.setUniformValue("LightColor", LightColor);

        MYGL->disable(MYGL_DEPTH_TEST);
        MYGL->enable(MYGL_DEPTH_TEST);
    }

    void render(double time) override
    {
        shader.setUniformValue("time", time);
        mygl::mat4 projection = mygl::ortho(0, 800, 0, 600, 1.0f, -1000.0f);
        mygl::mat4 model(1.0f);

        model *= mygl::mat4(1, 0, 0, 0,
                            0, cos(time), -sin(time), 0,
                            0, sin(time), cos(time), 0,
                            0, 0, 0, 1);
        
        model *= mygl::mat4(cos(time), 0, sin(time), 0,
                            0, 1, 0, 0,
                            -sin(time), 0, cos(time),0,
                            0, 0, 0, 1);

        model *= mygl::mat4(cos(time), -sin(time), 0, 0,
                            sin(time), cos(time), 0, 0,
                            0, 0, 1, 0,
                            0, 0, 0, 1);
                        
        model = mygl::scale(model, mygl::vec3(400, 400, 400));
        model = mygl::translate(model, mygl::vec3(400, 300, -500));
        
        shader.setUniformValue("projection", projection);
        shader.setUniformValue("view", camera.getViewMatrix());
        shader.setUniformValue("model", model);
        shader.setUniformValue("ViewPos", camera.position);

        /*shader.setUniformValue("projection", mygl::mat4(1.0f));
        shader.setUniformValue("view", mygl::mat4(1.0f));
        shader.setUniformValue("model", mygl::mat4(1.0f));*/

        MYGL->ClearColor(0,1,1,1);
        MYGL->Clear(MYGL_COLOR_BUFFER_BIT | MYGL_DEPTH_BUFFER_BIT | MYGL_STENCIL_BUFFER_BIT);
        MYGL->bindShader(shader);
        MYGL->bindVertexArray(vao);
        MYGL->drawArrays(MYGL_TRIANGLES, 0, 36);
        //MYGL->drawElement(MYGL_TRIANGLE_FAN, 4, MYGL_UNSIGNED_INT, (const void *)(0 * sizeof(unsigned int)));
    }

    void processInput() override
    {
        float speed = 20;
        if(getKeyState(GLFW_KEY_A) == GLFW_PRESS)
        {
            mygl::vec3 left = -mygl::normalize(mygl::cross(camera.front, mygl::vec3(0, 1, 0)));
            camera.position += left * speed;
        }
        else if(getKeyState(GLFW_KEY_D) == GLFW_PRESS)
        {
            mygl::vec3 right = mygl::normalize(mygl::cross(camera.front, mygl::vec3(0, 1, 0)));
            camera.position += right * speed;
        }
        else if(getKeyState(GLFW_KEY_W) == GLFW_PRESS)
        {
            camera.position += camera.front * speed ;
        }
        else if(getKeyState(GLFW_KEY_S) == GLFW_PRESS)
        {
            camera.position -= camera.front * speed;
        }
    }

    void mousePressEvent(MouseEvent &event) override
    {
        std::cout << "MousePress: " << event.x << " " << event.y << std::endl;
        if(event.button == GLFW_MOUSE_BUTTON_LEFT)
        {
            isMousePress = true;
            lastMouse.x = event.x;
            lastMouse.y = event.y;
        }
    }

    void mouseReleaseEvent(MouseEvent &event) override
    {
        std::cout << "MouseRelease: " << event.x << " " << event.y << std::endl;
        isMousePress = false;
    }

    void mouseMoveEvent(MouseEvent &event)
    {
        if(isMousePress)
        {
            static float yaw = 0.0f, pitch = 0.0f;
            float xOffset = event.x - lastMouse.x;
            float yOffset = lastMouse.y - event.y;
            float sensitivity = 0.5;
            xOffset *= sensitivity;
            yOffset *= sensitivity;
            yaw   += xOffset;
            pitch -= yOffset;
            
            if(pitch > 89.0f)
            pitch = 89.0f;
            if(pitch < -89.0f)
            pitch = -89.0f;

            //frist rotate around x, and rotate around y (clockwise)
            camera.front.x = sin(mygl::radians(yaw)) * cos(mygl::radians(pitch));
            camera.front.y = -sin(mygl::radians(pitch));
            camera.front.z = -cos(mygl::radians(yaw)) * cos(mygl::radians(pitch));

            camera.front = mygl::normalize(camera.front);
            camera.up = mygl::normalize(cross(mygl::normalize(mygl::cross(camera.front, mygl::vec3(0, 1, 0))), camera.front));
            lastMouse.x = event.x;
            lastMouse.y = event.y;
        }
    }
    
    void resizeEvent(ResizeEvent &event)
    {
        std::cout << "Resize: " << event.width << " " << event.height << std::endl;
        MYGL->viewport(0, 0, event.width, event.height);
    }

private:
    mygl::Buffer vbo, ebo;
    mygl::VertexArray vao;
    mygl::Texture2D diffuse, specular;
    mygl::Shader shader;
    engine::Camera camera;
    bool isMousePress = false;
    mygl::vec2 lastMouse;
    mygl::Renderer *MYGL = getRenderer();
};

int main(int argc, char *argv[])
{
    MyWindow window("MyGL", 800, 600);
    window.run();
    
    return 0;
}