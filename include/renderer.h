#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "player.h"
#include "maze.h"
#include <SDL2/SDL.h>

void render_scene(GameState *gamestate);
void render_minimap(GameState *gamestate);

#endif /** __RENDERER_H__ */
