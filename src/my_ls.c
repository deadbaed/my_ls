/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int my_ls(char *path)
{
    struct stat st;

    if (stat(path, &st) != 0) {
        put_str_err(path);
        put_str_err(": no such file or directory\n");
        return EXIT_ERROR;
    }
    if (S_ISDIR(st.st_mode) != 0)
        directory(path);
    return EXIT_OKAY;
}

int main(int ac, char **av)
{
    int err_check = 0;

    (ac == 1) ? directory(".") : 0;
    while (*++av)
        (my_ls(*av)) ? err_check = EXIT_ERROR : 0;
    if (err_check == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_OKAY;
}
