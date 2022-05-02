#include <iostream>
using namespace std;

inline bool check(int a, int b)
{
    bool c;
    c = (a <= b) ? (true) : (false);
    return c;
}

bool sorted(int *arr, int n)
{
    if (n == 1)
    {
        return true;
    }
    if (check(arr[0], arr[1]))
    {
        sorted(arr + 1, n - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    int *arr = new int[5], i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sorted(arr, n);
    delete[] arr;
    return 0;
}