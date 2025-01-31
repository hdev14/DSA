#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {0, 3, 4, 1, 0, 2, 0};
    vector<int> temp;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != 0)
        {
            temp.push_back(vec[i]);
        }
    }

    int l = 0;

    while (l < (vec.size() - 1))
    {
        if (l < temp.size())
        {
            vec[l] = temp[l];
        }
        else
        {
            vec[l] = 0;
        }

        l++;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
