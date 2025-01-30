#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
        {
            return false;
        }
    }

    return true;
}

bool isSortedRecursive(vector<int> &vec, int size)
{
    if (size == 1 || size == 0)
    {
        return true;
    }

    return vec[size - 1] >= vec[size - 2] && isSortedRecursive(vec, size - 1);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 5, 6};

    cout << "Normal approach" << endl;
    cout << "Does the array sorted? " << isSorted(vec) << endl;

    cout << "Recursive approach" << endl;
    cout << "Does the array sorted? " << isSorted(vec) << endl;

    return 0;
}
