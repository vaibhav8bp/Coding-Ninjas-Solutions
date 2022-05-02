#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    int *output = new int[n + 1];
    output[0] = 0;
    output[1] = arr[0];
    for (int i = 2; i < n + 1; i++)
    {
        int a = arr[i - 1] + output[i - 2];
        int b = output[i - 1];
        output[i] = max(a, b);
    }
    return output[n];
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

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}