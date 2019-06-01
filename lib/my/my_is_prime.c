/*
** EPITECH PROJECT, 2018
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int d = 3;

    if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
        return (0);
    if (nb <= 3)
        return (1);
    while (d * d <= nb) {
        if (nb % d == 0)
            return (0);
        d = d + 2;
    }
    return (1);
}
