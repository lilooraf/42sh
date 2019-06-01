/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** ftc_minishell_4
*/

#include "my.h"

void disp_error(char *str, int i)
{
    struct stat sta;
    struct stat sfile;

    my_putstr_error(str);
    stat(str, &sta);
    if (access(str, F_OK) == 0) {
        if (S_ISDIR(sta.st_mode) || !(sfile.st_mode & S_IXUSR)) {
            my_putstrn_error(": Permission denied.");
            return;
        }
    }
    if (i) {
        my_putstrn_error(": Permission denied.");
        return;
    }
    my_putstrn_error(": Command not found.");
}

char *find_path_tool_bis(char *arg, char **env)
{
    char **arr = NULL;

    if (find_line(env, "PATH") == -1) {
        disp_error(arg, 1);
        return NULL;
    }
    if (arg[0] == '.' && arg[1] == '/') {
        my_putstr_error(arg);
        my_putstrn_error(": Command not found.");
        return NULL;
    }
    arr = my_str_to_word_array_char(env[find_line(env, "PATH")]+5, ':');
    return (find_path_tool(arr, arg));
}

int check_globing_tool(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '*' || str[i] == '?' || str[i] == '[' || str[i] == ']')
            return 1;
    return 0;
}

int check_globing(char **str)
{
    int r = 0;

    for (int i = 0; str[i]; i++)
        r += check_globing_tool(str[i]);
    return r;
}

char **globing(st_t *st, char **arg)
{
    glob_t globbuff;
    int size = 0;
    int index = 0;

    for (; arg[size]; size++);
    if ((index = check_globing(arg)) == 0 || size == 1)
        return (arg);
    globbuff.gl_pathv = NULL;
    globbuff.gl_pathc = 0;
    globbuff.gl_offs = size - index;
    for (int i = 0; arg[i]; i++)
        if (check_globing_tool(arg[i]))
            glob(arg[i], GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuff);
    for (int i = 0, j = 0; arg[i]; i++)
        if (!check_globing_tool(arg[i])) {
            globbuff.gl_pathv[j] = my_strdup(arg[i]);
            j++;
        }
    globbuff.gl_pathv[((size - index) + globbuff.gl_pathc)] = NULL;
    return (globbuff.gl_pathv);
}
