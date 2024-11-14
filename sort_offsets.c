/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Rate offset sorting function
*/

#include "my.h"
#include "count_letters.h"

static void print_language(offset_t *result)
{
    switch (result[0].lang) {
    case english:
        my_putstr("=> English\n");
        return;
    case french:
        my_putstr("=> French\n");
        return;
    case german:
        my_putstr("=> German\n");
        return;
    case spanish:
        my_putstr("=> Spanish\n");
        return;
    }
}

void sort_offsets(offset_t *array)
{
    offset_t result[4] = {
        {.lang = english, .average_offset = 0},
        {.lang = french, .average_offset = 0},
        {.lang = german, .average_offset = 0},
        {.lang = spanish, .average_offset = 0}
    };
    int max_index = 0;

    for (int i = 0; i < 4; i++) {
        max_index = 0;
        for (int j = 0; j < 4; j++)
            max_index += array[i].average_offset > array[j].average_offset
                ? 1
                : 0;
        while (array[i].average_offset != 0
            && array[i].average_offset == result[max_index].average_offset)
            max_index++;
        result[max_index] = array[i];
    }
    print_language(result);
}
