/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

size_t verify(char *map, size_t *size)
{
    size_t i = size[S_];
    size_t line_pgr = 0;

    if (size[X_] == 0 || size[Y_] == 0)
        return 0;
    for (size_t line_cnt = 0; map[i] && line_cnt < size[Y_]; line_cnt++) {
        for (line_pgr = 0; map[i] == '.' || map[i] == 'o'; i++)
            line_pgr++;
        if (map[i] != '\n' || line_pgr != size[X_])
            return 0;
        i++;
    }
    if (map[i] != '#' || i - 1 != size[E_])
        return 0;
    return 1;
}

static size_t generate_loop(char **map, size_t *size, char *pattern, size_t i)
{
    size_t j = 0;
    size_t pattern_len = len(pattern);

    for (size_t k = 0; i < size[E_];) {
        for (; k < pattern_len && j < size[X_]; k++) {
            (*map)[i] = pattern[k];
            i++;
            j++;
        }
        if (j == size[X_]) {
            (*map)[i] = '\n';
            i++;
            j = 0;
        }
        if (k == pattern_len)
            k = 0;
    }
    return i;
}

void generate(char **map, size_t *size, char *pattern)
{
    size_t i = 0;

    size[S_] = size[X_] + 2;
    size[E_] = size[S_] + size[X_] * (size[X_] + 1) - 1;
    *map = malloc(size[E_] + size[X_] + 2);
    if (!*map || !pattern)
        return;
    for (size_t k = -1; ++k < size[X_] + 2; i++)
        (*map)[i] = '#';
    i = generate_loop(map, size, pattern, i);
    for (size_t k = -1; ++k < size[X_]; i++)
        (*map)[i] = '#';
    (*map)[i] = '\0';
}
