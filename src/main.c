#include <SDL2/SDL.h>
#include <stdio.h>
#include "gamestate.h"
#include "player.h"
#include "renderer.h"
#include "main.h"
#include "maze.h"
#include "enemy.h"

int maze[HEIGHT][WIDTH];

/**
 * Main Entry point
 * 
 * @return 0.
*/
int main(void) {
    
    GameState gamestate;
    init_game_state(&gamestate);

    Uint32 last_time = SDL_GetTicks();

    while (gamestate.running) {
        Uint32 current_time = SDL_GetTicks();
        double delta_time = (current_time - last_time) / 1000.0;
        last_time = current_time;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    gamestate.running = 0;
                    break;
            }
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) move_player(&gamestate, 0.05);
        if (state[SDL_SCANCODE_S]) move_player(&gamestate, -0.05);
        if (state[SDL_SCANCODE_A]) gamestate.player.angle += 0.01;
        if (state[SDL_SCANCODE_D]) gamestate.player.angle -= 0.01;

        update_enemies(&gamestate, delta_time);

        SDL_SetRenderDrawColor(gamestate.renderer, 0, 0, 0, 255);
        SDL_RenderClear(gamestate.renderer);

        render_scene(&gamestate);
        render_minimap(&gamestate);
        /** render_enemies(renderer, enemies, 3, enemy_texture, (int)player.x, (int)player.y, player.angle); */

        SDL_RenderPresent(gamestate.renderer);
        SDL_Delay(16);
    }

    cleanup_game_state(&gamestate);

    return 0;
}
