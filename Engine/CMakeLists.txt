project(Engine)

file(GLOB_RECURSE SRC src/*.cpp src/*.h)

add_library(Engine STATIC ${SRC} 
                          3rdparty/stb_image/stb_image.cpp)
target_include_directories(Engine PUBLIC ./include)

#link mygl
target_link_libraries(Engine PUBLIC MyGL)
target_include_directories(Engine PUBLIC ../MyGL/include)

#link 3rdparty
add_subdirectory(3rdparty)
#glfw
target_include_directories(Engine PUBLIC 3rdparty/glfw/include)
target_link_libraries(Engine PUBLIC glfw)
#stb_image
target_include_directories(Engine PUBLIC 3rdparty/stb_image)
#imgui
target_include_directories(Engine PUBLIC 3rdparty/imgui/include)
target_link_libraries(Engine PUBLIC imgui)

#link opengl
if(WIN32)
    target_link_libraries(Engine PUBLIC opengl32.lib)
elseif(UNIX)
    target_link_libraries(Engine PUBLIC libGL.so)
else()
    message(FATAL_ERROR "Don't support this platform!")
endif()