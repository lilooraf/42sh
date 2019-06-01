/*
** EPITECH PROJECT, 2019
** putstr_error
** File description:
** putstr_error
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int adresse = 0;

    while (str[adresse] != '\0') {
        my_putchar_error(str[adresse]);
        adresse++;
    }
}

int my_putstrn_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
    my_putchar_error('\n');
}