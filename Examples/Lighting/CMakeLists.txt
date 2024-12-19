project(Lighting)

file(GLOB_RECURSE SRC src/*.cpp src/*.h)
add_executable(Lighting ${SRC})

target_link_libraries(Lighting PUBLIC Engine)
target_link_directories(Lighting PUBLIC ../../Engine/include)