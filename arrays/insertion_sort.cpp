#include <iostream>

using namespace std;

int main()
{
    int array[] = {2, 34, 5, 2, 3, 5};
    int length = sizeof(array) / sizeof(int);

    for (int i = 1; i < length; i++)
    {
        int prev_idx = i - 1;
        int element = array[i];

        while (prev_idx >= 0 && array[prev_idx] > element)
        {
            array[prev_idx + 1] = array[prev_idx];
            prev_idx--;
        }

        array[prev_idx + 1] = element;
    }

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
