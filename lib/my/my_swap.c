/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
