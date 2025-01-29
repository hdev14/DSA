#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSecondLagestElement(vector<int> &vec)
{
    int size = vec.size();

    sort(vec.begin(), vec.end());

    for (int i = size - 2; i > 0; i--)
    {
        if (vec[i] != vec[i - 1])
        {
            return vec[i];
        }
    }

    return -1;
}

int findSecondLagestElement2(vector<int> &vec)
{
    int size = vec.size();

    int max_element = vec[0];
    int second_max_element = -1;

    for (int i = 1; i < size; i++)
    {
        if (vec[i] > max_element)
        {
            max_element = vec[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (vec[i] < max_element && vec[i] > second_max_element)
        {
            second_max_element = vec[i];
        }
    }

    return second_max_element;
}

int findSecondLagestElement3(vector<int> &vec)
{
    int size = vec.size();

    int max_element = -1;
    int second_max_element = -1;

    for (int i = 0; i < size; i++)
    {
        if (vec[i] > max_element)
        {
            second_max_element = max_element;
            max_element = vec[i];
            continue;
        }

        if (vec[i] < max_element && vec[i] > second_max_element)
        {
            second_max_element = vec[i];
        }
    }

    return second_max_element;
}

int main()
{
    vector<int> vec = {23, 3, 5, 2, 1, 25, 54};

    cout << "Sorted Approach" << endl;

    int result = findSecondLagestElement(vec);

    if (result > 0)
    {
        cout << "The second largest element is: " << result << endl;
    }
    else
    {
        cout << "All the elements are equal" << endl;
    }

    cout << "Two loops approach" << endl;

    result = findSecondLagestElement2(vec);

    if (result > 0)
    {
        cout << "The second largest element is: " << result << endl;
    }
    else
    {
        cout << "All the elements are equal" << endl;
    }

    cout << "One loop approach" << endl;

    result = findSecondLagestElement3(vec);

    if (result > 0)
    {
        cout << "The second largest element is: " << result << endl;
    }
    else
    {
        cout << "All the elements are equal" << endl;
    }

    return 0;
}
