#ifndef CROSS_H
#define CROSS_H

#include <stdio.h>
#include <stdlib.h>

#if !defined(__EMSCRIPTEN__)
#include <glad/glad.h>
#else
#include <emscripten.h>
#endif

#if WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#if !defined(__EMSCRIPTEN__)
#include <SDL2/SDL_opengl.h>
#else
#include <SDL2/SDL_opengles2.h>
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif

int cross_init(void);
void cross_quit(void);

void cross_loop(void);

#if defined(__cplusplus)
}
#endif

#endif /* CROSS_H */