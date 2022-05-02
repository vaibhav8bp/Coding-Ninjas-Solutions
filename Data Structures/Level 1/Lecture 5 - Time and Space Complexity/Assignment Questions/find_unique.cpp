#include <iostream>
using namespace std;

int findUnique(int *arr, int n)
{
    int unique = arr[0];
    for (int i = 1; i < n; i++)
    {
        unique ^= arr[i];
    }
    return unique;
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