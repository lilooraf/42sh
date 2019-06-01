/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** my_pipe
*/

#include "my.h"

int check_pipe(st_t *st)
{
    for (int i = 0; st->arg[i]; i++)
        if (!my_strcmp(st->arg[i], "|"))
            return 1;
    return 0;
}

int check_error_pipe(char **arg, st_t *st)
{
    for (int i = 0; arg[i]; i++)
        if (!my_strcmp(arg[i], "|") && !arg[i + 1]) {
            st->i += 1;
            my_putstrn_error("Invalid null command.");
            return 1;
        }
    return 0;
}

void pipe_exec(char ***targ, st_t *st, int *pipefd, int tmp)
{
    pid_t cpid;

    for (int i = 0; targ[i]; i++) {
        pipe(pipefd);
        cpid = fork();
        if (cpid == 0) {
            close(pipefd[0]);
            dup2(tmp, 0);
            (targ[i + 1] != NULL) ? dup2(pipefd[1], STDOUT_FILENO) : 0;
            exec(st, targ[i]);
            exit(st->i);
        }
        if (cpid > 0 && targ[i + 1] != NULL) {
            close(pipefd[1]);
            tmp = pipefd[0];
        }
    }
    for (int i = 0, status; targ[i]; i++)
        print_sig(cpid, status, st);
    close(tmp);
}

char ***init_tab_pipe(char ***targ, char **arg, int size)
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
        if (my_strcmp(arg[j], "|")) {
            targ[a][b] = my_strdup(arg[j]);
            b++;
        }
        else {
            a++;
            b = 0;
        }
    }
    return targ;
}

void my_pipe(st_t *st, char **arg)
{
    int pipefd[2];
    int size = 2;
    char ***targ = NULL;

    for (int j = 0; arg[j]; j++)
        if (!my_strcmp(arg[j], "|"))
            size++;
    if (size == 2) {
        free(targ);
        return (exec_fct(st, arg));
    }
    if (check_error_pipe(arg, st))
        return;
    targ = init_tab_pipe(targ, arg, size);
    pipe_exec(targ, st, pipefd, 0);
    for (int i = 0; targ[i]; i++)
        free_array(targ[i]);
    free(targ);
}