/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

#include <stddef.h>

int my_strcmp(char const *s2, char const *s1)
{
    int i = 0;

    if (!s1 || !s2)
        return 0;
    while (s1[i] && (s1[i] == s2[i]))
        i++;
    return s1[i] - s2[i];
}