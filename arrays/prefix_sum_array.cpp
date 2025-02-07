#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 5, 6};
    int length = sizeof(arr) / sizeof(int);
    int sum_arr[length];

    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            sum_arr[i] = arr[i];
            continue;
        }

        sum_arr[i] = sum_arr[i - 1] + arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        cout << sum_arr[i] << " ";
    }

    cout << endl;

    return 0;
}
