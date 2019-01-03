/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        put_str_err("please give an argument and try again\n");
        return EXIT_ERROR;
    }
    return EXIT_OKAY;
}
