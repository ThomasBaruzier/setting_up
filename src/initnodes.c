/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static void fill_nodes(unsigned **nodes, char *map, size_t *size)
{
    size_t node = 0;
    size_t i;

    for (i = size[S_]; i < size[E_]; i++) {
        if (map[i] == 'o') {
            node++;
            nodes[CUR][node] = i;
        }
    }
    nodes[CUR][0] = node;
    nodes[PREV][0] = 0;
}

void free_nodes(unsigned **nodes)
{
    if (!nodes)
        return;
    for (int i = 0; i < 10; i++)
        if (nodes[i])
            free(nodes[i]);
    free(nodes);
}

static char free_if_issue(unsigned **nodes, char *map)
{
    for (int i = 0; i < 10; i++) {
        if (!nodes[i]) {
            free(map);
            free_nodes(nodes);
            return 0;
        }
    }
    return 1;
}

unsigned **init_nodes(char *map, size_t *size)
{
    unsigned to_alloc;
    unsigned **nodes = malloc(10 * sizeof(unsigned *));

    if (!nodes)
        return NULL;
    nodes[CUR] = malloc((size[X_] * size[Y_] + 1) * sizeof(unsigned));
    nodes[PREV] = malloc((size[X_] * size[Y_] + 1) * sizeof(unsigned));
    for (int i = 0; i < 8; i++) {
        to_alloc = size[(i % 2) + 3] + 1 - i % 2 * 2;
        nodes[i] = malloc(to_alloc * sizeof(unsigned));
        if (!nodes[i])
            break;
        nodes[i][0] = 0;
    }
    if (!free_if_issue(nodes, map))
        return NULL;
    fill_nodes(nodes, map, size);
    return nodes;
}
