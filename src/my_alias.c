/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_alias
*/

#include "my.h"

void disp_alias_bis(st_t *st, char **arg, char **alias, int i)
{
    if (cmp_alias(arg[1], get_alias(alias[i]))) {
        my_putstrn(find_cmd(alias[i]));
    }
}

void disp_alias(st_t *st, char **arg)
{
    char **alias = my_str_to_word_array_char(read_file(st->alias_rc), '\n');

    for (int i = 0; alias[i]; i++) {
        if (cmp_alias("alias", alias[i]))
            disp_alias_bis(st, arg, alias, i);
    }
}

void append_in_file(char *file, char *arg, char *tmp)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
    int output = open(file, O_RDWR | O_APPEND | O_CREAT, mode);

    my_putstr_to("alias ", output);
    my_putstr_to(arg, output);
    my_putstr_to("=\'", output);
    my_putstr_to(tmp, output);
    my_putstr_to("\'\n", output);
    close(output);
}

void set_alias_cmd(st_t *st, char **arg)
{
    int size = 0;
    int a = 0;
    char *tmp = NULL;

    if (check_alias(st, arg))
        return;
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
    append_in_file(st->alias_rc, arg[1], tmp);
    free(tmp);
}

void set_alias(st_t *st, char **arg)
{
    if (!my_strcmp(arg[0], "alias")) {
        if (arg_nb(arg) == 1)
            my_putstr(read_file(st->alias_rc));
        if (arg_nb(arg) == 2)
            disp_alias(st, arg);
        if (arg_nb(arg) >= 3)
            set_alias_cmd(st, arg);
    }
    return;
}