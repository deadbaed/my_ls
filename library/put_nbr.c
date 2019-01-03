/*
** EPITECH PROJECT, 2018
** put_nbr
** File description:
** display number given as parameter
*/

#include "library.h" /* for put_str, put_char, len_str */

void put_nbr(int nb)
{
    if (nb == -2147483648) {
        put_str("-2147483648");
        return;
    }
    if (nb < 0) {
        nb *= -1;
        put_char('-');
    }
    if (nb / 10 != 0)
        put_nbr(nb / 10);
    put_char((nb % 10) + '0');
}
