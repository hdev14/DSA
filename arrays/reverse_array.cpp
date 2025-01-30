#include <iostream>
#include <vector>

using namespace std;

void reverseArray(vector<int> &vec)
{
    int length = vec.size();

    vector<int> reverse(length);

    for (int i = length - 1; i >= 0; i--)
    {
        reverse[(length - 1) - i] = vec[i];
    }

    for (int i = 0; i < length; i++)
    {
        cout << reverse[i] << " ";
    }
}

void reverseArraySwap(vector<int> &vec)
{
    int left = 0, right = vec.size() - 1;

    while (left < right)
    {
        swap(vec[left], vec[right]);
        left++;
        right--;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};

    reverseArray(vec);
    cout << endl;
    reverseArraySwap(vec);
    return 0;
}
