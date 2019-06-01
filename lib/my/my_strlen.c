/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int adresse = 0;

    while (str[adresse] != '\0') {
        adresse++;
    }
    return (adresse);
}
