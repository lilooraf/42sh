/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/
#include "my.h"

int main(int ac, char **av, char **env)
{
    st_t st;

    st.i = 0;
    if (ac == 1)
        minishell(env, st);
    return 84;
}
