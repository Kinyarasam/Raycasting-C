#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "player.h"
#include "maze.h"
#include <SDL2/SDL.h>

void render_scene(SDL_Renderer *renderer, Player *player);
void render_minimap(SDL_Renderer *renderer, Player *player, int maze[HEIGHT][WIDTH]);

#endif /** __RENDERER_H__ */
