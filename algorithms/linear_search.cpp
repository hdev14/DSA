#include <iostream>
using namespace std;

int findIndex(int element, int array[5])
{
    for (int i = 0; i < 5; i++)
    {
        if (element == array[i])
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int element = 4;
    int idx;

    int result = findIndex(element, array);

    if (result >= 0)
    {
        cout << "Element found at index " << result << endl;
        return 0;
    }

    cout << "Element not found" << endl;

    return 0;
}
