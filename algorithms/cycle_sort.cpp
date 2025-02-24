#include <iostream>

using namespace std;

void cycleSort(int arr[], int length)
{
    int current_position = 0;

    while (current_position < length)
    {
        int correct_idx = arr[current_position] - 1;

        if (arr[current_position] != arr[correct_idx])
        {
            swap(arr[current_position], arr[correct_idx]);
        }
        else
        {
            current_position++;
        }
    }
}

int main()
{
    int arr[] = {3, 2, 4, 5, 1};
    int length = sizeof(arr) / sizeof(int);

    cycleSort(arr, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
