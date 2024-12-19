project(MyGL)

file(GLOB_RECURSE SRC src/*.cpp src/*.h src/*.inl)

add_library(MyGL STATIC ${SRC})
target_include_directories(MyGL PRIVATE ./include)