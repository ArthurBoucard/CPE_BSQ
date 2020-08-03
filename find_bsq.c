/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** find_bsq
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *modif_map(char *map, int max, int mem_i, int line_len)
{
    for (int mem_max = max, col = 0; col != mem_max; mem_i--, max--) {
        map[mem_i] = 'x';
        if (max == 1) {
            max = mem_max + 1;
            mem_i -= line_len - max + 2;
            col++;
        }
    }
}

int find_max(int *map_nb)
{
    int max = 0;

    for (int i = 0; map_nb[i] != -2; i++) {
        if (max < map_nb[i]) {
            max = map_nb[i];
        }
    }
    return (max);
}

void find_square(char *map, int *map_nb, int line_len, int larg)
{
    int max = find_max(map_nb);
    int mem_i;
    char len_nb[5];
    int j = 0;
    int minus_char = 0;
    char *new_map = malloc(sizeof(char) * (line_len * larg + larg));

    for (;map[j] != '\n'; j++)
        len_nb[j] = map[j];
    for (int nb = my_getnbr(len_nb); nb != 0; nb /= 10)
        minus_char++;
    minus_char++;
    for (mem_i = 0; map_nb[mem_i] != max;)
        mem_i++;
    free(map_nb);
    modif_map(map, max, mem_i, line_len);
    for (int i = 0; map[i] != '\0'; i++)
        new_map[i] = map[i + minus_char];
    free(map);
    write(1, new_map, line_len * larg + larg);
    free(new_map);
}

void calc_square(char *map, int *map_nb, int line_len, int larg)
{
    int min;

    for (int i = line_len + 2; map_nb[i] != -2; i++) {
        if (i == line_len + 1)
            i++;
        if (map_nb[i] >= 1 && map_nb[i - line_len - 1] >= 1
            && map_nb[i - line_len - 2] >= 1 && map_nb[i - 1] >= 1) {
            min = map_nb[i - line_len - 1];
            if (min > map_nb[i - line_len - 2])
                min = map_nb[i - line_len - 2];
            if (min > map_nb[i - 1] && map_nb[i - 1] != 0)
                min = map_nb[i - 1];
            map_nb[i] = min + 1;
        }
    }
    find_square(map, map_nb, line_len, larg);
}