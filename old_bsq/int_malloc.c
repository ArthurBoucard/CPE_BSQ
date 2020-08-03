/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** int_malloc
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int **int_malloc(char **map, char *buff, int nb, int **square)
{
    static int test = 0;
    static int len = 1;

    if (buff[0] != '\n' && test != 2)
        len++;
    else if (test == 2)
        return (square);
    else
        test = 1;
    if (test == 1) {
        square = malloc(sizeof(char *) * (nb + 1));
        for (int j = 0; j <= (nb + 1); j++)
            square[j] = malloc(sizeof(char) * (len * 2));
        test = 2;
    }
    return (square);
}