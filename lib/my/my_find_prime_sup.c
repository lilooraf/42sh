/*
** EPITECH PROJECT, 2018
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = 0;

    i = my_is_prime(nb);
    while (i == 0) {
        nb++;
        i = my_is_prime(nb);
    }
    return (nb);
}
