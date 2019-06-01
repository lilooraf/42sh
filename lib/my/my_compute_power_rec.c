/*
** EPITECH PROJECT, 2018
** my_compute_power_rec
** File description:
** my_compude_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (power <= 1)
        return nb;
    return (nb * my_compute_power_rec(nb, power - 1));
}
