#include <iostream>
using namespace std;

int balancedBTs(int n)
{
    int *ans = new int[n + 1];
    ans[0] = ans[1] = 1;
    int mod = 1e9 + 7;
    for (int i = 2; i <= n; i++)
    {
        int x = ans[i - 1] % mod;
        int y = ans[i - 2] % mod;
        int temp1 = (int)((long(x) * x) % mod);
        int temp2 = (int)((2 * (long)(x)*y) % mod);
        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}