/*
** EPITECH PROJECT, 2018
** src/str_to_word_array
** File description:
** try not to segfault, good luck :)
*/

#include <stdlib.h> /* for malloc */

int count_words(const char *str, const char sep)
{
    int number_words = 1;
    int i = 0;

    if (!str)
        return 0;
    for (; str[i]; i++)
        (str[i] == sep) ? number_words++ : 0;
    return number_words;
}

int len_word(const char *str, const char sep)
{
    int i = 0;

    for (; str[0] && str[0] != sep; i++, str++);
    return i;
}

char **str_to_word_array(const char *str, const char sep)
{
    int number_words = count_words(str, sep);
    char **arr = malloc(sizeof(char *) * (number_words + 1));
    int i = 0;
    int j = 0;
    int len = 0;

    if (number_words < 0 || !arr)
        return NULL;
    for (; i < number_words; i++) {
        len = len_word(str, sep);
        if (!(arr[i] = malloc(sizeof(char) * (len + 2))))
            return NULL;
        for (j = 0; j < len; j++, str++)
            arr[i][j] = *str;
        arr[i][j] = '\0';
        str++;
    }
    arr[i] = NULL;
    return arr;
}
