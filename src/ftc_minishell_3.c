/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ftc_minishell_3
*/

#include "my.h"

void free_all(st_t *st)
{
    free(st->home);
    free(st->alias_rc);
    free(st->clear);
    free(st->file);
    free_array(st->senv);
}

int check_redirect(char **arg)
{
    int a = 0;

    for (int i = 0; arg[i]; i++)
        for (int j = 0; arg[i][j]; j++)
            a += arg[i][j] == '<' || arg[i][j] == '>' ? 1 : 0;
    if (a > 0)
        return 1;
    return 0;
}

int check_builtins(char **arg)
{
    if (!my_strcmp(arg[0], "env") || !my_strcmp(arg[0], "cd") ||
        !my_strcmp(arg[0], "setenv") || !my_strcmp(arg[0], "unsetenv") ||
        !arg[0] || !my_strcmp(arg[0], "exit") || !my_strcmp(arg[0], "\n") ||
        !my_strcmp(arg[0], "alias"))
        return 1;
    return 0;
}

int check_nbr(char *av)
{
    int j;
    int a = 0;
    int y;

    if (!av)
        return (0);
    for (j = 0, y = 1; av[j]; j++, y++) {
        (my_strlen(av) == 1 && av[0] == '-') ? a = 1 : a;
        (((av[j] < 48 || av[j] > 57) && av[0] != '-') ||
        ((av[y] < 48 || av[y] > 57) && av[y] != 0)) ? a = 1 : a;
    }
    return (a);
}

void redirect_r_tool(char ***targ, st_t *st, pid_t cpid, int *inf)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;

    for (int i = 0; targ[i]; i++) {
        if (!my_strcmp(targ[i][0], ">>")) {
            inf[0] = open(targ[i + 1][0], O_RDWR | O_APPEND | O_CREAT, mode);
            inf[2] = i;
        }
        if (!my_strcmp(targ[i][0], ">")) {
            inf[0] = open(targ[i + 1][0], O_RDWR | O_TRUNC | O_CREAT, mode);
            inf[2] = i;
        }
    }
    redirect_r(targ, st, cpid, inf);
}
