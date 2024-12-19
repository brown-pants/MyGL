project(Sandbox)

file(GLOB_RECURSE SRC src/*.cpp src/*.h)
add_executable(Sandbox ${SRC})

target_link_libraries(Sandbox PUBLIC Engine)
target_link_directories(Sandbox PUBLIC ../Engine/include)

file(COPY ${PROJECT_SOURCE_DIR}/textures DESTINATION ${PROJECT_BINARY_DIR})