#ifndef __RAYCASTING_H__
#define __RAYCASTING_H__

#include "player.h"
#include "maze.h"
#include <SDL2/SDL.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

extern int worldMap[MAP_WIDTH][MAP_HEIGHT];
// extern int maze[MAZE_WIDTH][MAZE_HEIGHT];

int isWall(double x, double y);
void cast_ray(SDL_Renderer *renderer, Player *player, int x);

#endif /** __RAYCASTING_H__ */
