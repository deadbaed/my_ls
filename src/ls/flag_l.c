/*
** EPITECH PROJECT, 2018
** src/ls/flag_l
** File description:
** try not to segfault, good luck :)
*/

#include "my_ls.h"

void format_time(char *str)
{
    for (int i = 4; i != 16; i++)
        put_char(str[i]);
    put_char(' ');
}

int ls_flag_l(struct stat st)
{
    struct passwd *pwd = getpwuid(st.st_uid);
    struct group *grp = getgrgid(st.st_gid);

    if (!pwd || !grp)
        return EXIT_ERROR;
    put_char((S_ISDIR(st.st_mode)) ? 'd' :
            (S_ISBLK(st.st_mode) ? 'b' : (S_ISCHR(st.st_mode) ? 'c' : '-')));
    put_char((st.st_mode & S_IRUSR) ? 'r' : '-');
    put_char((st.st_mode & S_IWUSR) ? 'w' : '-');
    put_char((st.st_mode & S_IXUSR) ? 'x' : '-');
    put_char((st.st_mode & S_IRGRP) ? 'r' : '-');
    put_char((st.st_mode & S_IWGRP) ? 'w' : '-');
    put_char((st.st_mode & S_IXGRP) ? 'x' : '-');
    put_char((st.st_mode & S_IROTH) ? 'r' : '-');
    put_char((st.st_mode & S_IWOTH) ? 'w' : '-');
    put_char((st.st_mode & S_IXOTH) ? 'x' : '-');
    putput(" %i %s %s %i ", st.st_nlink, pwd->pw_name, grp->gr_name,
            st.st_size);
    format_time(ctime(&st.st_mtime));
    return EXIT_OKAY;
}
