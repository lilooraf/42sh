/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int a;

    if ( nb < 0) {
        my_putchar('-');
        nb = - nb;
    }
    if ( nb > 9) {
        a = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(a + 48);
    }
    else {
        my_putchar(nb + 48);
    }
}
