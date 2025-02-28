#include <iostream>
#include <vector>

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

void sort(vector<int> &vec, vector<int> &aux, int lower, int high)
{
    if (lower >= high)
        return;

    int mid = lower + (high - lower) / 2;
    sort(vec, aux, lower, mid);
    sort(vec, aux, mid + 1, high);
    merge(vec, aux, lower, mid, high);
}

void mergeSort(vector<int> &vec)
{
    int length = vec.size();
    vector<int> aux(length);
    sort(vec, aux, 0, length - 1);
}

int main()
{
    vector<int> vec = {12, 11, 13, 5, 6, 7};

    mergeSort(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
