/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** my_revstr
*/

#include <criterion/criterion.h>
#include <stdlib.h>

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int temp;

    if (str == NULL)
        return (NULL);
    while (str[b] != '\0')
        b++;
    b--;
    while (a < b) {
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
        a++;
        b--;
    }
    return (str);
}
