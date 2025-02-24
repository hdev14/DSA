#include <iostream>
#include <vector>

using namespace std;

// Lomuto
int partition1(vector<int> &vec, int low, int high)
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

// Hoares
int partition2(vector<int> &vec, int low, int high)
{
    int pivot = vec[low];
    int low_idx = low - 1;
    int high_idx = high + 1;

    while (true)
    {
        do
        {
            low_idx++;
        } while (vec[low_idx] < pivot);

        do
        {
            high_idx--;
        } while (vec[high_idx] > pivot);

        if (low_idx >= high_idx)
        {
            return high_idx;
        }

        swap(vec[low_idx], vec[high_idx]);
    }
}

void quickSort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivot_idx = partition2(vec, low, high);

        quickSort(vec, low, pivot_idx);
        quickSort(vec, pivot_idx + 1, high);
    }
}

int main()
{
    vector<int> vec = {10, 30, 40, 20, 40};
    quickSort(vec, 0, vec.size() - 1);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << endl;

    return 0;
}
