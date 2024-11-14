/*
** EPITECH PROJECT, 2022
** CPoolDay04
** File description:
** Task06
*/

void my_sort_int_array(int *array, int size)
{
    int result[size];
    int max_index = 0;

    for (int i = 0; i < size; i++) {
        max_index = 0;
        for (int j = 0; j < size; j++)
            max_index += array[i] > array[j] ? 1 : 0;
        while (array[i] != 0 && array[i] == result[max_index])
            max_index++;
        result[max_index] = array[i];
    }
    for (int i = 0; i < size; i++)
        array[i] = result[i];
    return;
}
