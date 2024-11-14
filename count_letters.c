/*
** EPITECH PROJECT, 2022
** Step1 Rush02 count_letter_occ
** File description:
** This part will count the number of occurences of a letter in a string
*/

#include "my.h"
#include "my_macro_abs.h"
#include "count_letters.h"
#include <stdlib.h>

void sort_offsets(offset_t *array);
void my_put_errstr(char const *str);

const int lang_rates[4][26] = {
    {82, 15, 28, 43, 127, 22, 20, 61, 70, 2, 8, 40,
    24,
    67, 75, 19, 1, 60, 63, 91, 28, 10, 24, 1, 20, 1},
    {76, 9, 33, 37, 147, 11, 9, 7, 75, 6, 1, 55, 30,
    71, 58, 26, 14, 67, 79, 72, 63, 18, 0, 4, 1, 3},
    {65, 19, 27, 51, 164, 17, 30, 46, 65, 3, 14, 34,
    25, 98, 26, 7, 0, 70, 73, 62, 42, 8, 19, 0, 0, 11},
    {115, 22, 40, 50, 122, 7, 18, 7, 62, 5, 0, 50, 32,
    67, 87, 25, 9, 69, 80, 46, 29, 11, 0, 2, 10, 5}
};

void print_result(int count, char letter, int length)
{
    int decimals = ((count * 10000) / length) % 100;
;
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(count);
    my_putstr(" (");
    my_put_nbr((count * 100) / length);
    my_putchar('.');
    if (decimals < 10)
        my_putchar('0');
    my_put_nbr(decimals);
    my_putstr("%)\n");
    return;
}

static int print_letter_count(char *str, char letter, int done)
{
    int count = 0;
    int length = 0;

    for (int i = 0; str[i]; i++)
        if (('A' <= str[i] && str[i] <= 'Z')
            || ('a' <= str[i] && str[i] <= 'z'))
            length++;
    for (int i = 0; str[i]; i++)
        if (('A' <= letter && letter <= 'Z'
            ? letter + 32
            : letter) == str[i])
            count++;
    if (!done)
        print_result(count, letter, length);
    return count * 1000 / length;
}

static int error(char const *error)
{
    my_put_errstr(error);
    return 84;
}

static int compute_offsets(int *rates)
{
    offset_t offsets[4] = {
        {.lang = english, .average_offset = 0},
        {.lang = french, .average_offset = 0},
        {.lang = german, .average_offset = 0},
        {.lang = spanish, .average_offset = 0}
    };

    for (lang_t lang = english; lang <= spanish; lang++) {
        for (int i = 0; i < 26; i++)
            offsets[lang].average_offset += ABS((rates[i] == -1
                ? lang_rates[lang][i]
                : rates[i]) - lang_rates[lang][i]);
    }
    sort_offsets(offsets);
    return 0;
}

int rush2_main(int argc, char *argv[])
{
    char *str = my_strlowcase(argv[1] ? argv[1] : "");
    char chars[(argc < 3 ? 3 : argc) - 2];
    int rates[27] = {-1};
    int i = 0;

    if (argc < 3)
        return error("Missing arguments.\n");
    if (str[0] == '\0')
        return error("Input is null.\n");
    for (i = 2; argv[i] != NULL; i++) {
        if (!(('a' <= argv[i][0] && argv[i][0] <= 'z')
            || ('A' <= argv[i][0] && argv[i][0] <= 'Z')) || argv[i][1] != '\0')
            return error("Invalid character argument.\n");
        chars[i - 2] = argv[i][0];
    }
    for (i = 0; i < argc - 2; i++)
        print_letter_count(str, chars[i], 0);
    for (i = 0; i < 26; i++)
        rates[i] = print_letter_count(str, i + 'a', 1);
    return compute_offsets(rates);
}
