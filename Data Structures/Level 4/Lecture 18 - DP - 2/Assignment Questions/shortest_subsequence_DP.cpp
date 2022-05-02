#include <iostream>
using namespace std;

int solve(string s, string v)
{
    int n = s.length();
    int m = v.length();
    int dp[n + 1][m + 1], next[n + 1][m + 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int prev = -1;
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == v[j])
            {
                prev = 0;
            }
            else if (s[i] != v[j] && prev != -1)
            {
                prev += 1;
            }
            next[n - i][m - j] = prev;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (next[i][j] == -1)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][j - next[i][j] - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}