/*
** EPITECH PROJECT, 2018
** put_str
** File description:
** writes a string on stdout
*/

#include <unistd.h> /* for write */
#include "library.h" /* for len_str */

void put_str(const char *str)
{
    write(1, str, len_str(str) - 1);
}
