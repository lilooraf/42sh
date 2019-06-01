/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** minishell
*/

#include "my.h"

void my_exit(st_t *st, char **arg)
{
    int i = 0;

    if (my_strcmp(arg[0], "exit"))
        return;
    if (arg_nb(arg) <= 2) {
        if (check_nbr(arg[1])) {
            write(2, "exit: Expression Syntax.\n", 25);
            st->i += 1;
            return;
        }
        if (isatty(0))
            my_putstr("exit\n");
        i = my_getnbr(arg[1]);
        free_array(arg);
        free_all(st);
        exit(i);
    }
    write(2, "exit: Expression Syntax.\n", 25);
    st->i += 1;
}

void exit_d(st_t *st)
{
    if (isatty(0))
        my_putstrn("exit");
    free_all(st);
    exit(st->i);
}

void parser(st_t *st)
{
    st->i = 0;
    st->file = separe(st->file);
    parse_change(st);
    st->clear = my_clear_str(st->file);
    st->arg = my_str_to_word_array_char(st->clear, ' ');
}

void run_minishell(st_t st)
{
    while (42) {
        if (isatty(0))
            print_prompt();
        if (getline(&st.file, &st.len, stdin) == -1) {
            exit_d(&st);
        }
        parser(&st);
        exec(&st, st.arg);
        free_array(st.arg);
        free(st.file);
        st.file = NULL;
        st.arg = NULL;
    }
}

void minishell(char **env, st_t st)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
    int tmp = find_line(env, "HOME");
    int tmp1 = find_line(env, "PWD");

    st.file = NULL;
    st.senv = save_env(env, 0);
    if (tmp != -1)
        st.home = my_strdup(st.senv[tmp] + 5);
    else
        st.home = my_strdup("/home/");
    if (tmp1 != -1)
        st.alias_rc = strcpy_end(my_strdup(st.senv[find_line
        (st.senv, "PWD")] + 4), "/.42rc");
    else
        st.alias_rc = strcpy_end(getcwd(NULL, 0), "/.42rc");
    st.clear = NULL;
    st.arg = NULL;
    st.len = 1;
    close(open(st.alias_rc, O_RDWR | O_APPEND | O_CREAT, mode));
    run_minishell(st);
}
