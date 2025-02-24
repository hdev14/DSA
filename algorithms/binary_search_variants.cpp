#include <iostream>

using std::cout;

bool contains(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value)
        {
            return true;
        }

        if (value > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int findFirst(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value && array[mid - 1] != value)
        {
            return mid;
        }

        if (value > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int findLast(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value && array[mid + 1] != value)
        {
            return mid;
        }

        if (value > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int leastGreater(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value && array[mid + 1] > value)
        {
            return mid + 1;
        }

        if (value > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int greatestLesser(int array[], int low, int high, int value)
{
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (array[mid] == value && array[mid - 1] < value)
        {
            return mid - 1;
        }

        if (value > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    cout << "---Binary Search---\n";

    int array[8] = {1, 1, 2, 2, 3, 3, 4, 5};

    int capacity = sizeof(array) / sizeof(array[0]);

    int high = capacity - 1,
        low = 0;

    bool result = contains(array, low, high, 6);
    int first_index = findFirst(array, low, high, 2);
    int last_index = findLast(array, low, high, 2);
    int least_greater_index = leastGreater(array, low, high, 4);
    int greatest_lesser_index = greatestLesser(array, low, high, 4);

    cout << "Contains element " << (result ? "true" : "false") << '\n';
    cout << "First index at position " << first_index << '\n';
    cout << "Last index at position " << last_index << '\n';
    cout << "Least greater index at position " << least_greater_index << '\n';
    cout << "Greatest lesser index at position " << greatest_lesser_index << '\n';
}
