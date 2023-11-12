#include <iostream>

using std::cout;

void simpleAccessOperation()
{
    double numbers[] = {11, 12, 13, 14, 15, 16};
    double count = 0;
    double sum = 0;

    for (const double &number : numbers)
    {
        cout << number << "\n";
        sum += number;
        count++;
    }

    cout << "Sum: " << sum << "\n";

    double average = sum / count;

    cout << "Average: " << average << "\n";
}

void accessByPointer()
{
    int numbers[10];

    for (int i = 0; i < 10; i++)
    {
        *(numbers + i) = i + 1; // numbers[i]
    }

    cout << "Values: ";

    for (int i = 0; i < 10; i++)
    {
        cout << *(numbers + i) << ' ';
    }

    cout << '\n';
}

/*
As known,
*(p + 1) is exactly the same as *(1 + p)
Therefore, *(arr + i) in above code can also be written as *(i + arr)
and basically *(arr + i) means a[i] implying,
*(i + arr) can also be written as i[a]
*/
void accessByNumber()
{
    int numbers[10];

    for (int i = 0; i < 10; i++)
    {
        i[numbers] = i + 1;
    }

    cout << "Values: ";
    for (int i = 0; i < 10; i++)
    {
        cout << i[numbers] << ' ';
    }

    cout << '\n';
}

int main()
{
    simpleAccessOperation();
    accessByPointer();
    accessByNumber();

    return 0;
}
