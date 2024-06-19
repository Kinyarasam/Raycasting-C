#include "../include/player.h"
#include "../include/raycasting.h"

/**
 * move_player - Moves the player by a certain distance in the direction
 *               they are currently facing
 * @player: The player object containing the player's current position and direction
 * @distance: The distance to move the player.
 * 
 * This function calculates the new position of the player based on their
 * current direction and distance to move. It the checks if the new position
 * is a wall. If the new position is not a wall, it updates the player's position.
*/
void move_player(Player *player, double distance) {
    /** Move player */
    double newX = player->x + distance * cos(player->angle);
    double newY = player->y + distance * sin(player->angle);

    if (isWall(newX, newY) == 1) return;

    player->x = newX;
    player->y = newY;
}
