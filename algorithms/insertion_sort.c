#include <stdio.h>

void exchange(int *array, int first_idx, int second_idx)
{
    int aux = array[second_idx];
    array[second_idx] = array[first_idx];
    array[first_idx] = aux;
}

void insertionSort(int *array)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j] >= array[j - 1])
            {
                break;
            }

            exchange(array, j, j - 1);
        }
    }
}

int main()
{
    int array[] = {3, 4, 5, 6, 1};

    insertionSort(array);

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", array[i]);
    }

    return 0;
}
