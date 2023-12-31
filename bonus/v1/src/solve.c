/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static char is_square_valid(char *map, size_t map_w, size_t i, size_t size)
{
    i += size - 1;
    for (size_t line_cnt = -1; ++line_cnt < size - 1; i += map_w + 1)
        if (map[i] != '.')
            return 0;
    for (size_t j = 0; j < size; j++) {
        if (map[i] != '.')
            return 0;
        i--;
    }
    return 1;
}

static size_t get_max_square(char *map, ssize_t map_w, size_t i)
{
    char ret = 1;
    size_t result = 1;

    for (; ret; result++) {
        ret = is_square_valid(map, map_w, i, result);
        if (!ret)
            return result - 1;
    }
    return 0;
}

static void draw_square(char *map, size_t map_w, size_t i, size_t size)
{
    size_t j;

    for (size_t line_cnt = -1; ++line_cnt < size; i = j + map_w + 1) {
        j = i;
        for (size_t line_prg = -1; ++line_prg < size; i++)
            map[i] = 'x';
    }
}

void solve(char *map, size_t map_w)
{
    size_t i = 0;
    size_t x = 0;
    size_t max = 0;
    size_t max_pos = 0;
    size_t current = 0;

    for (; map[i] && ((map[i] > 47 && map[i] < 58) || map[i] == '\n'); i++);
    for (; map[i]; i++) {
        x = map[i] == '\n' ? 0 : x + 1;
        if (map[i] != '.' || x + max > map_w)
            continue;
        current = get_max_square(map, map_w, i);
        if (current > max) {
            max = current;
            max_pos = i;
        }
    }
    draw_square(map, map_w, max_pos, max);
}
