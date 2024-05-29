#include <SDL2/SDL.h>
#include <stdio.h>
#include "player.h"
#include "renderer.h"
#include "main.h"
#include "maze.h"

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

    generate_maze(maze);

    int running = 1;
    Player player = { .x = 1.5, .y = 1.5, .angle = 0.0 };

    while (running) {
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        render_scene(renderer, &player);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
