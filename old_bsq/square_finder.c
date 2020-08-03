/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** square_finder
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

#include <stdio.h>

void return_square(char **map, int nb, int i, int j)
{
    char verif = map[i][j];
    int len = (map[i][j] - 35);
    int wid = (map[i][j] - 35);
    int mem = wid;

    for (; len >= 0; len--) {
        wid = mem;
        for (; wid >= 0; wid--) {
            map[i][j] = 'x';
            j--;
        }
        printf("%s\n", map[i]);
        i--;
    }
}

void find_square(int **square, int nb, int max, char **map)
{
    int j = 1;
    int i = 2;
    int mem;

    for (; i < nb; j++) {
        if (square[i][j] == -1) {
            i++;
            j = 1;
        }
        if (square[i][j] == max)
            break;
    }
    mem = j;
    for (int k = 0; k < max; k++) {
        square[i][j] = -2;
        for (int cpy = max; cpy > 0; cpy--, j--)
            square[i][j] = -2;
        i--;
        j = mem;
    }

    int m = 1;
    for (int l = 2; l < nb; m++) {
        if (square[l][m] == -1) {
            l++;
            m = 0;
        }
    }
}

void write_square(int **square, int nb, char **map)
{
    int j = 1;
    int max = square[1][0];

    for (int i = 2; i < nb; j++) {
        if (square[i][j] == -1) {
            i++;
            j = 1;
        }
        if (max < square[i][j])
            max = square[i][j];     
    }
    find_square(square, nb, max, map);
}

void make_square(int **square, int nb, char **map)
{
    int j = 1;
    int min;

    for (int i = 2; i < nb; j++) {
        if (square[i][j] == -1) {
            i++;
            j = 1;
        }
        if (square[i][j] >= 1 && square[i - 1][j] >= 1 && square[i - 1][j - 1] >= 1
        && square[i][j - 1] >= 1) {
            min = square[i - 1][j];
            if (min > square[i - 1][j - 1])
                min = square[i - 1][j - 1];
            if (min > square[i][j - 1])
                min = square[i][j - 1];
            square[i][j] = (min + 1);
        }
    }
    write_square(square, nb, map);
}

void read_square(char **map, int nb, int **square)
{
    int j = 0;

    for (int i = 0; i < nb; j++) {
        if (map[i][j] == '\n') {
            square[i][j] = -1;
            i++;
            j = 0;
        }
        if (map[i][j] == 'o')
            square[i][j] = 0;
        if (map[i][j] == '.')
            square[i][j] = 1;
    }
    make_square(square, nb, map);
}