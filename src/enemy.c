#include "enemy.h"
#include "main.h"
#include <math.h>
#include "maze.h"
#include "astar.h"

#define ENEMY_SPEED 0.05

void render_enemies(SDL_Renderer *renderer, Enemy *enemies, int num_enemies, SDL_Texture *enemy_texture, int playerX, int playerY, double player_angle) {
    for (int i = 0; i < num_enemies; i++) {
        double dx = enemies[i].x - playerX;
        double dy = enemies[i].y - playerY;
        float distance = sqrt(dx * dx + dy * dy);

        double angle_to_enemy = atan2f(dx, dy) - player_angle;
        int screenX = (int)(SCREEN_WIDTH / 2) + tanf(angle_to_enemy) * SCREEN_WIDTH / 2;
        int screenY = (SCREEN_HEIGHT / 2);

        int enemy_size = (int)(SCREEN_HEIGHT / distance);

        SDL_Rect enemyRect = { screenX - enemy_size / 2, screenY - enemy_size / 2, enemy_size, enemy_size };
        SDL_RenderCopy(renderer, enemy_texture, NULL, &enemyRect);
    }
}

void update_enemies(Enemy *enemies, int num_enemies, float playerX, float playerY, int maze[HEIGHT][WIDTH], float delta_time) {
    Grid grid;
    init_grid(&grid, maze);

    for (int i = 0; i < num_enemies; i++) {
        Point start = { (int)enemies[i].x, (int)enemies[i].y };
        Point end = { (int)playerX, (int)playerY };
        Point path[HEIGHT * WIDTH];
        int path_length;

        if (find_path(&grid, start, end, path, &path_length)) {
            if (path_length > 1) {
                Point next_pos = path[path_length - 2];
                float dirX = next_pos.x - enemies[i].x;
                float dirY = next_pos.y - enemies[i].y;
                float distance = sqrtf(dirX * dirY + dirY * dirY); /** @bug: possible bug */

                dirX /= distance;
                dirY /= distance;

                float newX = enemies[i].x + dirX * ENEMY_SPEED * delta_time;
                float newY = enemies[i].y + dirY * ENEMY_SPEED * delta_time;

                if (maze[(int)enemies[i].x] == 0) {
                    enemies[i].x = newX;
                }
                if (maze[(int)enemies[i].y] == 0) {
                    enemies[i].y = newY;
                }

                enemies[i].angle = atan2f(dirY, dirX);
            }
        }
    }

    free_grid(&grid);
}
