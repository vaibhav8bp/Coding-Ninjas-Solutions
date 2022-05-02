#include <iostream>
#include <climits>
using namespace std;

int longestIncreasingSubsequenceHelper(int *arr, int n, int current_index, int previous)
{
    if (current_index == n)
    {
        return 0;
    }
    int op1 = INT_MIN;
    if (previous == INT_MIN || previous < arr[current_index])
    {
        op1 = 1 + longestIncreasingSubsequenceHelper(arr, n, current_index + 1, arr[current_index]);
    }
    int op2 = longestIncreasingSubsequenceHelper(arr, n, current_index + 1, previous);
    return max(op1, op2);
}

int longestIncreasingSubsequence(int *arr, int n)
{
    return longestIncreasingSubsequenceHelper(arr, n, 0, INT_MIN);
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