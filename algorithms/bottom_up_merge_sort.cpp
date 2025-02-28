#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void merge(vector<int> &vec, vector<int> &aux, int lower, int mid, int high)
{
    for (int i = lower; i <= high; i++)
    {
        aux[i] = vec[i];
    }

    for (int i = lower, j = mid + 1, k = lower; k <= high; k++)
    {
        if (i > mid)
        {
            vec[k] = aux[j];
            j++;
            continue;
        }

        if (j > high)
        {
            vec[k] = aux[i];
            i++;
            continue;
        }

        if (aux[i] < aux[j])
        {
            vec[k] = aux[i];
            i++;
            continue;
        }

        vec[k] = aux[j];
        j++;
    }
}

void mergeSort(vector<int> &vec)
{
    int length = vec.size(), lower, mid, high;
    vector<int> aux(length);

    for (int i = 1; i < length; i *= 2)
    {
        for (int j = 0; j < length - i; j += 2 * i)
        {
            lower = j;
            mid = lower + i - 1;
            high = fmin(lower + (2 * i) - 1, length - 1);
            merge(vec, aux, lower, mid, high);
        }
    }
}

int main()
{
    vector<int> vec = {12, 11, 15, 13, 5, 6, 7};

    mergeSort(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
