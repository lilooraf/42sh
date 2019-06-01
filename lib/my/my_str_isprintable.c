/*
** EPITECH PROJECT, 2018
** my_str_isprintable
** File description:
** my_str_printable
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 126)
            i++;
        else
            return (0);
    }
    return (1);
}
