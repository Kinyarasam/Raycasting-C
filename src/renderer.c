#include "renderer.h"
#include "raycasting.h"
#include "main.h"

/**
 * render_scene - Renders the scene by casting the rays for each vertical slice
 * @renderer: The SDL_renderer used for drawing.
 * @player: The player object containing the player's position and direction
 * 
 * This function loops through each vertical slice of the screen and calls
 * the cast_ray function to render the scene from the players perspective.
*/
void render_scene(SDL_Renderer *renderer, Player *player) {
    for (int x = 0; x < SCREEN_HEIGHT; x++) {
        cast_ray(renderer, player, x);
    }
}
