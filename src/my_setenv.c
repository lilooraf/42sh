/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_setenv
*/

#include "my.h"

int check_var(char *arg)
{
    if ((arg[0] > 122 || arg[0] < 97) && (arg[0] >
        90 || arg[0] < 65) && arg[0] != 95) {
        my_putstrn_error("setenv: Variable name must begin with a letter.");
        return 1;
    }
    for (int i = 1; arg[i]; i++)
        if ((arg[i] > 122 || arg[i] < 97) && (arg[i] >
            90 || arg[i] < 65) && (arg[i] > 57 || arg[i] < 48)) {
            my_putstr_error("setenv: Variable name must contain");
            my_putstrn_error(" alphanumeric characters.");
            return 1;
        }
    return 0;
}

void create_env(char ***senv, char **arg)
{
    int i = 0;

    *senv = save_env(*senv, 1);
    for (i = 0; senv[0][i] != NULL; i++);
    senv[0][i] = strcpy_end(arg[1], "=");
    senv[0][i] = strcpy_end(senv[0][i], arg[2]);
}

int set_valor(char ***senv, char **arg)
{
    int line = find_line(*senv, arg[1]);
    char *tmp;

    if (check_var(arg[1]))
        return 1;
    if (line == -1) {
        create_env(senv, arg);
        return 0;
    }
    tmp = strcpy_end(arg[1], "=");
    tmp = strcpy_end(tmp, arg[2]);
    senv[0][line] = my_strdup(tmp);
    free(tmp);
    return 0;
}

void disp_env(char ***senv)
{
    for (int i = 0; senv[0][i]; my_putstrn(senv[0][i]), i++);
}

int my_setenv(char ***senv, char **arg)
{
    if (!my_strcmp(arg[0], "setenv")) {
        if (arg_nb(arg) > 3) {
            my_putstrn_error("setenv: Too many arguments.");
            return 1;
        }
        if (arg_nb(arg) == 1) {
            disp_env(senv);
            return 0;
        }
        return (set_valor(senv, arg));
    }
    return 0;
}
