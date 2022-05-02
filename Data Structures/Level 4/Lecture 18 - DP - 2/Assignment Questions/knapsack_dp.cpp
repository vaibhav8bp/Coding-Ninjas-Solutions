#include <iostream>
#include <climits>
using namespace std;

int knapsack(int *weight, int *value, int n, int maxWeight)
{
    int **output = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = new int[maxWeight + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        output[i][0] = 0;
    }
    for (int i = 1; i < maxWeight + 1; i++)
    {
        output[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < maxWeight + 1; j++)
        {
            int a = INT_MIN;
            if (j - weight[i - 1] >= 0)
            {
                a = value[i - 1] + output[i - 1][j - weight[i - 1]];
            }
            int b = output[i - 1][j];
            output[i][j] = max(a, b);
        }
    }
    return output[n][maxWeight];
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}