#include <iostream>

using std::cout;

int binarySearch(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value)
        {
            return mid;
        }

        if (value < array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int recursiveBinarySearch(int array[], int low, int high, int value)
{
    int position = -1;
    int mid = 0;

    if (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value)
            return mid; // position

        if (value > array[mid]) // {1, 2, 4, 5, 6, 7};
            return recursiveBinarySearch(array, mid + 1, high, value);
        else
            return recursiveBinarySearch(array, low, mid - 1, value);
    }

    return -1;
}

int main()
{
    cout << "---Binary Search---\n";

    int array[6] = {1, 2, 4, 5, 6, 7};

    int capacity = sizeof(array) / sizeof(array[0]);

    int high = capacity - 1,
        low = 0,
        value = 5,
        position = -1;

    // position = binarySearch(array, low, high, value);
    position = recursiveBinarySearch(array, low, high, value);

    if (position == -1)
        cout << "Element not found";
    else
        cout << "Position of the element is " << position;

    cout << "\n";
}
