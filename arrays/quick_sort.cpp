#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int low, int high)
{
    int pivot = vec[high];

    int prev_idx = low - 1;

    for (int next_idx = low; next_idx < high; next_idx++)
    {
        if (vec[next_idx] < pivot)
        {
            prev_idx++;
            swap(vec[prev_idx], vec[next_idx]);
        }
    }
    int pivot_idx = prev_idx + 1;
    swap(vec[pivot_idx], vec[high]);
    return pivot_idx;
}

void quickSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition(vec, low, high);

        quickSort(vec, low, pivot_idx - 1);
        quickSort(vec, pivot_idx + 1, high);
    }
}

int main()
{
    vector<int> vec = {10, 30, 80, 90, 40};
    quickSort(vec, 0, vec.size() - 1);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << endl;

    return 0;
}
