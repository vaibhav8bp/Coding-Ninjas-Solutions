#include <iostream>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int **answer = new int *[m];
    for (int i = 0; i < m; i++)
    {
        answer[i] = new int[n];
    }
    answer[m - 1][n - 1] = input[m - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        answer[m - 1][i] = input[m - 1][i] + answer[m - 1][i + 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        answer[i][n - 1] = input[i][n - 1] + answer[i + 1][n - 1];
    }
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            answer[i][j] = input[i][j] + min(answer[i + 1][j], min(answer[i][j + 1], answer[i + 1][j + 1]));
        }
    }
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