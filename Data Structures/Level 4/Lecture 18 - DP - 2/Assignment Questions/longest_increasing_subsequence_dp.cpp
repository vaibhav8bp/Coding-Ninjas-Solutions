#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int *arr, int n)
{
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && output[j] >= output[i])
            {
                output[i] = output[j] + 1;
            }
        }
    }
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (output[i] > max)
        {
            max = output[i];
        }
    }
    delete[] output;
    return max;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}