#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minCount(int n)
{
    int *ans = new int[n + 1];
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int k = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++)
        {
            k = min(k, ans[i - (j * j)]);
        }
        ans[i] = 1 + k;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}