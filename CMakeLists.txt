cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(cross VERSION 0.1.0 LANGUAGES C)

message("Compiling for ${CMAKE_SYSTEM_NAME}")

if (CMAKE_SYSTEM_NAME MATCHES "Emscripten")
    set(USE_FLAGS "-s USE_SDL=2")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}") 
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    set(EMSCRIPTEN 1)
endif ()

include_directories(. external/glad/include)

if (NOT SDL_PATH)
    if (MSVC)
        set(SDL_PATH MSVC/SDL2)
    endif()
endif()

if (WIN32 AND MSVC)
    set(SDL2_DIR ${SDL_PATH}/cmake)
endif()

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

set(LIBRARIES ${OPENGL_LIBRARIES} ${SDL2_LIBRARIES})
include_directories(${OPENGL_INCLUDE_DIR} ${SDL2_INCLUDE_DIRS})

if (WIN32)
    if (MSVC)
    else()
        set(LIBRARIES mingw32 ${LIBRARIES} -mwindows)
    endif()
    set(LIBRARIES ${LIBRARIES} gdi32 winmm)
else()
    set(LIBRARIES ${LIBRARIES} dl m pthread)
endif()

add_executable(${PROJECT_NAME} main.c cross.c external/glad/src/glad.c)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})