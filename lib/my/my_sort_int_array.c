/*
** EPITECH PROJECT, 2018
** my_sort_int_array
** File description:
** my_sort_int_array
*/

void my_putchar(char c);
void my_put_nbr(int nb);
void my_swap(int *a, int *b);

void condition(int i, int count, int *array)
{
    if (array[i] > array[count])
        my_swap(&array[i], &array[count]);
}
void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int count = 0;

    while (i != size) {
        while (count != size) {
            condition(i, count, array);
            count++;
        }
        my_put_nbr(array[i]);
        my_putchar('\n');
        i++;
        count = i;
    }
}
