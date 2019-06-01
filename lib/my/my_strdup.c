/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

void my_putchar(char c);

void my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char *src)
{
    int size = my_strlen(src) + 1;
    char *dest = malloc(sizeof(char) * size);
    dest = my_strcpy(dest, src);
    return dest;
}
