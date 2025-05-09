// src/main.c
#include <stdio.h>
#include "game_loop/game_loop.h"
#include "rendering/rendering.h"
#include "input/input.h"
#include "physics/physics.h"
#include "audio/audio.h"
#include "scene/scene.h"
#include "ui/ui.h"

int main(void) {
        // Initialize game state
        GameLoop game_loop;
        init_game_loop(&game_loop);

        // Initialize renderer
        Renderer renderer;
        if (!init_renderer(&renderer, 800, 600)) {
                return 1;
        }

        printf("Game engine starting...\n");

        // Main game loop
        while (game_loop.running) {
                // Temporary, will move to input.h
                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                        if (event.type == SDL_QUIT) {
                                game_loop.running = 0;
                        }
                }

                int should_update = update_game_loop(&game_loop);

                if (should_update) {
                        printf("Frame %u\n", game_loop.frame_count);
                }

                render_frame(&renderer);

                // Temporary: Exit after 10 seconds
                if (game_loop.frame_count >= 600) {
                        game_loop.running = 0;
                }
        }

        // Cleanup
        cleanup_renderer(&renderer);
        printf("Game engine shutting down...\n");
        return 0;
}

