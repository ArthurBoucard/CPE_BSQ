/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** 
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    char N;
    char P;

    N = 78;
    P = 80;
    if (n >= 0){
        my_putchar(P); 
    } else {
        my_putchar(N);
    }
    return (0);
}
