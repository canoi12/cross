cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(cross_gl VERSION 0.1.0 LANGUAGES C)

include_directories(glad/include)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} main.c glad/src/glad.c)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES} dl)