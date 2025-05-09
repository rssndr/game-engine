// src/game_loop/game_loop.c
#include <time.h>
#include <unistd.h>
#include "game_loop.h"

void init_game_loop(GameLoop* loop) {
        loop->running = 1;
        loop->frame_count = 0;
        loop->_last_time = clock();
        loop->_delta_time = 0.0f;
        loop->_target_frame_time = 1.0f / TARGET_FPS;
}

int update_game_loop(GameLoop* loop) {
        clock_t current_time = clock();
        float elapsed = (float)(current_time - loop->_last_time) / CLOCKS_PER_SEC;
        loop->_last_time = current_time;

        loop->_delta_time += elapsed;

        if (loop->_delta_time >= loop->_target_frame_time) {
                loop->frame_count++;
                loop->_delta_time -= loop->_target_frame_time;
                return 1;
        }
        return 0;
}

