#include <iostream>

using namespace std;

int main()
{
    int array[] = {3, 4, 5, 6, 1};
    int length = sizeof(array) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        int idx = i;

        for (int h = i + 1; h < length; h++)
        {
            if (array[h] < array[idx])
            {
                idx = h;
            }
        }

        int aux = array[idx];
        array[idx] = array[i];
        array[i] = aux;
    }

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}
