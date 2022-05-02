#include <iostream>
using namespace std;

void column_wise_sum(int a[1000][1000], int m, int n)
{
    int i, j, sum;
    for (j = 0; j < n; j++)
    {
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum += a[i][j];
        }
        cout << sum << " ";
    }
}

int main()
{
    int a[1000][1000], m, n, i, j;
    cin >> m >> n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    column_wise_sum(a, m, n);
    return 0;
}