/*
** EPITECH PROJECT, 2018
** src/ls/no_flags.c
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int ls_no_flags(char *path)
{
    struct stat st;

    if (stat(path, &st)) {
        put_str_err(path);
        put_str_err(": no such file or directory\n");
        return EXIT_ERROR;
    }
    (!(S_ISDIR(st.st_mode))) ? put_str_n(path) : directory(path);
    return EXIT_OKAY;
}
