/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** prepare_map
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *map_malloc(char *av, int len)
{
    char *map = malloc(sizeof(char) * len);
    int fd = open(av, O_RDONLY);

    read(fd, map, len);
    close(fd);
    return (map);
}

int *map_nb_malloc(char *map, int len)
{
    int *map_nb = malloc(sizeof(int) * len);
    int i = 0;

    while (map[i] != '\n')
        i++;
    i++;
    for (; map[i] != '\0'; i++) {
        if (map[i] == '.')
            map_nb[i] = 1;
        else if (map[i] == 'o')
            map_nb[i] = 0;
        else if (map[i] == '\n')
            map_nb[i] = -1;
    }
    map_nb[i] = -2;
    return (map_nb);
}

int line_map(char *av)
{
    int fd = open(av, O_RDONLY);
    char buff[1];
    int len_line = 0;
    int test = 0;

    for (int by = read(fd, buff, 1); by != 0; by = read(fd, buff, 1)) {
        for (; test == 0 ; by = read(fd, buff, 1)) {
            if (buff[0] == '\n')
                test = 1;
        }
        if (buff[0] == '\n')
            break;
        len_line++;
    }
    close(fd);
    return (len_line);
}

int column_map(char *av)
{
    int fd = open(av, O_RDONLY);
    char buff[1];
    char *nb = malloc(sizeof(char) * 5);
    int i = 0;
    int nbb;

    for (int by = read(fd, buff, 1); by != 0; by = read(fd, buff, 1)) {
        if (buff[0] >= 48 && buff[0] <= 57) {
            nb[i] = buff[0];
            i++;
        }else
            break;
    }
    close(fd);
    nbb = my_getnbr(nb);
    free(nb);
    return (nbb);
}

int prep_map(char *file)
{
    char *map;
    int *map_nb;
    int col = column_map(file);
    int len = line_map(file);

    map = map_malloc(file, col * len + col + 5);
    map_nb = map_nb_malloc(map, col * len + col + 5);
    calc_square(map, map_nb, len, col);
    return (0);
}