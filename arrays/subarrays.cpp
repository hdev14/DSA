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

/*************  ✨ Codeium Command ⭐  *************/
/**
 * @brief This is the main function of the program
 *
 * This function does the following:
 *  1. Declares a vector with the elements 1, 2, 3, and 4.
 *  2. Calls the function printSubArrays with the vector as the argument.
 *  3. Calls the function printSubArraysRecursive with the vector, 0, and 0 as arguments.
 *  4. Returns 0.
 *
 * @return 0 if the function runs successfully
 */
/******  3546e73c-042d-469f-a61b-db993e9571d3  *******/
int main()
{
    vector<int> vec = {1, 2, 3, 4};

    printSubArrays(vec);
    printSubArraysRecursive(vec, 0, 0);
    return 0;
}
