#include <iostream>
using namespace std;

int array_sum(int a[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int a[1000000];
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << array_sum(a, n) << endl;
    return 0;
}