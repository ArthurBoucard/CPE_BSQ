/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** 
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i += 1;
    }
    return (0);
}
