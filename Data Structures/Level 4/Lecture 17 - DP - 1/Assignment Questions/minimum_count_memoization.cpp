#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minCountHelper(int *ans, int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int i = 1;
    int j = INT_MAX;
    while (i * i <= n)
    {
        j = min(j, minCountHelper(ans, n - pow(i, 2)));
        i++;
    }
    ans[n] = j + 1;
    return ans[n];
}

int minCount(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minCountHelper(ans, n);
    delete[] ans;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}