/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ftc_minishell
*/

#include "my.h"

void free_array(char **arg)
{
    for (int i = 0; arg[i]; i++)
        free(arg[i]);
    free(arg);
}

void env_minishell(char **env, char **arg)
{
    if (!my_strcmp(arg[0], "env") && arg_nb(arg) == 1)
        for (int i = 0; env[i]; my_putstrn(env[i]), i++);
}

char **save_env(char **env, int size)
{
    int i;
    char **svg;

    for (i = 0; env[i]; i++);
    svg = malloc(sizeof(char *) * (i + 1 + size));
    for (i = 0; env[i]; i++)
        svg[i] = my_strdup(env[i]);
    for (int j = i; j < size + i; j++)
        svg[j] = NULL;
    svg[i + size] = NULL;
    return (svg);
}

int find_line(char **senv, char *arg)
{
    int line = -1;
    int i = 0;

    for (int j = 0; senv[i]; i++) {
        for (j = 0; arg[j] && senv[i][j] == arg[j] && senv[i][j]; j++);
        if (j == my_strlen(arg) && senv[i][j] == '=')
            line = i;
    }
    return (line);
}

int arg_nb(char **arg)
{
    int i;

    for (i = 0; arg[i]; i++);
    return (i);
}
