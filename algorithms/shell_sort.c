#include <stdio.h>

void exchange(int *array, int first_idx, int second_idx)
{
    int aux = array[second_idx];
    array[second_idx] = array[first_idx];
    array[first_idx] = aux;
}

void shellSort(int *array, int length)
{
    int h = 1;
    while (h < length / 3)
    {
        h = h * 3 + 1;
    }

    while (h >= 1)
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (array[j] >= array[j - h])
                {
                    break;
                }

                exchange(array, j, j - h);
            }
        }
        h /= 3;
    }
}

int main()
{
    int length = 5;
    int array[] = {3, 4, 5, 6, 1};

    shellSort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }

    return 0;
}
