/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** Program unit tests
*/

#include <stddef.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int rush2_main(int argc, char **argv);

Test(rush2_main, main)
{
    cr_redirect_stdout();
}

Test(rush2_main, error)
{
    char *args1[2] = {"../test2", NULL};
    char *args2[3] = {"../test2", "blah", NULL};
    char *args3[4] = {"../test2", "", "a", NULL};
    char *args4[4] = {"../test2", "blah", "ab", NULL};
    char *args5[4] = {"../test2", "blah", "3", NULL};
    char *args6[4] = {"../test2", "blah", "%", NULL};

    cr_redirect_stderr();
    cr_assert_eq(rush2_main(1, args1), 84);
    cr_assert_eq(rush2_main(2, args2), 84);
    cr_assert_eq(rush2_main(3, args3), 84);
    cr_assert_eq(rush2_main(3, args4), 84);
    cr_assert_eq(rush2_main(3, args5), 84);
    cr_assert_eq(rush2_main(3, args6), 84);

    cr_assert_stderr_eq_str("Missing arguments.\nMissing arguments.\nInput is null.\nInvalid character argument.\nInvalid character argument.\nInvalid character argument.\n");
}
