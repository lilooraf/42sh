/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

void *my_calloc(size_t elem_size, size_t elems);

char **my_str_to_word_array(char *str)
{
    int j = 2;
    int size;
    char **dest;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == '\n')
            j++;
    dest = malloc(sizeof(char *) * j);
    for (j = 0; str[0] != 0; j++) {
        if (str[0] == '\n')
            str = str + 1;
        for (size = 0; str[size] != '\n' && str[size] != 0; size++);
        dest[j] = my_calloc(sizeof(char), size);
        for (size = 0; str[size] != '\n' && str[size] != 0; size++)
            dest[j][size] = str[size];
        str = str + size;
    }
    dest[j] = NULL;
    return (dest);
}
