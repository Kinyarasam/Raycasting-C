#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <SDL2/SDL.h>
#include "maze.h"

typedef struct {
    double x;
    double y;
    double angle;
} Enemy;

void render_enemies(SDL_Renderer *renderer, Enemy *enemies, int num_enemies, SDL_Texture *enemy_texture, int playerX, int playerY, double player_angle);
void update_enemies(Enemy *enemies, int num_enemies, float playerX, float playerY, int maze[HEIGHT][WIDTH], float delta_time);

#endif /** __ENEMY_H__ */
