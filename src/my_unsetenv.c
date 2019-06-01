/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_unsetenv
*/

#include "my.h"

void unset(char ***senv, char *arg)
{
    int i = find_line(*senv, arg);

    if (i == -1)
        return;
    while (senv[0][i + 1]) {
        senv[0][i] = my_strdup(senv[0][i + 1]);
        i++;
    }
    senv[0][i] = NULL;
    senv[0] = save_env(senv[0], 0);
}

int my_unsetenv(char ***senv, char **arg)
{
    if (!my_strcmp(arg[0], "unsetenv")) {
        if (arg_nb(arg) == 1) {
            my_putstrn_error("unsetenv: Too few arguments.");
            return 1;
        }
        for (int i = 1; arg[i]; unset(senv, arg[i]), i++);
    }
    return 0;
}
