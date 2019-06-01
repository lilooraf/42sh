/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
#define __MY_H__

#include <stddef.h>
#include <stdbool.h>
#include "struct.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <glob.h>

void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_str_isalpha(char const *str);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_str_isprintable(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_putchar_to(char c, int output);
int my_putstr(char const *);
int my_putstr_to(char const *, int output);
int my_putstrn(char const *);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putnbr_base(int nb, char const *base);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char const *src);
void *my_calloc(size_t elem_size, size_t elems);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_char(char *str, char c);
char *my_clear_str(char *str);
int check_num(char **av);
int usage(int ac, char **av);
void exec(st_t *st, char **arg);
void free_all(st_t *st);
int check_nbr(char *av);
char *strcpy_end(char *dest, char *src);
char **save_env(char **env, int size);
void env_minishell(char **arg, char **env);
int cd_minishell(char ***senv, char **arg);
int find_line(char **senv, char *arg);
void create_env(char ***senv, char **arg);
int set_valor(char ***senv, char **arg);
int my_setenv(char ***senv, char **arg);
void minishell(char **env, st_t st);
int my_unsetenv(char ***senv, char **arg);
void free_array(char **arg);
int arg_nb(char **arg);
void my_pipe(st_t *st, char **arg);
int check_builtins(char **arg);
void my_exit(st_t *st, char **arg);
int check_pipe(st_t *st);
char *find_path(char *arg, char **env, st_t *st);
void exec_fct(st_t *st, char **arg);
int check_error(char **arg);
int exec_my_ftc(st_t *st, char **arg);
char *separe(char *);
int check_redirect(char **arg);
void my_redirect(st_t *st, char **arg);
void my_putchar_error(char c);
int my_putstr_error(char const *str);
int my_putstrn_error(char const *str);
void redirect_r_tool(char ***targ, st_t *st, pid_t cpid, int *inf);
void redirect_r(char ***targ, st_t *st, pid_t cpid, int *inf);
void print_prompt(void);
void exec_separator(st_t *st, char **arg, int size);
bool separators(st_t *st, char **arg);
int alias(st_t *st, char ***arg);
void parse_change(st_t *st);
void rm_alias(st_t *st);
void set_alias(st_t *st, char **arg);
int check_alias(st_t *st, char **arg);
int cmp_alias(char *str1, char *str2);
char *read_file(char *fp);
void change_cmd(st_t *st, char ***arg, int i, char *alias);
void remplace_cmd_tool(st_t *st, char **arg, char **alias, int r);
void cpy_to_cmd_tab(char **new, char **str, int *j);
char *get_alias(char *str);
int find_alias_bis(st_t *st, char **arg, char **alias, int i);
char *find_cmd_bis(char *str);
void cpy_to_cmd(char *new, char *str, int *z);
char *find_cmd(char *str);
void return_pipe(char ***targ, st_t *st, int status);
void disp_error(char *str, int i);
char *find_path_tool_bis(char *arg, char **env);
char *find_path_tool(char **arr, char *arg);
void print_sig(pid_t pid, int status, st_t *st);
char **globing(st_t *st, char **arg);

#endif
