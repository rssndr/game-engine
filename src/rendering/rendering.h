// src/rendering/rendering.h
#ifndef RENDERING_H
#define RENDERING_H

#include <SDL2/SDL.h>

typedef struct {
        SDL_Window* window;
        SDL_Renderer* renderer;
} Renderer;

int init_renderer(Renderer* renderer, int width, int height);

void render_frame(Renderer* renderer);

void cleanup_renderer(Renderer* renderer);

#endif

