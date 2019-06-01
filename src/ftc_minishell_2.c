/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ftc_minishell_2
*/

#include "my.h"

char *find_path_tool(char **arr, char *arg)
{
    char *tmp = NULL;

    for (int j = 0; arr[j]; j++) {
        tmp = strcpy_end(strcpy_end(arr[j], "/"), arg);
        if (access(tmp, X_OK) == 0) {
            free_array(arr);
            return tmp;
        }
        free(tmp);
        tmp = NULL;
    }
    free_array(arr);
    disp_error(arg, 0);
    return NULL;
}

char *find_path(char *arg, char **env, st_t *st)
{
    char *tmp = NULL;
    struct stat sta;

    stat(arg, &sta);
    if (access(arg, X_OK) == 0) {
        if (S_ISDIR(sta.st_mode)) {
            my_putstr_error(arg);
            my_putstrn_error(": Permission denied.");
            return NULL;
        }
        return (my_strdup(arg));
    }
    return (find_path_tool_bis(arg, env));
}

void exec_separator(st_t *st, char **arg, int size)
{
    int i = 0;
    int l = 0;
    char **tmp = NULL;
    char **tmp1 = NULL;

    for (i = size; arg[i]; i++);
    tmp = my_calloc(sizeof(char *), size + 1);
    tmp1 = my_calloc(sizeof(char *), (i - size) + 1);
    for (int j = 0; j < size; j++)
        tmp[j] = arg[j];
    for (int j = size + 1; arg[j]; j++, l++)
        tmp1[l] = arg[j];
    exec(st, tmp);
    if (st->i == 0 && !my_strcmp(arg[size], "&&"))
        exec(st, tmp1);
    if (st->i != 0 && !my_strcmp(arg[size], "||")) {
        st->i = 0;
        exec(st, tmp1);
    }
}

char *get_short_cd(void)
{
    char *short_cd = NULL;
    char *cd_name = NULL;
    int i = 0;

    cd_name = getcwd(cd_name, 0);
    for (i = 0; cd_name[i]; i++);
    for (i--; cd_name[i] != '/' && i >= 0; i--);
    short_cd = my_strdup(cd_name + i + 1);
    if (!my_strcmp(short_cd, "")) {
        free(short_cd);
        short_cd = my_strdup("/");
    }
    free(cd_name);
    return short_cd;
}

void print_prompt(void)
{
    char *short_cd = get_short_cd();

    my_putstr(TBBOLD TBWHITE "[" TBCYAN);
    my_putstr(short_cd);
    my_putstr(TBWHITE "] " TRST);
    free(short_cd);
}
