#include <iostream>

using std::cout;

int metaBinarySearch(int array[], int length, int value)
{
    // {1, 2, 3, 4, 5}
    int interval_size = length;

    while (interval_size > 0)
    {
        int interval_division = interval_size / 2;
        int mid_index = ((length - 1) + interval_division) / 2; // found the correct logic

        if (array[mid_index] == value)
            return mid_index;

        if (array[mid_index] < value)
            interval_size = (length - mid_index) / 2;
        else
            interval_size = mid_index / 2;
    }

    return -1;
}
int main()
{
    cout << "---Binary Search---\n";

    int array[] = {1, 2, 3, 4, 5};

    int capacity = sizeof(array) / sizeof(array[0]);

    int high = capacity - 1,
        low = 0,
        value = 5,
        position = -1;

    // position = binarySearch(array, low, high, value);
    position = metaBinarySearch(array, capacity, value);

    if (position == -1)
        cout << "Element not found";
    else
        cout << "Position of the element is " << position;

    cout << "\n";
}
