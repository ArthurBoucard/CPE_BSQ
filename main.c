/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int verif_map(char *file)
{
    int fd = open(file, O_RDONLY);
    char buff[1];
    int j = 0;
    int test = 0;

    if (fd == -1)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (verif_map(av[1]) == 84)
        return (84);
    prep_map(av[1]);
    return (0);
}
