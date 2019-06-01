/*
** EPITECH PROJECT, 2019
** strcpy_end
** File description:
** strcpy_end
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
void *my_calloc(size_t elem_size, size_t elems);

char *strcpy_end(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *tmp = NULL;

    if (src == NULL)
        return (dest);
    tmp = my_calloc(sizeof(char), (my_strlen(dest) + my_strlen(src) + 1));
    while (dest[i] != 0) {
        tmp[i] = dest[i];
        i++;
    }
    while (src[j] != 0) {
        tmp[i] = src[j];
        i++;
        j++;
    }
    return (tmp);
}