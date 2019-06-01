/*
** EPITECH PROJECT, 2019
** check_num
** File description:
** check_num
*/

int my_strlen(char const *str);

int check_num(char **av)
{
    int j;
    int a = 0;
    int y;

    for (int i = 1; av[i]; i++) {
        for (j = 0, y = 1; av[i][j]; j++, y++) {
            (my_strlen(av[i]) == 1 && av[i][0] == '-') ? a = 1 : a;
            (((av[i][j] < 48 || av[i][j] > 57) && av[i][0] != '-') ||
            ((av[i][y] < 48 || av[i][y] > 57) && av[i][y] != 0)) ? a = 1 : a;
        }
    }
    return (a);
}
