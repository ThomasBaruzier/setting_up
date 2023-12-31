/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

static size_t read_fd(int fd, char *data, ssize_t to_read, size_t offset)
{
    ssize_t total = 0;

    if (data == NULL)
        return 0;
    for (ssize_t bytes = 1; total < to_read && bytes > 0; total += bytes)
        bytes = read(fd, data + offset + total, to_read - total);
    if (total < to_read)
        return 0;
    data[to_read + offset] = '\0';
    return total;
}

static char read_map_offset(int fd, char **data, char *buf, size_t *size)
{
    unsigned i = 0;
    unsigned to_malloc = size[E_] + size[O_] + 2;

    *data = malloc(to_malloc);
    if (!*data)
        return error(MALL);
    for (i = 0; i < size[O_] && i < to_malloc - 1; i++)
        (*data)[i] = '#';
    for (unsigned j = -1; ++j < size[2] && i < to_malloc - 1; i++)
        (*data)[i] = buf[j];
    if (i > to_malloc - 2 || (size[3] > BUF &&
        !read_fd(fd, *data, size[3] - size[2], size[O_] + size[2])))
        return error(READ);
    size[2] = size[O_] + size[3] + size[O_];
    for (i = size[O_] + size[3]; i < size[2] && i < to_malloc - 1; i++)
        (*data)[i] = '#';
    if (i != to_malloc - 1)
        return error(MAPI);
    (*data)[i] = '\0';
    return 0;
}

static char read_map_sizes(int fd, char **data, size_t *size, size_t filesize)
{
    size_t to_read = MIN(BUF, filesize);
    size_t i = 0;
    char buf[BUF + 1] = "\0";

    if (!read_fd(fd, (char *)&buf, to_read, 0))
        return error(READ);
    for (; i < to_read && buf[i] >= '0' && buf[i] <= '9'; i++);
    if (i == to_read || buf[i] != '\n')
        return error(MAPI);
    buf[i] = '\0';
    size[Y_] = str_to_int(buf);
    size[X_] = size[Y_] > 0 ? (filesize - i - 1) / size[Y_] - 1 : 1;
    size[O_] = size[X_];
    size[S_] = i + 1 + size[O_];
    size[E_] = filesize + size[O_] - 1;
    buf[i] = '\n';
    if (!size[Y_] || read_map_offset(fd, data, buf,
        (size_t[]){size[O_], size[E_], to_read, filesize}) == 84)
        return error(MAPI);
    return 0;
}

char read_map(const char *path, char **data, size_t *size)
{
    struct stat st;
    int fd = open(path, O_RDONLY);

    if (fd < 0)
        return error(OPEN);
    if ((stat(path, &st) < 0 || st.st_size < 0) && close(fd) < 1)
        return error(STAT);
    if (!S_ISREG(st.st_mode) && close(fd) < 1)
        return error(FILE);
    if (st.st_size + 1 > 1024 * 1024 * 1024 && close(fd) < 1)
        return error(SIZE);
    if (read_map_sizes(fd, data, size, st.st_size) == 84 && close(fd) < 1)
        return 84;
    if (close(fd) < 0) {
        free(*data);
        return error(CLOS);
    }
    return 1;
}
