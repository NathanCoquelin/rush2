/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Main file header
*/

#pragma once

typedef enum language {
    english,
    french,
    german,
    spanish
} lang_t;

typedef struct language_data {
    lang_t lang;
    int average_offset;
} offset_t;
