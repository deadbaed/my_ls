/*
** EPITECH PROJECT, 2018
** src/ls/no_flags.c
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

int no_flags_directory(char *path, char *flag)
{
    DIR *fs_dir = opendir(path);
    struct dirent *dir = readdir(fs_dir);
    char *content_name;
    struct stat st;
    char *path_name;

    for (; dir; dir = readdir(fs_dir)) {
        content_name = dir->d_name;
        if (content_name[0] != '.') {
            path_name = str_dup_cat_path(path, content_name);
            if (stat(path_name, &st) == -1)
                return EXIT_ERROR;
            (flag[0] == 'l') ? ls_flag_l(st) : 0;
            put_str_n(content_name);
            free(path_name);
        }
    }
    closedir(fs_dir);
    return EXIT_OKAY;
}

int ls_no_flags(struct stat st, char *path, char *flag)
{
    if (!(S_ISDIR(st.st_mode)))
        put_str_n(path);
    else
        if (no_flags_directory(path, flag) == EXIT_ERROR)
            return EXIT_ERROR;
    return EXIT_OKAY;
}
