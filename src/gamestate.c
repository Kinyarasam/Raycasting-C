#include "gamestate.h"

void init_game_state(GameState *gamestate) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Create Window.
    gamestate->window = SDL_CreateWindow("Raycasting",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gamestate->window) {
        fprintf(stderr, "Couldn't create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Create renderer
    gamestate->renderer = SDL_CreateRenderer(gamestate->window, -1, SDL_RENDERER_ACCELERATED);
    if (!gamestate->renderer) {
        fprintf(stderr, "Couldn't create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(gamestate->window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // Load enemy texture
    gamestate->enemy_surface = SDL_LoadBMP("../assets/enemy.bmp");  /** @bug: Fix how the assets are being retrieved. Make it more dynamic. */
    if (!gamestate->enemy_surface) {
        fprintf(stderr, "Could not load enemy texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(gamestate->renderer);
        SDL_DestroyWindow(gamestate->window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    gamestate->enemy_texture = SDL_CreateTextureFromSurface(gamestate->renderer, gamestate->enemy_surface);
    SDL_FreeSurface(gamestate->enemy_surface);

    // Initialize player
    gamestate->player = (Player){ .angle = 0.0, .x = 1.5, .y = 1.5 };

    // Initialize enemies
    gamestate->num_enemies = 3;
    gamestate->enemies[0] = (Enemy){ .x = 3.0, .y = 3.0, .angle = 0.0 };
    gamestate->enemies[1] = (Enemy){ .x = 5.0, .y = 5.0, .angle = M_PI / 2 };
    gamestate->enemies[2] = (Enemy){ .x = 7.0, .y = 7.0, .angle = M_PI };

    generate_maze(gamestate);

    gamestate->running = 1;
}

void cleanup_game_state(GameState *gamestate) {
    SDL_DestroyTexture(gamestate->enemy_texture);
    SDL_DestroyRenderer(gamestate->renderer);
    SDL_DestroyWindow(gamestate->window);
    SDL_Quit();
}
