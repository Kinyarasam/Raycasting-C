// #include "enemy.h"
#include "gamestate.h"
#include "astar.h"

#define ENEMY_SPEED 0.05

void render_enemies(GameState *gamestate) {
    for (int i = 0; i < gamestate->num_enemies; i++) {
        double dx = gamestate->enemies[i].x - gamestate->player.x;
        double dy = gamestate->enemies[i].y - gamestate->player.y;
        float distance = sqrt(dx * dx + dy * dy);

        double angle_to_enemy = atan2f(dx, dy) - gamestate->player.angle;
        int screenX = (int)(SCREEN_WIDTH / 2) + tanf(angle_to_enemy) * SCREEN_WIDTH / 2;
        int screenY = (SCREEN_HEIGHT / 2);

        int enemy_size = (int)(SCREEN_HEIGHT / distance);

        SDL_Rect enemyRect = { screenX - enemy_size / 2, screenY - enemy_size / 2, enemy_size, enemy_size };
        SDL_RenderCopy(gamestate->renderer, gamestate->enemy_texture, NULL, &enemyRect);
    }
}

void update_enemies(GameState *gamestate, float delta_time) {
    Grid grid;
    init_grid(&grid, gamestate->maze);

    for (int i = 0; i < gamestate->num_enemies; i++) {
        Point start = { (int)gamestate->enemies[i].x, (int)gamestate->enemies[i].y };
        Point end = { (int)gamestate->player.x, (int)gamestate->player.y };
        Point path[HEIGHT * WIDTH];
        int path_length;

        if (find_path(&grid, start, end, path, &path_length)) {
            if (path_length > 1) {
                Point next_pos = path[path_length - 2];
                float dirX = next_pos.x - gamestate->enemies[i].x;
                float dirY = next_pos.y - gamestate->enemies[i].y;
                float distance = sqrtf(dirX * dirY + dirY * dirY);

                dirX /= distance;
                dirY /= distance;

                float newX = gamestate->enemies[i].x + dirX * ENEMY_SPEED * delta_time;
                float newY = gamestate->enemies[i].y + dirY * ENEMY_SPEED * delta_time;

                 // Check if the new position is within the maze and not a wall
                 if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && gamestate->maze[(int)newY][(int)newX] == 0) {
                    gamestate->enemies[i].x = newX;
                    gamestate->enemies[i].y = newY;
                }

                gamestate->enemies[i].angle = atan2f(dirY, dirX);
            }
        }
    }

    free_grid(&grid);
}
