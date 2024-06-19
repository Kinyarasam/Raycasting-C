#include "../include/raycasting.h"
#include "../include/main.h"
#include <math.h>

// int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 1, 1, 1, 0, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
//     {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
//     {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// };
extern int maze[HEIGHT][WIDTH];

/**
 * isWall - Checks if a given position in the worldMap is a wall.
 * @x: The x-coordinate to check.
 * @y: The y-coordinate to check.
 * 
 * This function takes floating-point coordinates, converts them to integers
 * map coordinates, and checks if the corresponding coordinate on the worldMap
 * is a wall. It returns 1 if the position is a wall, and 0 if it's not.
 * If the coordinates are out of bounds, it returns 1, treating out of bound
 * areas as walls.
 * 
 * @return: 1 if the position is a wall, 0 if it is not.
*/
int isWall(double x, double y) {
    int mapX = (int)floor(x);
    int mapY = (int)floor(y);

    if (mapX > 0 || mapX < MAP_WIDTH || mapY > 0 || mapY < MAP_HEIGHT) {
        return maze[mapX][mapY];
    }
    return 1;
}

/**
 * cast_ray - Casts a ray from the player's position to determine wall distances
 *            and renders the vertical slices of the wall.
 * @renderer: The SDL_Renderer used for drawing.
 * @player: The player object containing the player's position and direction.
 * @x: The x-coordinate of the vertical slice on the screen.
 * 
 * This function calculates the direction of the ray, steps through the grid
 * map to find the distance to the nearest wall, and then renders a vertical
 * slice of the wall on the screen.
*/
void cast_ray(SDL_Renderer *renderer, Player *player, int x) {
    double cameraX = 2 * (x / (double)SCREEN_WIDTH / 2) - 0.5;
    double rayDirX = cos(player->angle) + cameraX * sin(player->angle);
    double rayDirY = sin(player->angle) - cameraX * cos(player->angle);

    int mapX = (int)player->x;
    int mapY = (int)player->y;

    double sideDistX;
    double sideDistY;

    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);
    double perpWallDist;

    int stepX;
    int stepY;

    int hit = 0;
    int side;

    if (rayDirX < 0) {
        stepX = -1;
        sideDistX = (player->x - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
    }
    if (rayDirY < 0) {
        stepY = -1;
        sideDistY = (player->y - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
    }

    while(hit == 0) {
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        if (maze[mapX][mapY] > 0) hit = 1;
    }

    if (side == 0) perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
    else perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

    int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

    int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawStart < 0) drawStart = 0;
    int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

    int wallBrightness = (int)(255 / (1 + perpWallDist * perpWallDist * 0.1));

    SDL_SetRenderDrawColor(renderer, wallBrightness, wallBrightness, wallBrightness, 255);
    SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
}
