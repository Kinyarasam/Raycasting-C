#include "../include/astar.h"
#include "../include/maze.h"
#include <stdlib.h>
#include <math.h>

static float heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

static Node* get_node(Grid* grid, int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return NULL;
    return grid->nodes[y][x];
}

static void init_node(Node* node, int x, int y, bool is_obstacle) {
    node->pos.x = x;
    node->pos.y = y;
    node->g_cost = INFINITY;
    node->h_cost = 0;
    node->parent = NULL;
    node->is_obstacle = is_obstacle;
    node->is_closed = false;
    node->is_open = false;
}

void init_grid(Grid* grid, int maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Node* node = (Node*)malloc(sizeof(Node));
            init_node(node, x, y, maze[y][x] == 1);
            grid->nodes[y][x] = node;
        }
    }
}

void free_grid(Grid* grid) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            free(grid->nodes[y][x]);
        }
    }
}

bool find_path(Grid* grid, Point start, Point end, Point* path, int* path_length) {
    Node* start_node = get_node(grid, start.x, start.y);
    Node* end_node = get_node(grid, end.x, end.y);

    if (!start_node || !end_node || start_node->is_obstacle || end_node->is_obstacle) {
        return false;
    }

    start_node->g_cost = 0;
    start_node->h_cost = heuristic(start, end);
    start_node->is_open = true;

    Node* open_list[HEIGHT * WIDTH];
    int open_count = 0;
    open_list[open_count++] = start_node;

    while (open_count > 0) {
        Node* current_node = open_list[0];
        int current_index = 0;
        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->g_cost + open_list[i]->h_cost < current_node->g_cost + current_node->h_cost) {
                current_node = open_list[i];
                current_index = i;
            }
        }

        open_list[current_index] = open_list[--open_count];
        current_node->is_open = false;
        current_node->is_closed = true;

        if (current_node == end_node) {
            int path_index = 0;
            while (current_node != NULL) {
                path[path_index++] = current_node->pos;
                current_node = current_node->parent;
            }
            *path_length = path_index;
            return true;
        }

        Point neighbors[4] = {
            { current_node->pos.x + 1, current_node->pos.y },
            { current_node->pos.x - 1, current_node->pos.y },
            { current_node->pos.x, current_node->pos.y + 1 },
            { current_node->pos.x, current_node->pos.y - 1 }
        };

        for (int i = 0; i < 4; i++) {
            Node* neighbor = get_node(grid, neighbors[i].x, neighbors[i].y);
            if (neighbor == NULL || neighbor->is_obstacle || neighbor->is_closed) {
                continue;
            }

            float new_g_cost = current_node->g_cost + 1; // Each step has a cost of 1
            if (new_g_cost < neighbor->g_cost) {
                neighbor->g_cost = new_g_cost;
                neighbor->h_cost = heuristic(neighbor->pos, end);
                neighbor->parent = current_node;

                if (!neighbor->is_open) {
                    neighbor->is_open = true;
                    open_list[open_count++] = neighbor;
                }
            }
        }
    }

    return false;
}
