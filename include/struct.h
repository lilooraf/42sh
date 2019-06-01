/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <stdlib.h>

#ifndef _STRUCT_H_
#define _STRUCT_H_

#define TRST        "\x1B[0m"
#define TBBOLD      "\x1B[1m"
#define TBBLACK     "\x1B[90m"
#define TBRED       "\x1B[91m"
#define TBGREEN     "\x1B[92m"
#define TBYELLOW    "\x1B[93m"
#define TBBLUE      "\x1B[94m"
#define TBMAGENTA   "\x1B[95m"
#define TBCYAN      "\x1B[96m"
#define TBWHITE     "\x1B[97m"
#define COLOR       "--color=auto"

#define TBRD TBRED

typedef struct st
{
    char *alias_rc;
    char *file;
    char *home;
    char **senv;
    char *clear;
    char **arg;
    int i;
    size_t len;
}st_t;

#endif
