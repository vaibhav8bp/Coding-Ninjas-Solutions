#include <iostream>
using namespace std;

int maxMoneyLootedHelper(int *arr, int n, int *output)
{
    if (n <= 0)
    {
        return 0;
    }
    if (output[n] != -1)
    {
        return output[n];
    }
    int a = arr[0] + maxMoneyLootedHelper(arr + 2, n - 2, output);
    int b = maxMoneyLootedHelper(arr + 1, n - 1, output);
    output[n] = max(a, b);
    return output[n];
}

int maxMoneyLooted(int *arr, int n)
{
    int *output = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = -1;
    }
    return maxMoneyLootedHelper(arr, n, output);
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