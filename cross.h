#ifndef CROSS_H
#define CROSS_H

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>

#if WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
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