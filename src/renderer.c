#include "renderer.h"
#include "raycasting.h"
#include "main.h"
#include <math.h>

#define MINIMAP_SCALE 5
#define MINIMAP_PLAYER_RADIUS 3
#define FOV_ANGLE (M_PI / 4)

void adjust_brightness(Uint8* r, Uint8* g, Uint8* b, float factor) {
    *r = (Uint8)(*r * factor);
    *g = (Uint8)(*g * factor);
    *b = (Uint8)(*b * factor);
}

/**
 * render_scene - Renders the scene by casting the rays for each vertical slice
 * @renderer: The SDL_renderer used for drawing.
 * @player: The player object containing the player's position and direction
 * 
 * This function loops through each vertical slice of the screen and calls
 * the cast_ray function to render the scene from the players perspective.
*/
void render_scene(GameState *gamestate) {
    Uint8 sky_r = 135, sky_g = 206, sky_b = 235;
    Uint8 ground_r = 189, ground_g = 164, ground_b = 157;

    SDL_SetRenderDrawColor(gamestate->renderer, sky_r, sky_g, sky_b, 255);
    SDL_Rect skyRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(gamestate->renderer, &skyRect);
    
    SDL_SetRenderDrawColor(gamestate->renderer, ground_r, ground_g, ground_b, 255);
    SDL_Rect groundRect = { 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderFillRect(gamestate->renderer, &groundRect);
    
    for (int x = 0; x < SCREEN_HEIGHT; x++) {
        cast_ray(gamestate, x);
    }
}

void draw_circle(SDL_Renderer *renderer, int x, int y, int radius) {
    const double PI = (22 / 7);

    for (int i = -180; i < 180; i++) {
        double angle = (i * PI) / 180;
        int circleX = x + radius * cos(angle);
        int circleY = y + radius * sin(angle);
        SDL_RenderDrawPoint(renderer, circleX, circleY);
    }
}

void render_minimap(GameState *gamestate) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (gamestate->maze[x][y] == 1) {
                SDL_SetRenderDrawColor(gamestate->renderer, 0, 0, 255, 255);
            } else {
                SDL_SetRenderDrawColor(gamestate->renderer, 125, 125, 255, 0);
            }
            SDL_Rect cell = { x * MINIMAP_SCALE, y * MINIMAP_SCALE, MINIMAP_SCALE, MINIMAP_SCALE };
            SDL_RenderFillRect(gamestate->renderer, &cell);
        }
    }

    SDL_SetRenderDrawColor(gamestate->renderer, 255, 0, 0, 255);
    int playerX = (int)(gamestate->player.x * MINIMAP_SCALE);
    int playerY = (int)(gamestate->player.y * MINIMAP_SCALE);
    // SDL_Rect playerRect = { }
    SDL_RenderDrawPoint(gamestate->renderer, playerX, playerY);
    draw_circle(gamestate->renderer, playerX, playerY, MINIMAP_PLAYER_RADIUS);

    SDL_SetRenderDrawColor(gamestate->renderer, 0, 255, 0, 255);
    double fov_start_angle = gamestate->player.angle - FOV_ANGLE / 2;
    double fov_end_angle = gamestate->player.angle + FOV_ANGLE / 2;

    SDL_RenderDrawLine(gamestate->renderer, playerX, playerY,
                       playerX + cos(fov_start_angle) * 20,
                       playerY + sin(fov_start_angle) * 20);
    SDL_RenderDrawLine(gamestate->renderer, playerX, playerY,
                       playerX + cos(fov_end_angle) * 20,
                       playerY + sin(fov_end_angle) * 20);
}
