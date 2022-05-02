#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplicationHelper(int *arr, int i, int j, int **output)
{
    if (i >= j)
    {
        return 0;
    }
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int answer1 = matrixChainMultiplicationHelper(arr, i, k, output);
        int answer2 = matrixChainMultiplicationHelper(arr, k + 1, j, output);
        int answer3 = arr[i - 1] * arr[k] * arr[j];
        int temp = answer1 + answer2 + answer3;
        if (temp < min)
        {
            min = temp;
        }
    }
    output[i][j] = min;
    return min;
}

int matrixChainMultiplication(int *arr, int n)
{
    int **output = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return matrixChainMultiplicationHelper(arr, 1, n, output);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}