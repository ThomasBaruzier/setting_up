/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static void generate_nl(char *map, size_t *counter, size_t *i, size_t size)
{
    if (*counter == size) {
        *counter = 0;
        map[*i] = '\n';
        *i += 1;
        return;
    }
}

static char *generate(const size_t size, const char *pattern)
{
    size_t counter = 0;
    size_t square_size = size * (size + 1);
    size_t pattern_len = len(pattern);
    char *map = malloc(square_size + 1);

    if (!map)
        return "0";
    for (size_t i = 0; i < square_size;) {
        for (size_t j = 0; square_size != i && j < pattern_len; j++) {
            map[i] = pattern[j];
            i++;
            counter++;
            generate_nl(map, &counter, &i, size);
        }
    }
    map[square_size] = '\0';
    return map;
}

static size_t get_line_nbr(char *map, size_t *i)
{
    size_t line_nbr;

    for (; map[*i] && map[*i] != '\n'; (*i)++)
        if (map[*i] < '0' || map[*i] > '9')
            return 0;
    if (map[*i] != '\n')
        return 0;
    map[*i] = '\0';
    line_nbr = str_to_int(map);
    map[*i] = '\n';
    return line_nbr;
}

static size_t get_line_len(char *map, size_t *i)
{
    size_t line_len = 0;

    for ((*i)++; map[*i] && map[*i] != '\n'; (*i)++) {
        if (map[*i] != '.' && map[*i] != 'o')
            return 0;
        line_len++;
    }
    if (map[*i] != '\n')
        return 0;
    return line_len;
}

static ssize_t verify_map(char *map)
{
    size_t i = 0;
    size_t line_pgr = 0;
    size_t line_cnt = 0;
    size_t line_nbr = get_line_nbr(map, &i);
    size_t line_len = get_line_len(map, &i);

    if (line_nbr == 0 || line_len == 0)
        return -1;
    for (; map[i] && ++line_cnt != line_nbr;) {
        for (line_pgr = 0; map[++i] && map[i] != '\n'; line_pgr++);
        if ((map[i] != '\0' && map[i] != '\n') || line_pgr != line_len)
            return -1;
    }
    if (map[i + 1] != '\0')
        return -1;
    return line_len;
}

static char handle_errors(char *map, ssize_t size)
{
    if (!map || !map[0]) {
        free(map);
        return error(ARGU);
    }
    if (map[0] == '0')
        return error(MALL);
    if (size < 0)
        return error(MAPI);
    return 0;
}

static char print(char *map)
{
    size_t i = 0;

    for (; map[i] && ((map[i] > 47 && map[i] < 58) || map[i] == '\n'); i++);
    write(1, map + i, len(map + i));
    free(map);
    return 0;
}

int main(int ac, char **av)
{
    char *map = NULL;
    ssize_t map_w = 0;

    if (ac == 2) {
        if (read_file(av[1], &map) == 84)
            return 84;
        map_w = verify_map(map);
    } else if (ac == 3 && isnum(av[1]) && sccmp(av[2], ".o")) {
        map_w = str_to_int(av[1]);
        map = generate(map_w, av[2]);
    }
    if (handle_errors(map, map_w) == 84)
        return 84;
    solve(map, map_w);
    return print(map);
}
