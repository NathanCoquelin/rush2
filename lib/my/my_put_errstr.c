/*
** EPITECH PROJECT, 2022
** CPoolRush1
** File description:
** Error string printer function
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_put_errstr(char const *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
