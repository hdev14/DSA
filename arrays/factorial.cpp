#include <iostream>

using namespace std;

int recursiveFactorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}

int interativeFactorial(int n)
{
    int result = 1, i;

    for (i = 2; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    cout << "Recursive Approach " << recursiveFactorial(5) << endl;
    cout << "Interative Approach " << interativeFactorial(5) << endl;
    return 0;
}
