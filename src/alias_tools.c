/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias_tools
*/

#include "my.h"

void remplace_cmd(st_t *st, char **arg, char **alias, int r)
{
    int size = 0;
    int a = 0;
    char *tmp = NULL;
    char *str = NULL;

    for (; arg[size]; size++);
    size -= 2;
    for (int i = 2; arg[i]; i++)
        size += my_strlen(arg[i]);
    tmp = my_calloc(sizeof(char), size);
    for (int i = 2; arg[i]; i++) {
        for (int j = 0; arg[i][j]; j++, a++)
            tmp[a] =  arg[i][j];
        tmp[a++] = ' ';
    }
    tmp[--a] = 0;
    str = strcpy_end("alias ", arg[1]);
    alias[r] = strcpy_end(str, strcpy_end(strcpy_end("=\'", tmp), "\'"));
    free(tmp);
    remplace_cmd_tool(st, arg, alias, r);
}

int find_alias_bis(st_t *st, char **arg, char **alias, int i)
{
    if (cmp_alias(arg[1], &alias[i][6])) {
        remplace_cmd(st, arg, alias, i);
        return 1;
    }
    return 0;
}

int check_alias(st_t *st, char **arg)
{
    char **alias = my_str_to_word_array_char(read_file(st->alias_rc), '\n');
    int r = 0;

    for (int i = 0; alias[i]; i++) {
        if (cmp_alias("alias", alias[i]))
            r = find_alias_bis(st, arg, alias, i);
        if (r)
            break;
    }

    return r;
}

int cmp_alias(char *str1, char *str2)
{
    if (!str2)
        return 0;
    for (int i = 0; str1[i]; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

void cpy_to_cmd(char *new, char *str, int *z)
{
    for (int j = 0; str[j]; j++, *z += 1)
        new[*z] = str[j];
    *z -= 1;
}