#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int startIndex, int k, int **dp)
{
    if (startIndex == n)
    {
        if (k == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[startIndex][k] != -1)
    {
        return dp[startIndex][k];
    }

    int smallOutputSize1 = subsetSumToK(input, n, startIndex + 1, k, dp);
    int smallOutputSize2 = 0;
    if (k - input[startIndex] >= 0)
    {
        smallOutputSize2 = subsetSumToK(input, n, startIndex + 1, k - input[startIndex], dp);
    }

    dp[startIndex][k] = smallOutputSize1 + smallOutputSize2;
    return smallOutputSize1 + smallOutputSize2;
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
            for (int j = 0; j < k + 1; j++)
            {
                dp[i][j] = -1;
            }
        }

        int size = subsetSumToK(input, length, 0, k, dp);
        cout << size << endl;

        for (int i = 0; i < length + 1; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }
    return 0;
}