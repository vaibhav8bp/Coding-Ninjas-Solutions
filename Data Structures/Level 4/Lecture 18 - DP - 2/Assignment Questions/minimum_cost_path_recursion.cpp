#include <iostream>
#include <climits>
using namespace std;

int minCostPathHelper(int **input, int current_row, int m, int current_column, int n)
{
    if (current_row >= m || current_column >= n)
    {
        return INT_MAX;
    }
    else if (current_row == m - 1 and current_column == n - 1)
    {
        return input[current_row][current_column];
    }
    int x = minCostPathHelper(input, current_row + 1, m, current_column, n);
    int y = minCostPathHelper(input, current_row, m, current_column + 1, n);
    int z = minCostPathHelper(input, current_row + 1, m, current_column + 1, n);
    int ans = min(x, min(y, z));
    return ans + input[current_row][current_column];
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input, 0, m, 0, n);
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}