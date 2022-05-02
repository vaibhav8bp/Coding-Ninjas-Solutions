#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int k, int **dp)
{
    dp[n][0] = 1;
    for (int i = 1; i < k + 1; i++)
    {
        dp[n][i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = k; j >= 0; j--)
        {
            int a = 0;
            if (j - input[i] >= 0)
            {
                a = dp[i + 1][j - input[i]];
            }
            dp[i][j] = dp[i + 1][j] + a;
        }
    }
    return dp[0][k];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int input[20], length, k;
        cin >> length;
        cin >> k;
        for (int i = 0; i < length; i++)
        {
            cin >> input[i];
        }

        int **dp = new int *[length + 1];
        for (int i = 0; i < length + 1; i++)
        {
            dp[i] = new int[k + 1];
        }

        int size = subsetSumToK(input, length, k, dp);
        cout << size << endl;

        for (int i = 0; i < length + 1; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }
    return 0;
}