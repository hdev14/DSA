#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void exchange(int *array, int first_idx, int second_idx)
{
    int aux = array[second_idx];
    array[second_idx] = array[first_idx];
    array[first_idx] = aux;
}

void shuffle(int *array, int length)
{
    for (int idx = 0; idx < length; idx++)
    {
        int random_idx = rand() % (idx + 1);
        exchange(array, idx, random_idx);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    shuffle(array, 9);

    for (int i = 0; i < 9; i++)
    {
        printf("%i ", array[i]);
    }

    printf("\n");

    return 0;
}
