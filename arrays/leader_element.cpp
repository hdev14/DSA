#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> getLeaders(vector<int> &vec)
{
    vector<int> leaders;

    for (int i = 0; i < vec.size(); i++)
    {
        bool isLeader = true;

        for (int j = i; j < vec.size(); j++)
        {
            if (vec[i] < vec[j])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
        {
            leaders.push_back(vec[i]);
        }
    }

    return leaders;
}

vector<int> getLeaders2(vector<int> &vec)
{
    vector<int> leaders;
    int maxRight = vec[vec.size() - 1];

    leaders.push_back(maxRight);

    for (int i = vec.size() - 2; i >= 0; i--)
    {
        if (vec[i] >= maxRight)
        {
            maxRight = vec[i];
            leaders.push_back(maxRight);
        }
    }

    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main()
{

    vector<int> vec = {10, 4, 3, 70, 23, 60};
    vector<int> leaders1 = getLeaders(vec);
    vector<int> leaders2 = getLeaders2(vec);

    cout << "Two loops" << endl;

    for (int i = 0; i < leaders1.size(); i++)
    {
        cout << leaders1[i] << " ";
    }

    cout << endl;

    cout << "One loop" << endl;

    for (int i = 0; i < leaders2.size(); i++)
    {
        cout << leaders2[i] << " ";
    }

    cout << endl;

    return 0;
}
