/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** my_strncmp
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int j = 0;

    if (s1 == NULL || s2 == NULL)
        return (0);
    while (i != n && s1[i] != '\0')
        i++;
    while (j != n && s2[j] != '\0')
        j++;
    return (i - j);
}
