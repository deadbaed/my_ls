/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int my_ls(char *path, char flag)
{
    int ret = 0;

    (flag == 0) ? ret = ls_no_flags(path) : 0;
    (flag == 'l') ? ret = ls_flag_l(path) : 0;
    if (ret == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_OKAY;
}

int main(int ac, char **av)
{
    int err_check = 0;
    char flag = 0;

    (ac == 1) ? directory(".") : 0;
    for (int i = 1; i < ac; i++) {
        flag = (av[i][0] == '-') ? av[i][1] : 0;
        (my_ls(av[i], flag)) ? err_check = EXIT_ERROR : 0;
        flag = 0;
    }
    if (err_check == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_OKAY;
}
