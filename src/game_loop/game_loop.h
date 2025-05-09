// src/game_loop/game_loop.h
#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <time.h>

#define TARGET_FPS 60

typedef struct {
        int running;
        unsigned int frame_count;
        clock_t _last_time;
        float _delta_time;
        float _target_frame_time;
} GameLoop;

void init_game_loop(GameLoop* loop);

int update_game_loop(GameLoop* loop);

#endif

