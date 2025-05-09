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

        printf("Game engine starting...\n");

        while (game_loop.running) {
                // Update game loop state
                int should_update = update_game_loop(&game_loop);

                if (should_update) {
                        printf("Frame %u\n", game_loop.frame_count);
                }

                // TODO: Process input (e.g., check for quit event)
                // TODO: Update game state (physics, scene, etc.)
                // TODO: Render frame

                // Temporary: Exit after 10 seconds
                if (game_loop.frame_count >= 600) {
                        game_loop.running = 0;
                }
        }

        // TODO: Cleanup systems
        printf("Game engine shutting down...\n");
        return 0;
}

