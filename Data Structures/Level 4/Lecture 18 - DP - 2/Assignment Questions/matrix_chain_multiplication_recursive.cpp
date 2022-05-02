#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplicationHelper(int *arr, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int answer1 = matrixChainMultiplicationHelper(arr, i, k);
        int answer2 = matrixChainMultiplicationHelper(arr, k + 1, j);
        int answer3 = arr[i - 1] * arr[k] * arr[j];
        int temp = answer1 + answer2 + answer3;
        if (temp < min)
        {
            min = temp;
        }
    }
    return min;
}

int matrixChainMultiplication(int *arr, int n)
{
    return matrixChainMultiplicationHelper(arr, 1, n);
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