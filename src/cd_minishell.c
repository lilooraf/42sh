/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** cd_minishell
*/

#include "my.h"

void cd_setenv(char ***senv)
{
    char **str = my_calloc(sizeof(char *), 4);

    str[2] = senv[0][find_line(senv[0], "PWD")] + 4;
    str[1] = "OLDPWD";
    set_valor(senv, str);
    str[2] = getcwd(NULL, 0);
    str[1] = "PWD";
    set_valor(senv, str);
    free_array(str);
}

int cd_arg(char ***senv, char **arg, int i)
{
    if (find_line(senv[0], "HOME") == -1)
        return 0;
    if (arg_nb(arg) == 1 || !my_strcmp(arg[1], "~"))
        i = chdir(senv[0][find_line(senv[0], "HOME")] + 5);
    else {
        if (my_strcmp(arg[1], "-"))
            i = chdir(arg[1]);
        if (!my_strcmp(arg[1], "-"))
            i = chdir(senv[0][find_line(senv[0], "OLDPWD")] + 7);
    }
    if (i != 0) {
        my_putstr_error(arg[1]);
        my_putstr_error(": ");
        my_putstr_error(strerror(errno));
        my_putstr_error(".\n");
        return 1;
    }
    cd_setenv(senv);
    return 0;
}

int cd_minishell(char ***env, char **arg)
{
    if (!my_strcmp(arg[0], "cd") && arg_nb(arg) > 2) {
        my_putstrn_error("cd: Too many arguments.");
        return 1;
    }
    if (!my_strcmp(arg[0], "cd") && arg_nb(arg) <= 2) {
        return (cd_arg(env, arg, 0));
    }
    return 0;
}
