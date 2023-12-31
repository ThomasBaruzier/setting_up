/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

void draw_square(char *map, size_t map_size, size_t i, size_t size)
{
    size_t j;

    for (size_t line_cnt = -1; ++line_cnt < size; i = j + map_size + 1) {
        j = i;
        for (size_t line_prg = -1; ++line_prg < size; i++)
            map[i] = 'x';
    }
}

char is_square_valid(char *map, size_t map_size, size_t i, size_t size)
{
    i += size - 1;
    for (size_t line_cnt = -1; ++line_cnt < size - 1; i += map_size + 1) {
        if (map[i] != '.')
            return 0;
        map[i] = '@';
        printf("\n");
        print(map);
        map[i] = '.';
    }
    for (size_t j = 0; j < size; j++) {
        if (map[i] != '.')
            return 0;
        map[i] = '@';
        printf("\n");
        print(map);
        map[i] = '.';
        i--;
    }
    return 1;
}

size_t max_square(char *map, ssize_t map_size, size_t i)
{
    char ret = 1;
    size_t result = 1;

    for (; ret; result++) {
        printf("\033[36m==> TRYING SQUARE OF SIZE %ld\033[0m ", result);
        ret = is_square_valid(map, map_size, i, result);
        if (ret)
            printf("\033[32m--> SUCCESS\033[0m\n");
        else
            printf("\033[31m--> FAIL\033[0m\n");
        if (!ret)
            return result - 1;
    }
    return 0;
}

void solve(char *map, ssize_t map_size)
{
    size_t max = 0;
    size_t max_pos = 0;
    size_t current;

    for (size_t i = 0; map[i]; i++) {
        if (map[i] != '.')
            continue;
        printf("\n\033[40;34mSEARCHING THE BIGGEST ");
        printf("SQUARE AT THIS LOCATION:\033[0m\n");
        map[i] = '#';
        print(map);
        printf("\033[40;34m*****\033[0m\n\n");
        map[i] = '.';
        current = max_square(map, map_size, i);
        if (current > max) {
            max = current;
            max_pos = i;
        }
    }
    draw_square(map, map_size, max_pos, max);
}
