/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

size_t filesize(const char *filename)
{
    struct stat st;

    if (!stat(filename, &st))
        return st.st_size;
    return 0;
}

char cat(char *path)
{
    int fd = open(path, O_RDONLY);
    char buf[128];

    if (fd == -1 || read(fd, buf, 0))
        return 84;
    for (int len = 1; len; write(1, buf, len))
        len = read(fd, buf, 128);
    return 0;
}

static char read_fd(const int fd, const long size, char **data)
{
    ssize_t total_bytes = 0;

    for (ssize_t bytes; total_bytes < size; total_bytes += bytes) {
        bytes = read(fd, *data + total_bytes, size - total_bytes);
        if (bytes < 1 && close(fd) < 1) {
            free(*data);
            return 0;
        }
    }
    (*data)[size] = '\0';
    return 1;
}

char read_file(const char *path, char **data)
{
    struct stat st;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return error(OPEN);
    if ((stat(path, &st) < 0 || st.st_size < 0) && close(fd) < 1)
        return error(STAT);
    if (!S_ISREG(st.st_mode) && close(fd) < 1)
        return error(FILE);
    if (st.st_size + 1 > 100 * 1024 * 1024 && close(fd) < 1)
        return error(SIZE);
    for (*data = malloc(st.st_size + 1); !*data && close(fd) < 1;)
        return error(MALL);
    if (!read_fd(fd, st.st_size, data))
        return error(READ);
    if (close(fd) < 0) {
        free(*data);
        return error(CLOS);
    }
    return 1;
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
