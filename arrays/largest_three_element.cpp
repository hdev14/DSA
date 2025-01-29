#include <iostream>
#include <vector>

using namespace std;

int findThreeLargestElement(vector<int> &vec)
{
    int size = vec.size();

    int max_element = -1;
    int second_max_element = -1;
    int three_max_element = -1;

    for (int i = 0; i < size; i++)
    {
        if (vec[i] > max_element)
        {
            three_max_element = second_max_element;
            second_max_element = max_element;
            max_element = vec[i];
            continue;
        }

        if (vec[i] > second_max_element && vec[i] != max_element)
        {
            three_max_element = second_max_element;
            second_max_element = vec[i];
            continue;
        }

        if (vec[i] > three_max_element && vec[i] < second_max_element)
        {
            three_max_element = vec[i];
        }
    }

    return three_max_element;
}

int main()
{
    vector<int> vec = {3, 4, 6, 12, 21};
    cout << "The result is " << findThreeLargestElement(vec) << endl;
    return 0;
}
