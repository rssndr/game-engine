// src/rendering/rendering.c
#include "rendering.h"

int init_renderer(Renderer* renderer, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                printf("SDL_Init failed: %s\n", SDL_GetError());
                return 0;
        }

        renderer->window = SDL_CreateWindow(
                "Game Engine",
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height,
                SDL_WINDOW_SHOWN
        );
        if (!renderer->window) {
                printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
                SDL_Quit();
                return 0;
        }

        renderer->renderer = SDL_CreateRenderer(renderer->window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer->renderer) {
                printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
                SDL_Quit();
                return 0;
        }

        return 1;
}

void render_frame(Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer->renderer);
        SDL_RenderPresent(renderer->renderer);
}

void cleanup_renderer(Renderer* renderer) {
        SDL_DestroyRenderer(renderer->renderer);
        SDL_DestroyWindow(renderer->window);
        SDL_Quit();
}

