/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** setting_up
*/

#include "setting.h"

size_t str_to_int(const char *str)
{
    size_t nbr = 0;
    long p10 = 1;

    for (size_t i = 0; str[i++]; p10 *= 10)
        if (str[i - 1] < '0' || str[i - 1] > '9' || i > 9)
            return -1;
    for (size_t i = 0; str[i++]; p10 /= 10)
        nbr += (str[i - 1] - '0') * (p10 / 10);
    return nbr;
}

void int_to_str(char *str, int nbr)
{
    int size = 1;

    for (long p10 = 10; nbr / p10 != 0; p10 *= 10)
        size++;
    if (nbr == 0)
        str[0] = '0';
    str[size] = '\0';
    for (; nbr != 0; nbr /= 10) {
        size--;
        str[size] = nbr % 10 + 48;
    }
}
