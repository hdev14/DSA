#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int low, int mid, int high)
{
    int low_length = mid - low + 1;
    int high_length = high - mid;

    vector<int> low_subarray(low_length), high_subarray(high_length);

    for (int i = 0; i < low_length; i++)
    {
        low_subarray[i] = vec[low + i];
    }

    for (int i = 0; i < high_length; i++)
    {
        high_subarray[i] = vec[mid + 1 + i];
    }

    int low_idx = 0, high_idx = 0;
    int idx = low;

    while (low_idx < low_length && high_idx < high_length)
    {
        if (low_subarray[low_idx] <= high_subarray[high_idx])
        {
            vec[idx] = low_subarray[low_idx];
            low_idx++;
        }
        else
        {
            vec[idx] = high_subarray[high_idx];
            high_idx++;
        }
        idx++;
    }

    while (low_idx < low_length)
    {
        vec[idx] = low_subarray[low_idx];
        low_idx++;
        idx++;
    }

    while (high_idx < high_length)
    {
        vec[idx] = high_subarray[high_idx];
        high_idx++;
        idx++;
    }
}

void mergeSort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

int main()
{
    vector<int> vec = {12, 11, 13, 5, 6, 7};

    mergeSort(vec, 0, vec.size() - 1);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
