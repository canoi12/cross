#include "cross.h"

const char* vert_src =
#if defined(__EMSCRIPTEN__)
"#version 100\n"
"attribute vec2 a_Pos;\n"
"attribute vec4 a_Color;\n"
"varying vec4 v_Color;\n"
#else
"#version 140\n"
"in vec2 a_Pos;\n"
"in vec4 a_Color;\n"
"out vec4 v_Color;\n"
#endif
"void main() {\n"
"   gl_Position = vec4(a_Pos.x, a_Pos.y, 0.0, 1.0);\n"
"   v_Color = a_Color;\n"
"}";

const char* frag_src =
#if defined(__EMSCRIPTEN__)
"#version 100\n"
"precision mediump float;\n"
"varying vec4 v_Color;\n"
"#define FragColor gl_FragColor\n"
#else
"#version 140\n"
"in vec4 v_Color;\n"
"out vec4 FragColor;\n"
#endif
"void main() {\n"
"   FragColor = v_Color;\n"
"}";

SDL_Window* window;
SDL_GLContext ctx;
SDL_Event ev;
GLuint vao, vbo;
GLuint program;
GLuint vert_shader, frag_shader;

int running = 1;

GLuint compile_shader(int type, const char* source);
GLuint create_program(GLuint vert_shader, GLuint frag_shader);

int cross_init(void) {
    printf("Initiating cross\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
        return -1;
    }
#if defined(__EMSCRIPTEN__)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#else
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    window = SDL_CreateWindow("cross opengl", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 380, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window) {
        fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        return -1;
    }
    ctx = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, ctx);

#if !defined(__EMSCRIPTEN__)
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        fprintf(stderr, "failed to initialize OpenGL context\n");
        exit(EXIT_FAILURE);
    }
#endif

    glViewport(0, 0, 640, 380);

    float vertices[] = {
        -0.5f,  0.5f, 1.f, 0.f, 0.f, 1.f,
         0.5f,  0.5f, 0.f, 1.f, 0.f, 1.f,
        -0.5f, -0.5f, 0.f, 0.f, 1.f, 1.f,

        -0.5f, -0.5f, 0.f, 0.f, 1.f, 1.f,
         0.5f, -0.5f, 1.f, 0.f, 0.f, 1.f,
         0.5f,  0.5f, 0.f, 1.f, 0.f, 1.f
    };
    printf("TEstando\n");

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

#if !defined(__EMSCRIPTEN__)
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
#endif
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(2 * sizeof(float)));
#if !defined(__EMSCRIPTEN__)
    glBindVertexArray(0);
#endif

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vert_shader = compile_shader(GL_VERTEX_SHADER, vert_src);
    frag_shader = compile_shader(GL_FRAGMENT_SHADER, frag_src);
    program = create_program(vert_shader, frag_shader);
    return 0;
}

static inline void main_loop(void) {
    while (SDL_PollEvent(&ev)) {
        switch(ev.type) {
            case SDL_QUIT: running = 0; break;
        }
    }

    glClearColor(0.3f, 0.4f, 0.4f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
#if !defined(__EMSCRIPTEN__)
    glBindVertexArray(vao);
#else
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
#endif
    glDrawArrays(GL_TRIANGLES, 0, 6);
#if !defined(__EMSCRIPTEN__)
    glBindVertexArray(0);
#else
    glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
    glUseProgram(0);

    SDL_GL_SwapWindow(window);
}

void cross_loop(void) {
    #if defined(__EMSCRIPTEN__)
        emscripten_set_main_loop(main_loop, 0, 1);
    #else
        while(running) main_loop();
    #endif
}

void cross_quit(void) {
    glDeleteBuffers(1, &vbo);
#if !defined(__EMSCRIPTEN__)
    glDeleteVertexArrays(1, &vao);
#endif
    glDeleteProgram(program);
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);
    SDL_GL_DeleteContext(ctx);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

inline GLuint compile_shader(int type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    int success;
    char info_log[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, info_log);
        fprintf(stderr, "Failed to compile shader: %s\n", info_log);
        return 0;
    }
    return shader;
}

inline GLuint create_program(GLuint vert_shader, GLuint frag_shader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vert_shader);
    glAttachShader(program, frag_shader);
    glLinkProgram(program);
    int success;
    char info_log[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, info_log);
        fprintf(stderr, "Failed to link program: %s\n", info_log);
        return 0;
    }
    return program;
}