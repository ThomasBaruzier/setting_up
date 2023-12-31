/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static void forward_generic(unsigned *node, char *map, size_t dest)
{
    if (map[dest] == '.') {
        map[dest] = '#';
        node[0]++;
        node[node[0]] = dest;
    }
}

void forward_nodes(unsigned **nodes, char *map, size_t *size)
{
    size_t dest;
    unsigned *swap = nodes[CUR];
    const unsigned end = nodes[CUR][0] + 1;

    nodes[CUR] = nodes[PREV];
    nodes[PREV] = swap;
    nodes[CUR][0] = 0;
    for (size_t i = 1; i < end; i++) {
        dest = nodes[PREV][i] - size[X_] - 2;
        forward_generic(nodes[CUR], map, dest);
        forward_generic(nodes[CUR], map, dest + 1);
        forward_generic(nodes[CUR], map, dest + 2);
        forward_generic(nodes[CUR], map, nodes[PREV][i] - 1);
        forward_generic(nodes[CUR], map, nodes[PREV][i] + 1);
        dest = nodes[PREV][i] + size[X_];
        forward_generic(nodes[CUR], map, dest);
        forward_generic(nodes[CUR], map, dest + 1);
        forward_generic(nodes[CUR], map, dest + 2);
    }
}

void init_edges(unsigned **nodes, char *map, size_t *size)
{
    size_t i;

    for (i = size[S_]; i < size[S_] + size[X_]; i++)
        forward_generic(nodes[TOP], map, i);
    for (i++; i < size[E_] - size[X_]; i += 2) {
        forward_generic(nodes[LEFT], map, i);
        i += size[X_] - 1;
        forward_generic(nodes[RIGHT], map, i);
    }
    for (; i < size[E_]; i++)
        forward_generic(nodes[DOWN], map, i);
}

void forward_edges(unsigned **nodes, char *map, size_t *size)
{
    unsigned *swap;

    for (unsigned i = 0; i < 4; i++) {
        swap = nodes[i];
        nodes[i] = nodes[i + 4];
        nodes[i + 4] = swap;
        nodes[i][0] = 0;
    }
    for (size_t i = 1; i < nodes[PTOP][0] + 1; i++)
        forward_generic(nodes[TOP], map, nodes[PTOP][i] + size[X_] + 1);
    for (size_t i = 1; i < nodes[PDOWN][0] + 1; i++)
        forward_generic(nodes[DOWN], map, nodes[PDOWN][i] - size[X_] - 1);
    for (size_t i = 1; i < nodes[PLEFT][0] + 1; i++)
        forward_generic(nodes[LEFT], map, nodes[PLEFT][i] + 1);
    for (size_t i = 1; i < nodes[PRIGHT][0] + 1; i++)
        forward_generic(nodes[RIGHT], map, nodes[PRIGHT][i] - 1);
}
