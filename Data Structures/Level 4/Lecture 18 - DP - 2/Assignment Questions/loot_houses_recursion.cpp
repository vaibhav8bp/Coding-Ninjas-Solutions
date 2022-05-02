#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
    if (n <= 0)
    {
        return 0;
    }
    int include = arr[0] + maxMoneyLooted(arr + 2, n - 2);
    int exclude = maxMoneyLooted(arr + 1, n - 1);
    return max(include, exclude);
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