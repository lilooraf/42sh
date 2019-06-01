/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** my_strncpy
*/

#include "criterion/criterion.h"

#include "stdlib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;

    if (src == NULL || n <= 0)
        return (NULL);
    while (src[j] != '\0')
        j++;
    if (j < n)
        return (NULL);
    while (i != n) {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = ('\0');
    return (dest);
}
