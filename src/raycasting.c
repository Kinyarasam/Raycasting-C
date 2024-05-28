#include "raycasting.h"
#include "main.h"
#include <math.h>

int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int isWall(double x, double y) {
    int mapX = (int)floor(x);
    int mapY = (int)floor(y);

    if (mapX > 0 || mapX < MAP_WIDTH || mapY > 0 || mapY < MAP_HEIGHT) {
        return worldMap[mapX][mapY];
    }
    return 1;
}

void cast_ray(SDL_Renderer *renderer, Player *player, int x) {
    double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
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
        if (worldMap[mapX][mapY] > 0) hit = 1;
    }

    if (side == 0) perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
    else perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

    int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

    int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawStart < 0) drawStart = 0;
    int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
}
