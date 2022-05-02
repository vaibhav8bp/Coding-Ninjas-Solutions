#include <bits/stdc++.h>
using namespace std;

int minCostPathHelper(int **input, int **answer, int current_row, int m, int current_column, int n)
{
    if (current_row >= m || current_column >= n)
    {
        return INT_MAX;
    }
    else if (current_row == m - 1 && current_column == n - 1)
    {
        return input[current_row][current_column];
    }
    if (answer[current_row][current_column] != -1)
    {
        return answer[current_row][current_column];
    }
    int x = minCostPathHelper(input, answer, current_row + 1, m, current_column, n);
    int y = minCostPathHelper(input, answer, current_row, m, current_column + 1, n);
    int z = minCostPathHelper(input, answer, current_row + 1, m, current_column + 1, n);
    int a = min(x, min(y, z)) + input[current_row][current_column];
    answer[current_row][current_column] = a;
    return a;
}

int minCostPath(int **input, int m, int n)
{
    int **answer = new int *[m];
    for (int i = 0; i < m; i++)
    {
        answer[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer[i][j] = -1;
        }
    }
    minCostPathHelper(input, answer, 0, m, 0, n);
    return answer[0][0];
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