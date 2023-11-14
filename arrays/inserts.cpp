#include <iostream>

using std::cout;

void insertAtEnd()
{
    cout << "---Insert at the end---\n";

    int array[20] = {12, 22, 33, 44, 51};

    int capacity = sizeof(array) / sizeof(array[0]);

    int length = 5, value = 23;

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    if (!(length >= capacity))
    {
        array[length] = value;
        length += 1;
    }

    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";
}

void insertAtAnyPosition()
{
    cout << "---Insert at any position---\n";

    int array[20] = {12, 22, 33, 44, 51};

    int capacity = sizeof(array) / sizeof(array[0]);

    int length = 5, position = 3, value = 99;

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    if (position < 0 && position >= capacity)
    {
        cout << "Position is out of range";
        return;
    }

    if (array[position] == 0)
    {
        cout << "position equals to zero";
        array[position] = value;
    }
    else
    {
        /*
        int aux[length - position];

        for (int i = position; i < length; i++)
        {
            aux[i - position] = array[i];
        }

        array[position] = value;

        for (int i = position; i < length; i++)
        {
            array[i + 1] = aux[i - position];
        }
        */

        /*
         for (int i = length - 1; i >= position; i--)
         {
             array[i + 1] = array[i];
         }
        */

        for (int i = length; i > position; i--)
        {
            array[i] = array[i - 1];
        }

        array[position] = value;

        length++;
    }

    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";
}

void insertInSortedArray()
{
    cout << "---Insert at any position---\n";

    int array[20] = {1, 2, 4, 5, 6};

    int capacity = sizeof(array) / sizeof(array[0]);

    int length = 5, value = 3;

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    if (!(length >= capacity))
    {
        int i;
        for (i = length - 1; i >= 0 && array[i] > value; i--)
        {
            array[i + 1] = array[i];
        }

        array[i + 1] = value;

        length++;
    }

    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    cout << "\n";
}

int main()
{
    insertAtEnd();
    insertAtAnyPosition();
    insertInSortedArray();
    return 0;
}
