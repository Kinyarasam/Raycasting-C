#include "player.h"
#include "raycasting.h"

void move_player(Player *player, double distance) {
    /** Move player */
    double newX = player->x + distance * cos(player->angle);
    double newY = player->y + distance * sin(player->angle);

    if (isWall(newX, newY) == 1) return;

    player->x = newX;
    player->y = newY;
}
