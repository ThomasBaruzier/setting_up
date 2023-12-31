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
    write(2, "\n", 1);
    write(2, map + size[S_], size[E_] - size[S_] + 1);
    write(2, "\n", 1);
    for (; nodes[CUR][0]; size[SQR]++) {
        T1(0);
        forward_nodes(nodes, map, size);
        if (size[SQR])
            forward_edges(nodes, map, size);
        else
            init_edges(nodes, map, size);
        write(2, "\n", 1);
        write(2, map + size[S_], size[E_] - size[S_] + 1);
        write(2, "\n", 1);
        T2(0, "solving nodes");
    }
    T1(1);
    if (!size[SQR])
        return;
    mark_solutions(nodes, map, 'x');
    if (!find_best_sqr_center(nodes, map, size))
        return;
    mark_solutions(nodes, map, '.');
    T2(1, "finding best solution");
    T1(2);
    clean_map(map, size);
    T2(2, "repairing map");
    T1(3);
    draw_square(map, size, size[SQR], size[LOC]);
    T2(3, "drawing square");
}

char solve(char *map, size_t *size)
{
    unsigned **nodes;
    size_t i = size[S_];

    if (size[X_] < 2 || size[Y_] < 2) {
        for (; i < size[E_] && map[i] != '.'; i++);
        map[i] = map[i] == '.' ? 'x' : map[i];
    } else {
        T1(2);
        nodes = init_nodes(map, size);
        if (!nodes)
            return error(MALL);
        T2(2, "initializing nodes");
        T1(1);
        if (!nodes[CUR][0])
            draw_square(map, size, MIN(size[X_], size[Y_]), size[S_]);
        else
            solve_nodes(nodes, map, size);
        T2(1, "solving total");
        free_nodes(nodes);
    }
    write(1, map + size[S_], size[E_] - size[S_] + 1);
    free(map);
    return 0;
}
