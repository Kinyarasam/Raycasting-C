#ifndef __ASTAR_H__
#define __ASTAR_H__

#include <stdbool.h>
#include "maze.h"

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point pos;
    float g_cost, h_cost;
    struct Node *parent;
    bool is_obstacle;
    bool is_closed;
    bool is_open;
} Node;

typedef struct {
    Node* nodes[HEIGHT][WIDTH];
} Grid;

void init_grid(Grid* grid, int maze[HEIGHT][WIDTH]);
void free_grid(Grid* grid);
bool find_path(Grid* grid, Point start, Point end, Point* path, int* path_length);

#endif /** __ASTAR_H__ */
