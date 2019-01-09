/*
** EPITECH PROJECT, 2018
** putput
** File description:
** put_str on steroids
*/

#include <stdarg.h>
#include "library.h" /* for put_char, put_str, put_nbr */

int putput(char *str, ...)
{
    va_list list;

    va_start(list, str);
    for (int i = 0; str[i]; i++) {
        (str[i] != '%') ? put_char(str[i]) : 0;
        if (str[i] == '%') {
            (str[i + 1] == 'i') ? put_nbr(va_arg(list, int)) : 0;
            (str[i + 1] == 'c') ? put_char(va_arg(list, int)) : 0;
            (str[i + 1] == 's') ? put_str(va_arg(list, char *)) : 0;
            (str[i + 1] == '%') ? put_char('%') : 0;
            i++;
        }
    }
    va_end(list);
    return 0;
}
