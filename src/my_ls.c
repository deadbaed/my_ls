/*
** EPITECH PROJECT, 2018
** my_ls
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int my_ls(char *path, char *flag)
{
    int ret = 0;
    struct stat st;

    if (path[0] == '-')
        return EXIT_OKAY;
    if (stat(path, &st)) {
        put_str_err("no such file or directory\n");
        return EXIT_ERROR;
    }
    if (S_ISDIR(st.st_mode) && !opendir(path)) {
        put_str_err("permission denied\n");
        return EXIT_ERROR;
    }
    (flag[0] == 'l') ? ret = ls_flag_l(st) : 0;
    ret = ls_no_flags(st, path);
    if (ret == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_OKAY;
}

char *store_flags(int ac, char **av)
{
    char *flag = malloc(sizeof(char) * (5 + 1));

    if (!flag)
        return NULL;
    for (int i = 0; i < 5; i++)
        flag[i] = ' ';
    flag[5] = '\0';
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            for (int j = 1; av[i][j]; j++) {
                (av[i][j] == 'l') ? flag[0] = 'l': 0;
                (av[i][j] == 'R') ? flag[1] = 'R': 0;
                (av[i][j] == 'd') ? flag[2] = 'd': 0;
                (av[i][j] == 'r') ? flag[3] = 'r': 0;
                (av[i][j] == 't') ? flag[4] = 't': 0;
            }
        }
    }
    return flag;
}

int main(int ac, char **av)
{
    int err_check = 0;
    char *flag = store_flags(ac, av);

    (ac == 1) ? no_flags_directory(".") : 0;
    for (int i = 1; i < ac; i++)
        (my_ls(av[i], flag)) ? err_check = EXIT_ERROR : 0;
    free(flag);
    if (err_check == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_OKAY;
}
