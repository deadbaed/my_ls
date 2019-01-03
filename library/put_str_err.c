/*
** EPITECH PROJECT, 2018
** put_str_err
** File description:
** writes a string on stderr
*/

#include <unistd.h> /* for write */
#include "library.h" /* for len_str */

void put_str_err(const char *str)
{
    write(2, str, len_str(str) - 1);
}
