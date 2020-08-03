/*
** EPITECH PROJECT, 2019
** ta mere
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **map_malloc(char **map, char *buff, int nb)
{
    static int test = 0;
    static int len = 1;

    if (buff[0] != '\n' && test != 2)
        len++;
    else if (test == 2)
        return (map);
    else
        test = 1;
    if (test == 1) {
        map = malloc(sizeof(char *) * (nb + 1));
        for (int j = 0; j <= (nb + 1); j++)
            map[j] = malloc(sizeof(char) * (len * 2));
        test = 2;
    }
    return (map);
}

char **map_copy(char **map, char *file, int nb)
{
    int fd = open(file, O_RDONLY);
    char buff[1];
    int by;
    int k = 0;
    int l = 0;

    for (int k = 0; k < (nb + 1); by = read(fd, buff, 1)) {
        if (buff[0] == '\n') {
            map[k][l] = buff[0];
            k++;
            l = 0;
            by = read(fd, buff, 1);
        }
        map[k][l] = buff[0];
        l++;
    }
    return (map);
}

int read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char buff[1];
    char **map;
    char *nb = malloc(sizeof(char) * 10);
    int i = 0;
    int **square;

    if (fd == -1) {
        write(2, "Error with open\n", 16);
        return (84);
    }
    for (int by = read(fd, buff, 1); by != 0; by = read(fd, buff, 1)) {
        if (buff[0] != '.' && buff[0] != 'o') {
            if (buff[0] >= 48 && buff[0] <= 57)
                nb[i] = buff[0];
            i++;
        } else if (buff[0] == '\n' || buff[0] != '\n') {
            by = read(fd, buff, 1);
            map = map_malloc(map, buff, my_getnbr(nb));
            square = int_malloc(map, buff, my_getnbr(nb), square);
        }
    }
    map = map_copy(map, file, my_getnbr(nb));
    read_square(map, (my_getnbr(nb) + 1), square);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    read_file(av[1]);
    return (0);
}
