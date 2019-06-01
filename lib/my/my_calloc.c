/*
** EPITECH PROJECT, 2019
** my_calloc
** File description:
** my_calloc.c
*/

#include <stddef.h>
#include <stdlib.h>

void *my_calloc(size_t elem_size, size_t elems)
{
    size_t alloc_size = elem_size * elems;
    void *block = malloc(alloc_size);
    unsigned char *ptr = block;

    for (; alloc_size; alloc_size--)
        *ptr++ = (unsigned char)(0);
    return (block);
}
