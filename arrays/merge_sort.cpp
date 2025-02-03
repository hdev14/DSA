#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;

    vector<int> left_subarray(left_length), right_subarray(right_length);

    for (int i = 0; i < left_length; i++)
    {
        left_subarray[i] = vec[left + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right_subarray[i] = vec[mid + 1 + i];
    }

    int left_idx = 0, right_idx = 0;
    int idx = left;

    while (left_idx < left_length && right_idx < right_length)
    {
        if (left_subarray[left_idx] <= right_subarray[right_idx])
        {
            vec[idx] = left_subarray[left_idx];
            left_idx++;
        }
        else
        {
            vec[idx] = right_subarray[right_idx];
            right_idx++;
        }
        idx++;
    }

    while (left_idx < left_length)
    {
        vec[idx] = left_subarray[left_idx];
        left_idx++;
        idx++;
    }

    while (right_idx < right_length)
    {
        vec[idx] = right_subarray[right_idx];
        right_idx++;
        idx++;
    }
}

void mergeSort(vector<int> &vec, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
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
