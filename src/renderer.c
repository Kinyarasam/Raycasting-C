#include "renderer.h"
#include "raycasting.h"
#include "main.h"

void render_scene(SDL_Renderer *renderer, Player *player) {
    int x;
    for (x = 0; x < SCREEN_HEIGHT; x++) {
        cast_ray(renderer, player, x);
    }
}
