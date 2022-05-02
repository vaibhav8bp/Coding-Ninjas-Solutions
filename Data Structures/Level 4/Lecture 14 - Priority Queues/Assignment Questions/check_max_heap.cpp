#include <iostream>
#include <cmath>
using namespace std;

bool helper(int *arr, int size, int index)
{
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (index >= size / 2)
    {
        return true;
    }
    if (arr[index] > arr[left] && arr[index] > arr[right] && helper(arr, size, left) && helper(arr, size, right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isMaxHeap(int arr[], int n)
{
    return helper(arr, n, 0);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}