/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Return 1 if a str contains numbers.
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str))
            return (0);
        ++str;
    }
    return (1);
}
