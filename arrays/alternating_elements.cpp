#include <iostream>
#include "alternating_elements.h"

using namespace std;

void alternateElements(int elements[5])
{
    for (int i = 0; i < 5; i += 2)
    {
        cout << elements[i] << " ";
    }

    cout << endl;
}

void alternateElementsRecursive(int elements[], int idx)
{
    if (idx < 5)
    {
        cout << elements[idx] << " ";
        alternateElementsRecursive(elements, idx + 2);
        return;
    }

    cout << endl;
}

int main()
{
    int elements[] = {10, 20, 30, 40, 50};

    cout << "Normal" << endl;

    alternateElements(elements);

    cout << "Recursive" << endl;

    alternateElementsRecursive(elements, 0);

    return 0;
}
