// src/input/input.h
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

typedef struct {
        int quit;
} Input;

void init_input(Input* input);

void process_input(Input* input);

void cleanup_input(Input* input);

#endif

