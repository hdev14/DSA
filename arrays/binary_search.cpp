#include <iostream>

using std::cout;

int main()
{
    cout << "---Binary Search---\n";

    int array[6] = {1, 2, 4, 5, 6, 7};

    int capacity = sizeof(array) / sizeof(array[0]);

    int high = capacity - 1,
        low = 0,
        value = 7,
        position = -1;

    int mid = low + (high - low) / 2;

    while (low <= capacity - 1)
    {
        if (array[mid] == value)
        {
            position = mid;
            break;
        }

        if (mid == 0)
            break;

        if (value < array[mid])
            high = mid - 1;
        else
            low = mid + 1;

        mid = low + (high - low) / 2;
    }

    if (position == -1)
        cout << "Element not found";
    else
        cout << "Position of the element is " << position;

    cout << "\n";
}
