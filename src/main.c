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

        // Initialize input
        Input input;
        init_input(&input);

        printf("Game engine starting...\n");

        // Main game loop
        while (game_loop.running) {
                process_input(&input);
                if (input.quit) {
                        game_loop.running = 0;
                        break;
                }

                int should_update = update_game_loop(&game_loop);

                if (should_update) {
                        printf("Frame %u\n", game_loop.frame_count);
                }

                render_frame(&renderer);
        }

        // Cleanup
        cleanup_input(&input);
        cleanup_renderer(&renderer);
        printf("Game engine shutting down...\n");
        return 0;
}

