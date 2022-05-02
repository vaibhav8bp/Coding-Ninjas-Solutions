#include <iostream>
using namespace std;

bool is_sorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool isSmallerOutput = is_sorted(arr + 1, size - 1);

    if (!isSmallerOutput)
    {
        return false;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return true;
}

int main()
{
    int *arr = new int[5], i, size;
    cin >> size;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << is_sorted(arr, size);
    delete[] arr;
    return 0;
}