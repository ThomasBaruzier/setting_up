/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static void draw_square(char *map, size_t *size, size_t sqr_size, size_t i)
{
    size_t j;

    for (size_t line_cnt = -1; ++line_cnt < sqr_size; i = j + size[X_] + 1) {
        j = i;
        for (size_t line_prg = -1; ++line_prg < sqr_size; i++)
            map[i] = 'x';
    }
}

static void mark_solutions(unsigned **nodes, char *map, char mark)
{
    for (unsigned i = 4; i < 9; i++)
        for (unsigned j = 1; j < nodes[i][0] + 1; j++)
            map[nodes[i][j]] = mark;
}

static void clean_map(char *map, size_t *size)
{
    for (size_t i = size[S_]; i < size[E_]; i++)
        if (map[i] == '#')
            map[i] = '.';
}

static void find_loop(unsigned **nodes, char *map, size_t *size, unsigned i)
{
    for (unsigned j = 1; j < nodes[i][0] + 1; j++) {
        if (nodes[i][j] < size[LOC] &&
            map[nodes[i][j] + 1] == 'x' &&
            map[nodes[i][j] + size[X_] + 1] == 'x' &&
            map[nodes[i][j] + size[X_] + 2] == 'x') {
            size[LOC] = nodes[i][j];
        }
        if (nodes[i][j] < size[LOW])
            size[LOW] = nodes[i][j];
    }
}

static char find_best_sqr_center(unsigned **nodes, char *map, size_t *size)
{
    for (unsigned i = 4; i < 9; i++)
        find_loop(nodes, map, size, i);
    if (size[LOW] == size[E_]) {
        mark_solutions(nodes, map, '.');
        clean_map(map, size);
        return 0;
    }
    size[SQR] = ((size[SQR] - 1) * 2);
    if (size[LOC] == size[E_]) {
        size[LOC] = size[LOW];
        size[SQR]--;
    }
    size[LOC] -= ((size[SQR] - 1) / 2) * (size[X_] + 2);
    return 1;
}

static void solve_nodes(unsigned **nodes, char *map, size_t *size)
{
    if (nodes[CUR][0] == size[X_] * size[Y_])
        return;
    size[SQR] = 0;
    size[LOC] = size[E_];
    size[LOW] = size[E_];
    for (; nodes[CUR][0]; size[SQR]++) {
        forward_nodes(nodes, map, size);
        if (size[SQR])
            forward_edges(nodes, map, size);
        else
            init_edges(nodes, map, size);
    }
    if (!size[SQR])
        return;
    mark_solutions(nodes, map, 'x');
    if (!find_best_sqr_center(nodes, map, size))
        return;
    mark_solutions(nodes, map, '.');
    clean_map(map, size);
    draw_square(map, size, size[SQR], size[LOC]);
}

char solve(char *map, size_t *size)
{
    unsigned **nodes;
    size_t i = size[S_];

    if (size[X_] < 2 || size[Y_] < 2) {
        for (; i < size[E_] && map[i] != '.'; i++);
        map[i] = map[i] == '.' ? 'x' : map[i];
    } else {
        nodes = init_nodes(map, size);
        if (!nodes)
            return error(MALL);
        if (!nodes[CUR][0])
            draw_square(map, size, MIN(size[X_], size[Y_]), size[S_]);
        else
            solve_nodes(nodes, map, size);
        free_nodes(nodes);
    }
    write(1, map + size[S_], size[E_] - size[S_] + 1);
    free(map);
    return 0;
}
