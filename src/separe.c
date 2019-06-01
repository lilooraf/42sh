/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** separe
*/

#include "my.h"

char *separe_tool(char *str, char *tmp, int j)
{
    for (int i = 0; str[i]; i++, j++) {
        if ((str[i] == '<' && str[i + 1] == '<') || (str[i] == '>' &&
        str[i + 1] == '>') || (str[i] == '|' && str[i + 1] == '|') ||
        (str[i] == '&' && str[i + 1] == '&')) {
            tmp[j] = ' ';
            tmp[++j] = str[i];
            tmp[++j] = str[i + 1];
            tmp[++j] = ' ';
            i++;
        } else if (str[i] == ';' || str[i] == '|' || ((str[i] == '<' &&
        str[i + 1] != '<') || (str[i] == '>' && str[i + 1] != '>'))) {
            tmp[j] = ' ';
            tmp[++j] = str[i];
            tmp[++j] = ' ';
        }
        else
            tmp[j] = str[i];
    }
    return tmp;
}

char *separe(char *str)
{
    int j = 0;
    char *tmp = NULL;
    int size = my_strlen(str);

    for (int i = 0; str[i]; i++)
        if (str[i] == ';' || (str[i] == '|' && str[i + 1] != '|')
        || (str[i] == '|' && str[i + 1] == '|')
        || (str[i] == '>' && str[i + 1] == '>')
        || (str[i] == '<' && str[i + 1] == '<')
        || (str[i] == '>' && str[i + 1] != '>')
        || (str[i] == '<' && str[i + 1] != '<')
        || (str[i] == '&' && str[i + 1] == '&'))
            size += 2;
    tmp = my_calloc(sizeof(char), size + 1);
    tmp = separe_tool(str, tmp, j);
    return (tmp);
}

bool separators(st_t *st, char **arg)
{
    for (int size = 0; arg[size]; size++)
        if (!my_strcmp(arg[size], "&&") || !my_strcmp(arg[size], "||")) {
            exec_separator(st, arg, size);
            return true;
        }
    return false;
}

void change_tilde(st_t *st, char *cmd, char *str, int i)
{
    int z = 0;
    int size_cmd = my_strlen(st->file);
    int size = my_strlen(str);
    char *tmp = my_calloc(sizeof(char), size_cmd + size);

    for (int a = 0; st->file[a]; a++, z++) {
        if (a == i)
            cpy_to_cmd(tmp, str, &z);
        else
            tmp[z] = st->file[a];
    }
    free(st->file);
    st->file = tmp;
}

void parse_change(st_t *st)
{
    for (int i = 0; st->file[i]; i++)
        if (st->file[i] == '~')
            change_tilde(st, st->file, st->home, i);
}