#include <iostream>
#include <vector>

using namespace std;

void printSubArrays(vector<int> &vec)
{
    int n = vec.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "[";

            for (int h = i; h <= j; h++)
            {
                cout << " " << vec[h] << " ";
            }

            cout << "]";
        }
    }

    cout << endl;
}

void printSubArraysRecursive(vector<int> &vec, int start, int end)
{
    if (end == vec.size())
    {
        return;
    }

    if (start > end)
    {
        printSubArraysRecursive(vec, 0, end + 1);
    }
    else
    {
        cout << "[";
        for (int i = start; i <= end; i++)
        {
            cout << " " << vec[i] << " ";
        }
        cout << "]";
        printSubArraysRecursive(vec, start + 1, end);
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    printSubArrays(vec);
    printSubArraysRecursive(vec, 0, 0);
    return 0;
}
