#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL2/SDL.h>
#include "player.h"
#include "enemy.h"
#include "maze.h"

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define MAX_ENEMIES 10
#define WIDTH 21
#define HEIGHT 21
#define M_PI 3.14159265358979323846

// GameState struct definition
typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *enemy_surface;
    SDL_Texture *enemy_texture;
    Player player;
    Enemy enemies[MAX_ENEMIES];
    int num_enemies;
    int maze[HEIGHT][WIDTH];
    int running;
} GameState;

// Function prototypes
void init_game_state(GameState *gamestate);
void cleanup_game_state(GameState *gamestate);

// Enemy
void render_enemies(GameState *gamestate);
void update_enemies(GameState *gamestate, float delta_time);

// Maze
void generate_maze(GameState *gamestate);

// Player
void move_player(GameState *gamestate, double distance);

#endif // GAMESTATE_H