/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void *my_calloc(size_t elem_size, size_t elems);

char *read_file(char *fp)
{
    int fd;
    int tr;
    char *buff = NULL;
    struct stat st;

    fd = open(fp, O_RDONLY);
    if (fd == -1)
        return (NULL);
    stat(fp, &st);
    buff = my_calloc(sizeof(char), (st.st_size + 2));
    tr = read(fd, buff, st.st_size + 1);
    close(fd);
    return (buff);
}
