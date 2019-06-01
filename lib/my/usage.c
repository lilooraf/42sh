/*
** EPITECH PROJECT, 2019
** usage
** File description:
** usage
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int usage(int ac, char **av)
{
    int fd = open("usage.txt", O_RDONLY);
    int size = 0;
    char *buff = malloc(sizeof(char) * 1);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0) {
        if (fd < 0)
            return (1);
        while (read(fd, buff, 1)) {
            write(1, buff, 1);
        }
        close(fd);
    }
    if (ac != 9)
        return (1);
    return (0);
}
