/*
** EPITECH PROJECT, 2019
** my_clear_str
** File description:
** my_clear_str
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

char *ftc_clear(int j, char *str, char *tmp, char *dest)
{
    int i = 0;

    for (i = 0; dest[i] != 0; i++)
        if (dest[i] == '\t' || dest[i] == '\n')
            dest[i] = ' ';
    for (i = 0; dest[i] == ' ' && dest[i] != 0; i++);
    for (; dest[i] != 0; i++)
        if (dest[i] == ' ' && dest[i + 1] == ' ');
        else {
            tmp[j] = dest[i];
            j++;
        }
    if (j != 0)
        if (tmp[j - 1] == ' ')
            tmp[j - 1] = '\0';
    free (dest);
    dest = my_strdup(tmp);
    free(tmp);
    return (dest);
}

char *my_clear_str(char *str)
{
    int j = 0;
    char *tmp = my_calloc(sizeof(char), my_strlen(str));
    char *dest = my_strdup(str);

    if (!my_strcmp(str, "\n"))
        return (str);
    return (ftc_clear(j, str, tmp, dest));
}