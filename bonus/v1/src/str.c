/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

size_t len(const char *str)
{
    size_t i = 0;

    for (; str[i]; i++);
    return i;
}

char cpy(char *dest, char const *src)
{
    size_t i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return 1;
}

char scmp(char const *s1, char const *s2)
{
    for (size_t i = 0; s1[i] || s2[i]; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

char sccmp(char const *s1, char const *s2)
{
    char flag;

    for (size_t i = 0; s1[i]; i++) {
        flag = 0;
        for (size_t j = 0; s2[j]; j++)
            flag = s1[i] == s2[j] ? 1 : flag;
        if (!flag)
            return 0;
    }
    return 1;
}

char isnum(const char *str)
{
    for (size_t i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
