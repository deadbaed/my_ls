/*
** EPITECH PROJECT, 2018
** put_char
** File description:
** prints a char
*/

#include <unistd.h> /* for write */

void put_char(char c)
{
    write(1, &c, 1);
}
