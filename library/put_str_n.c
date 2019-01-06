/*
** EPITECH PROJECT, 2018
** put_str_n
** File description:
** writes a string with a \n on stdout
*/

#include <unistd.h> /* for write */
#include "library.h" /* for len_str */

void put_str_n(const char *str)
{
    write(1, str, len_str(str) - 1);
    write(1, "\n", 1);
}
