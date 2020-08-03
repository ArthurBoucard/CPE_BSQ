/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "my.h"

char *fill_str(char *str, char fill)
{
    for (int i = 0; i < my_strlen(str); i++)
        str[i] = fill;
    return (str);
}
