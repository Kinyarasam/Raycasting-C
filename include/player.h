#ifndef __PLAYER_H__
#define __PLAYER_H__

typedef struct{
    double x, y;
    double angle;
} Player;

void move_player(Player *player, double distance);

#endif /** __PLAYER_H__ */
