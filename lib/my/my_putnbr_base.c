/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** my_putnbr_base
*/

int my_strlen(char const *str);
void my_putchar(char c);

int my_putnbr_base(int nb, char const *base)
{
    int a;
    int size = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        nb = - nb;
    }
    if (nb > (size - 1)) {
        a = nb % size;
        nb = nb / size;
        my_putnbr_base(nb, base);
        my_putchar(base[a]);
    }
    else
        my_putchar(base[nb]);
}
