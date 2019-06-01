/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_exec
*/

#include "my.h"

int builtins(st_t *st, char **arg)
{
    if (check_builtins(arg)) {
        my_exit(st, arg);
        env_minishell(st->senv, arg);
        st->i += my_setenv(&st->senv, arg);
        st->i += my_unsetenv(&st->senv, arg);
        st->i += cd_minishell(&st->senv, arg);
        set_alias(st, arg);
        return 1;
    }
    return 0;
}

void print_sig(pid_t pid, int status, st_t *st)
{
    wait3(&status, 0, NULL);
    if (WIFSIGNALED(status)) {
        my_putstr_error(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_putstrn_error(" (core dumped)");
        my_putchar('\n');
    }
    if (WEXITSTATUS(status))
        st->i = WEXITSTATUS(status);
}

void exec_fct(st_t *st, char **arg)
{
    char *argument = NULL;
    pid_t c_pid;
    int status;

    if (builtins(st, arg) || alias(st, &arg))
        return;
    arg = globing(st, arg);
    argument = find_path(arg[0], st->senv, st);
    if (!argument) {
        st->i += 1;
        return;
    }
    c_pid = fork();
    if (c_pid == 0)
        execve(argument, arg, st->senv);
    print_sig(c_pid, status, st);
    free(argument);
}

char ***init_tab(char ***targ, char **arg, int size)
{
    int s = 1;
    int a = 0;
    int b = 0;

    targ = my_calloc(sizeof(char **), size);
    for (int i = 0; arg[i]; i++)
        s++;
    for (int i = 0; i < size - 1; i++)
        targ[i] = my_calloc(sizeof(char *), s);
    for (int j = 0; arg[j]; j++) {
        if (my_strcmp(arg[j], ";")) {
            targ[a][b] = my_strdup(arg[j]);
            b++;
        } else {
            a++;
            b = 0;
        }
    }
    return targ;
}

void exec(st_t *st, char **arg)
{
    int size = 2;
    char ***targ = NULL;

    if (separators(st, arg))
        return;
    for (int j = 0; arg[j]; j++)
        if (!my_strcmp(arg[j], ";"))
            size++;
    if (size == 2 && !check_pipe(st)) {
        free(targ);
        return (my_redirect(st, arg));
    }
    targ = init_tab(targ, arg, size);
    for (int i = 0; targ[i]; i++) {
        my_redirect(st, targ[i]);
        free_array(targ[i]);
    }
    free(targ);
}
