/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

int main(int ac, char **av)
{
    char *map = NULL;
    size_t size[8] = {0};

    T1(1);
    if (ac == 2 && read_map(av[1], &map, size) != 84 && !verify(map, size))
        map[0] = '\0';
    T2(1, "reading and verifying file");
    T1(2);
    if (ac == 3 && isnum(av[1]) && sccmp(av[2], ".o")) {
        size[X_] = str_to_int(av[1]);
        size[Y_] = size[X_];
        if (size[X_] > 0 && size[X_] <= 65500)
            generate(&map, size, av[2]);
    }
    T2(2, "generating file");
    if (!map || !map[0]) {
        if (map && !map[0])
            free(map);
        return error(MAPI);
    }
    return solve(map, size);
}

char error(int n)
{
    n = n == OPEN ? ERR("Failed to open file\n") : n;
    n = n == STAT ? ERR("Failed to get file size information\n") : n;
    n = n == MALL ? ERR("Failed to allocate memory\n") : n;
    n = n == READ ? ERR("Failed to read the file\n") : n;
    n = n == CLOS ? ERR("Failed to close the file\n") : n;
    n = n == ARGN ? ERR("Invalid number of arguments\n") : n;
    n = n == ARGU ? ERR("Invalid usage of arguments\n") : n;
    n = n == FILE ? ERR("Invalid file type\n") : n;
    n = n == SIZE ? ERR("Invalid file size\n") : n;
    n = n == MAPI ? ERR("Invalid map\n") : n;
    return 84;
}
