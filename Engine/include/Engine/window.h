#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <GLFW/glfw3.h>
#include <MyGL/mygl.h>
#include <ImGui/imgui.h>

namespace engine
{     
    class Window
    {
    public:
        struct MouseEvent
        {
            double x, y;
            int button;
            int mods;
        };
        struct ResizeEvent
        {
            int width;
            int height;
        };
        struct KeyEvent
        {
            int key;
            int scancode;
            int mods;
        };
        Window(const char *title = "", int width = 800, int height = 600);
        ~Window();

        inline mygl::Renderer *getRenderer() { return &m_renderer; }
        
        inline int width() { return m_windowData.width; }
        inline int height() { return m_windowData.height; }
        inline const char *title() { return m_windowData.title; }

        inline void DarkStyle() { ImGui::StyleColorsDark(); }
        inline void LightStyle() { ImGui::StyleColorsLight(); }
        inline void ClassicStyle() { ImGui::StyleColorsClassic(); }

        void run();
        virtual void processInput() {}
        virtual void render(double time) {}
        
        virtual void mousePressEvent(MouseEvent &event) {}
        virtual void mouseReleaseEvent(MouseEvent &event) {}
        virtual void keyPressEvent(KeyEvent &event) {}
        virtual void keyReleaseEvent(KeyEvent &event) {}
        virtual void mouseMoveEvent(MouseEvent &event) {}
        virtual void resizeEvent(ResizeEvent &event) {}

        int getKeyState(int key);

    private:
        GLFWwindow *m_window;
        mygl::Renderer m_renderer;
        mygl::FrameBuffer m_fbo;

        struct WindowData{
            const char *title;
            int width, height;
            mygl::FrameBuffer *p_fbo;
            mygl::Renderer *p_renderer;
            Window *p_this;
        }m_windowData;

        void initGlfw(int width, int height, const char *title);
        void initImGui(GLFWwindow *window);

        void renderUI();
    };
}

#endif