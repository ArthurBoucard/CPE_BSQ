/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** 
*/

#include <unistd.h>

void my_putchar(char c);

int my_swap(int *a, int *b)
{
    int d;

    d = *a;
    *a = *b;
    *b = d;
    return (0);
}
