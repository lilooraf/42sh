/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putsrt
*/

#include <unistd.h>

void my_putchar(char c);
void my_putchar_to(char c, int output);

int my_putstr_to(char const *str, int output)
{
    int adresse = 0;

    while (str[adresse] != '\0') {
        my_putchar_to(str[adresse], output);
        adresse++;
    }
}

int my_putstr(char const *str)
{
    int adresse = 0;

    while (str[adresse] != '\0') {
        my_putchar(str[adresse]);
        adresse++;
    }
}