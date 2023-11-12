#include <iostream>

using std::cout;

int main()
{
  int one_dimensional_array[2] = {1, 2};
  int two_dimensional_array[2][2] = {{1, 2}, {1, 2}};                          // matrix
  int three_dimensional_array[2][2][2] = {{{1, 2}, {1, 2}}, {{1, 2}, {1, 2}}}; // array of matrix

  cout << "---1D Array---\n";
  cout << "[";
  for (auto &&item : one_dimensional_array)
    cout << item;
  cout << "]\n";

  cout << "---2D Array---\n";
  cout << "[";
  for (auto &&array : two_dimensional_array)
  {
    cout << "[";
    for (auto &&item : array)
      cout << item;
    cout << "]";
  }
  cout << "]\n";

  cout << "---3D Array---\n";
  cout << "[";
  for (auto &&matrix : three_dimensional_array)
  {
    cout << "[";
    for (auto &&array : matrix)
    {
      cout << "[";
      for (auto &&item : array)
        cout << item;
      cout << "]";
    }
    cout << "]";
  }
  cout << "]\n";

  return 0;
}
