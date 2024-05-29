#include "renderer.h"
#include "raycasting.h"
#include "main.h"
#include <math.h>

#define MINIMAP_SCALE 5
#define MINIMAP_PLAYER_RADIUS 3
#define FOV_ANGLE (M_PI / 4)

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

void draw_circle(SDL_Renderer *renderer, int x, int y, int radius) {
    const double PI = (22 / 7);

    for (int i = -180; i < 180; i++) {
        double angle = (i * PI) / 180;
        int circleX = x + radius * cos(angle);
        int circleY = y + radius * sin(angle);
        SDL_RenderDrawPoint(renderer, circleX, circleY);
    }
}

void render_minimap(SDL_Renderer *renderer, Player *player, int maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (maze[x][y] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 125, 125, 255, 0);
            }
            SDL_Rect cell = { x * MINIMAP_SCALE, y * MINIMAP_SCALE, MINIMAP_SCALE, MINIMAP_SCALE };
            SDL_RenderFillRect(renderer, &cell);
        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int playerX = (int)(player->x * MINIMAP_SCALE);
    int playerY = (int)(player->y * MINIMAP_SCALE);
    // SDL_Rect playerRect = { }
    SDL_RenderDrawPoint(renderer, player->x, player->y);
    draw_circle(renderer, playerX, playerY, MINIMAP_PLAYER_RADIUS);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    double fov_start_angle = player->angle - FOV_ANGLE / 2;
    double fov_end_angle = player->angle + FOV_ANGLE / 2;

    SDL_RenderDrawLine(renderer, playerX, playerY,
                       playerX + cos(fov_start_angle) * 20,
                       playerY + sin(fov_start_angle) * 20);
    SDL_RenderDrawLine(renderer, playerX, playerY,
                       playerX + cos(fov_end_angle) * 20,
                       playerY + sin(fov_end_angle) * 20);
}
