#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> array)
{
    int max = array[0];
    for (int i = 1; i < 5; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }

    return max;
}

int findMaxRecursive(vector<int> array, int idx)
{
    if (idx == 5)
    {
        return array[idx];
    }

    int max_result = findMaxRecursive(array, idx + 1);

    return max_result > array[idx] ? max_result : array[idx];
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5};

    cout << "Normal" << endl;
    cout << "The max number in the array is: " << findMax(array) << endl;

    cout << "Recursive" << endl;
    cout << "The max number in the array is: " << findMaxRecursive(array, 0) << endl;

    return 0;
}
