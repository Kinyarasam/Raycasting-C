#include <SDL2/SDL.h>
#include <stdio.h>
#include "../include/player.h"
#include "../include/renderer.h"
#include "../include/main.h"
#include "../include/maze.h"
#include "../include/enemy.h"

int maze[HEIGHT][WIDTH];

/**
 * Main Entry point
 * 
 * @return 0.
*/
int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Raycasting",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Surface *enemy_surface = SDL_LoadBMP("./assets/enemy.bmp");
    if (!enemy_surface) {
        fprintf(stderr, "Could not load enemy texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    /**
     * SDL_Texture *enemy_texture = SDL_CreateTextureFromSurface(renderer, enemy_surface);
     * SDL_FreeSurface(enemy_surface);
     */

    generate_maze(maze);

    int running = 1;
    Player player = { .x = 1.5, .y = 1.5, .angle = 0.0 };

    Enemy enemies[3] = {
        { .x = 3.0, .y = 3.0, .angle = 0.0 },

        // include M_PI ? math.h
        { .x = 5.0, .y = 5.0, .angle = MATH_M_PI / 2 },
        { .x = 7.0, .y = 7.0, .angle = MATH_M_PI },
    };

    Uint32 last_time = SDL_GetTicks();

    while (running) {
        Uint32 current_time = SDL_GetTicks();
        double delta_time = (current_time - last_time) / 1000.0;
        last_time = current_time;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_W]) move_player(&player, 0.05);
        if (state[SDL_SCANCODE_S]) move_player(&player, -0.05);
        if (state[SDL_SCANCODE_A]) player.angle += 0.01;
        if (state[SDL_SCANCODE_D]) player.angle -= 0.01;

        update_enemies(enemies, 3, player.x, player.y, maze, delta_time);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_scene(renderer, &player);
        render_minimap(renderer, &player, maze);
        /** render_enemies(renderer, enemies, 3, enemy_texture, (int)player.x, (int)player.y, player.angle); */

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
