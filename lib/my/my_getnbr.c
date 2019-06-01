/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int signes(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return (0);
}

int nombres(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int my_getnbr(char *str)
{
    int nbr = 0;
    int index = 0;
    int signe = 1;

    if (!str)
        return 0;
    while (signes(str[index]) == 1) {
        if (str[index] == '-')
            signe = signe * -1;
        index++;
    }
    while (nombres(str[index]) == 1) {
        nbr = ((nbr * 10) + (str[index] - '0'));
        index++;
    }
    return (nbr * signe);
}
