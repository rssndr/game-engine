// src/input/input.c
#include "input.h"

void init_input(Input* input) {
        input->quit = 0;
}

void process_input(Input* input) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
                switch (event.type) {
                        case SDL_QUIT:
                                input->quit = 1;
                                break;
                        case SDL_KEYDOWN:
                                if (event.key.keysym.sym == SDLK_ESCAPE) {
                                        input->quit = 1;
                                }
                                break;
                }
        }
}

void cleanup_input(Input* input) {

}

