/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** redirect
*/

#include "my.h"

void redirect_l(char ***targ, st_t *st, pid_t cpid, int *inf)
{
    int status = 0;

    if (inf[0] < 0) {
        perror("open");
        st->i += 1;
        return;
    }
    if (inf[1] == 1) {
        cpid = fork();
        if (cpid == 0) {
            dup2(inf[0], 0);
            exec(st, targ[inf[2] - 1]);
            exit(st->i);
        }
        close(inf[0]);
        print_sig(cpid, status, st);
        return;
    }
}

void redirect_r(char ***targ, st_t *st, pid_t cpid, int *inf)
{
    int status = 0;

    if (inf[0] < 0) {
        perror("open");
        st->i += 1;
        return;
    }
    cpid = fork();
    if (cpid == 0) {
        close(0);
        dup2(inf[0], 1);
        exec(st, targ[inf[2] - 1]);
        exit(st->i);
    }
    close(inf[0]);
    print_sig(cpid, status, st);
}

void redirect_exec(char ***targ, st_t *st, pid_t cpid, int *inf)
{
    for (int i = 0; targ[i]; i++) {
        if (!my_strcmp(targ[i][0], "<<")) {
            inf[0] = i + 1;
            inf[1] = 2;
            inf[2] = i;
            return;
        }
        if (!my_strcmp(targ[i][0], "<")) {
            inf[0] = open(targ[i + 1][0], O_RDONLY);
            inf[1] = 1;
            inf[2] = i;
        }
    }
    if (inf[1]) {
        redirect_l(targ, st, cpid, inf);
        return;
    }
    redirect_r_tool(targ, st, cpid, inf);
}

char ***init_tab_redirect(char ***targ, char **arg, int size)
{
    int s = 1;

    targ = my_calloc(sizeof(char **), size);
    for (int i = 0; arg[i]; i++, s++);
    for (int i = 0; i < size - 1; i++)
        targ[i] = my_calloc(sizeof(char *), s);
    for (int j = 0, a = 0, b = 0; arg[j]; j++) {
        if (my_strcmp(arg[j], "<") && my_strcmp(arg[j], ">") &&
        my_strcmp(arg[j], "<<") && my_strcmp(arg[j], ">>")) {
            targ[a][b] = my_strdup(arg[j]);
            b++;
        }
        else {
            a++;
            b = 0;
            targ[a][b] = my_strdup(arg[j]);
            a++;
        }
    }
    return targ;
}

void my_redirect(st_t *st, char **arg)
{
    int inf[] = {0, 0, 0};
    pid_t cpid;
    int size = 2;
    char ***targ = NULL;

    for (int j = 0; arg[j]; j++)
        if (!my_strcmp(arg[j], "<") || !my_strcmp(arg[j], ">") ||
        !my_strcmp(arg[j], "<<") || !my_strcmp(arg[j], ">>"))
            size += 2;
    if (size == 2) {
        free(targ);
        return (my_pipe(st, arg));
    }
    targ = init_tab_redirect(targ, arg, size);
    redirect_exec(targ, st, cpid, inf);
    for (int i = 0; targ[i]; i++)
        free_array(targ[i]);
    free(targ);
}