#include "maze.h"
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Position;

void shuffle(Position *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - 1) + 1);
            Position t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
}

void generate_maze(int maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[y][x] = 1;
        }
    }

    Position stack[WIDTH * HEIGHT];
    int stackSize = 0;

    Position start = {1, 1};
    maze[start.y][start.x] = 0;
    stack[stackSize++] = start;

    Position directions[4] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};

    srand(time(NULL));

    while(stackSize > 0) {
        Position current = stack[--stackSize];
        shuffle(directions, 4);

        for (int i = 0; i < 4; i++) {
            Position dir = directions[i];
            Position next = {current.x + dir.x, current.y + dir.y};

            if (next.x > 0 && next.x < WIDTH - 1 && next.y > 0 && next.y < HEIGHT - 1 && maze[next.y][next.x] == 1) {
                maze[next.y][next.x] = 0;
                maze[current.y + dir.y / 2][current.x + dir.x / 2] = 0;
                stack[stackSize++] = next;
            }
        }
    }

    maze[0][1] = 0;
    maze[HEIGHT - 1][WIDTH - 2] = 0;
}
