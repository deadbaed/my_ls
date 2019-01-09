/*
** EPITECH PROJECT, 2018
** library
** File description:
** try not to segfault, good luck :)
*/

#ifndef LIBRARY_H
#define LIBRARY_H

void put_char(const char c);
int len_str(const char *str);
void put_str(const char *str);
void put_str_n(const char *str);
void put_str_err(const char *str);
void put_nbr(int nb);
int str_compare(const char *s1, const char *s2);
int putput(char *str, ...);
char **str_to_word_array(const char *str, const char sep);

#endif
