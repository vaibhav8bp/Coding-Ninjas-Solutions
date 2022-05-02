#include <iostream>
using namespace std;

long long int balancedBTsHelper(int *ans, int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    long long int x = balancedBTsHelper(ans, n - 1);
    long long int y = balancedBTsHelper(ans, n - 2);
    long long int mod = 1e9 + 7;
    long long int temp1 = (x * x) % mod;
    long long int temp2 = (2 * x * y) % mod;
    ans[n] = (temp1 + temp2) % mod;
    return ans[n];
}

long long int balancedBTs(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return balancedBTsHelper(ans, n);
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}