/*
** EPITECH PROJECT, 2019
** put str with back slash n
** File description:
** \n
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstrn(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}
