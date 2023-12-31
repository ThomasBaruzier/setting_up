/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef SETTING_H
    #define SETTING_H

    #define BUF 20

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

    #define TOP 0
    #define RIGHT 1
    #define DOWN 2
    #define LEFT 3
    #define PTOP 4
    #define PRIGHT 5
    #define PDOWN 6
    #define PLEFT 7
    #define PREV 8
    #define CUR 9

    #define O_ 0
    #define E_ 1
    #define S_ 2
    #define X_ 3
    #define Y_ 4
    #define SQR 5
    #define LOC 6
    #define LOW 7

    #define ERR(s) write(2, "ERROR: ", 7) && write(2, s, len(s))
    #define STR(s) write(1, s, len(s))

    #define MIN(a, b) a < b ? a : b
    #define MAX(a, b) a > b ? a : b

char read_map(const char *path, char **data, size_t *size);
size_t verify(char *map, size_t *size);
void generate(char **map, size_t *size, char *pattern);
char solve(char *map, size_t *size);

unsigned **init_nodes(char *map, size_t *size);
void init_edges(unsigned **nodes, char *map, size_t *size);
void forward_nodes(unsigned **nodes, char *map, size_t *size);
void forward_edges(unsigned **nodes, char *map, size_t *size);
void free_nodes(unsigned **nodes);

char error(int n);
size_t len(const char *str);
char isnum(const char *str);
char sccmp(char const *s1, char const *s2);
void int_to_str(char *str, int nbr);
size_t str_to_int(const char *str);

#endif
