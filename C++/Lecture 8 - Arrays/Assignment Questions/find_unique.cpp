#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (i != j)
      {
        if (arr[i] == arr[j])
        {
          break;
        }
      }
    }
    if (j == size)
    {
      return arr[i];
    }
  }
}

int main()
{

  int t;
  cin >> t;

  while (t--)
  {
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; ++i)
    {
      cin >> input[i];
    }

    cout << findUnique(input, size) << endl;
  }

  return 0;
}