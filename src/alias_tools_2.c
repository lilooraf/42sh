/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias_tools_2
*/

#include "my.h"

char *get_alias(char *str)
{
    int size = 0;
    char *res = NULL;
    int a = 0;

    if (!str[size])
        return str;
    for (;str[size] != '='; size++);
    size -= 6;
    res = my_calloc(sizeof(char), size);
    for (size = 6; str[size] != '='; size++)
        res[a++] = str[size];
    return res;
}

char *find_cmd_bis(char *str)
{
    char *tmp = NULL;
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '=')
            break;
    str = my_strdup(&str[i + 2]);
    for (i = 0; str[i] != ' ' && str[i]; i++);
    str[i] = '\0';
    if (str[i - 1] == '\'')
        str[i - 1] = '\0';
    tmp = my_strdup(str);
    return tmp;
}

void cpy_to_cmd_tab(char **new, char **str, int *j)
{
    for (int a = 0; str[a]; a++, *j += 1)
        new[*j] = str[a];
    *j -= 1;
}

void rm_alias(st_t *st)
{
    char *tmp = strcpy_end("rm ", st->alias_rc);
    char **cmd = my_str_to_word_array_char(tmp, ' ');
    char *arg = find_path(cmd[0], st->senv, st);
    pid_t c_pid;
    int status;

    c_pid = fork();
    if (c_pid == 0)
        execve(arg, cmd, st->senv);
    wait3(&status, 0, NULL);
    free_array(cmd);
    free(arg);
    free(tmp);
}

void remplace_cmd_tool(st_t *st, char **arg, char **alias, int r)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
    int output = open(st->alias_rc, O_RDWR | O_TRUNC | O_CREAT, mode);

    for (int i = 0; alias[i]; i++) {
        my_putstr_to(alias[i], output);
        if (alias[i + 1])
            my_putchar_to('\n', output);
    }
    close(output);
}