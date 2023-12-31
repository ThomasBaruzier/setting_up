/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef SETTING_H
    #define SETTING_H

    #define OPEN 1
    #define STAT 2
    #define MALL 3
    #define READ 4
    #define CLOS 5
    #define ARGN 6
    #define ARGU 7
    #define FILE 8
    #define SIZE 9
    #define MAPI 10

    #define ERR(s) write(2, "ERROR: ", 7) && write(2, s, len(s))
    #define STR(s) write(1, s, len(s))

void solve(char *map, ssize_t map_size);
void print(char *map);

size_t len(const char *str);
char cpy(char *dest, char const *src);
char scmp(char const *s1, char const *s2);
char sccmp(char const *s1, char const *s2);
char isnum(const char *str);

size_t filesize(const char *filename);
char read_file(const char *path, char **data);
char error(int n);

size_t str_to_int(const char *str);
void int_to_str(char *str, int nbr);

#endif
