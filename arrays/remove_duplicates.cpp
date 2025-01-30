#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 2, 3, 4, 4, 4, 5, 5};

    int idx = 1;

    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] != vec[i - 1])
        {
            vec[idx] = vec[i];
            idx++;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}
