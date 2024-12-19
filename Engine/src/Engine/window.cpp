#include <Engine/window.h>
#include <MyGL/mygl.h>
#include <ImGui/imgui_impl_opengl2.h>
#include <ImGui/imgui_impl_glfw.h>

namespace engine
{     
    Window::Window(const char *title, int width, int height) : m_renderer(m_fbo, width, height)
    {
        initGlfw(width, height, title);
        initImGui(m_window);
        
        m_renderer.viewport(0, 0, width, height);

        m_fbo.ColorBuffer = new unsigned char[width * height * 4];
        m_fbo.DepthBuffer = new float[width * height];

        m_windowData.title = title;
        m_windowData.width = width;
        m_windowData.height = height;
        m_windowData.p_fbo = &m_fbo;
        m_windowData.p_renderer = &m_renderer;
        m_windowData.p_this = this;
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        delete m_fbo.ColorBuffer;
        delete m_fbo.DepthBuffer;
    }

    void Window::run()
    {
        while(!glfwWindowShouldClose(m_window))
        {
            glfwSwapBuffers(m_window);
            glfwPollEvents();
            processInput();
            ImGui_ImplOpenGL2_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
            glClear(GL_COLOR_BUFFER_BIT);
            render(glfwGetTime());
            glDrawPixels(m_windowData.width, m_windowData.height, GL_RGBA, GL_UNSIGNED_BYTE, m_fbo.ColorBuffer);

            renderUI();
        }
    }

    int Window::getKeyState(int key)
    {
        return glfwGetKey(m_window, key);
    }

    void Window::initGlfw(int width, int height, const char *title)
    {
        glfwInit();
        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (m_window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(m_window);

        glfwSetWindowUserPointer(m_window, (void *)&m_windowData);
        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods){
            double x, y;
            glfwGetCursorPos(window, &x, &y);
            WindowData *data =(WindowData *)glfwGetWindowUserPointer(window);
            MouseEvent event;
            event.x = x;
            event.y = y;
            event.button = button;
            event.mods = mods;
            if(action == GLFW_PRESS) {
                data->p_this->mousePressEvent(event);
            }
            else if(action == GLFW_RELEASE) {
                data->p_this->mouseReleaseEvent(event);
            }
        });
        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            WindowData *data =(WindowData *)glfwGetWindowUserPointer(window);
            KeyEvent event;
            event.key = key;
            event.mods = mods;
            event.scancode = scancode;
            if(action == GLFW_PRESS)
            {
                data->p_this->keyPressEvent(event);
            }
            else if(action == GLFW_RELEASE)
            {
                data->p_this->keyReleaseEvent(event);
            }
        });
        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int width, int height){
            WindowData *data =(WindowData *)glfwGetWindowUserPointer(window);
            ResizeEvent event;
            event.width = width;
            event.height = height;
            data->width = width;
            data->height = height;
            data->p_renderer->screenChanged(width, height);
            data->p_this->resizeEvent(event);

            //resize framebuffer
            delete data->p_fbo->ColorBuffer;
            data->p_fbo->ColorBuffer = new unsigned char[width * height * 4];
            delete data->p_fbo->DepthBuffer;
            data->p_fbo->DepthBuffer = new float[width * height];

        });
        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos){
            WindowData *data =(WindowData *)glfwGetWindowUserPointer(window);
            MouseEvent event;
            event.x = xpos;
            event.y = ypos;
            data->p_this->mouseMoveEvent(event);
        });
    }
    void Window::initImGui(GLFWwindow *window)
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL2_Init();

        //io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    }

    void Window::renderUI()
    {
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
        static bool show_demo_window = true;
        static bool show_another_window = true;
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }
        ImGui::Render();
        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }
}