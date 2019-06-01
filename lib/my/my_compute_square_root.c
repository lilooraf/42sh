/*
** EPITECH PROJECT, 2018
** my_compute_square_root
** File description:
** calcul_of_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 0;
    int count = 1;

    if (nb <= 0)
        return (0);
    else {
        while (nb != 0) {
            nb = nb - count;
            count = count + 2;
            i = i + 1;
        }
        return (i);
    }
}
