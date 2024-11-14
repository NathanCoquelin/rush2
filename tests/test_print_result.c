/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Step1-3 unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void print_result(int count, char letter, int length);

Test(print_result, step1_2)
{
    cr_redirect_stdout();

    print_result(1, 'a', 1);
    print_result(36, 'z', 36);
    print_result(42, 'G', 42);
    print_result(5, 'P', 5);
    cr_assert_stdout_eq_str("a:1 (100.00%)\nz:36 (100.00%)\nG:42 (100.00%)\nP:5 (100.00%)\n");
}

Test(print_result, step3)
{
    cr_redirect_stdout();

    print_result(5, 'a', 10);
    print_result(16, 'z', 36);
    print_result(28, 'G', 42);
    print_result(2, 'P', 5);
    cr_assert_stdout_eq_str("a:5 (50.00%)\nz:16 (44.44%)\nG:28 (66.66%)\nP:2 (40.00%)\n");
}
