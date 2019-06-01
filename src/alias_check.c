/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** alias_check
*/

#include "my.h"

char *find_cmd(char *str)
{
    char *tmp = NULL;
    int i = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == '=')
            break;
    str = my_strdup(&str[i + 2]);
    str[my_strlen(str) - 1] = '\0';
    tmp = my_strdup(str);
    return tmp;
}

void change_cmd(st_t *st, char ***arg, int i, char *alias)
{
    int j = 0;
    int size_arg = 0;
    int size_alias = 0;
    char **alias_tab = my_str_to_word_array_char(alias, ' ');
    char **new_cmd = NULL;

    for (size_arg = 0; (*arg)[size_arg]; size_arg++);
    for (size_alias = 0; alias_tab[size_alias]; size_alias++);
    new_cmd = my_calloc(sizeof(char *), (size_arg + size_alias + 1));
    for (int z = 0; (*arg)[z]; z++, j++) {
        if (z == i)
            cpy_to_cmd_tab(new_cmd, alias_tab, &j);
        else
            new_cmd[j] = (*arg)[z];
    }
    (*arg) = new_cmd;
}

int alias_loop(st_t *st, char ***arg, char **alias, int i)
{
    for (int j = 0; alias[j]; j++)
        if (i != j && (cmp_alias(get_alias(alias[i]), find_cmd_bis(alias[j]))
            && cmp_alias(get_alias(alias[j]), find_cmd_bis(alias[i]))) &&
            ((!my_strcmp(*arg[0], get_alias(alias[i]))) ||
            !my_strcmp(*arg[0], get_alias(alias[j])))) {
            my_putstrn("Alias loop.");
            return 1;
        }
    return 0;
}

void find_alias(st_t *st, char ***arg, char *alias)
{
    alias += 6;
    for (int i = 0; (*arg)[i]; i++)
        if (cmp_alias((*arg)[i], alias)) {
            change_cmd(st, arg, i, find_cmd(alias));
    }
}

int alias(st_t *st, char ***arg)
{
    char **alias = my_str_to_word_array_char(read_file(st->alias_rc), '\n');

    for (int i = 0; alias[i]; i++)
        if (alias_loop(st, arg, alias, i))
            return 1;
    for (int i = 0; alias[i]; i++) {
        if (cmp_alias("alias", alias[i]))
            find_alias(st, arg, alias[i]);
    }
    free_array(alias);
    return 0;
}