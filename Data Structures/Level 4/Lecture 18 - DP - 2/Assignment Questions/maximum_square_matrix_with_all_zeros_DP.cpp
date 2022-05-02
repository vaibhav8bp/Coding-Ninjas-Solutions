#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int **output = new int *[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = new int[m];
    }
    for (int i = 0; i < m; i++)
    {
        output[0][i] = (arr[0][i] == 0) ? (1) : (0);
    }
    for (int i = 1; i < n; i++)
    {
        output[i][0] = (arr[i][0] == 0) ? (1) : (0);
    }
    int max_ = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                output[i][j] = min(output[i - 1][j], min(output[i][j - 1], output[i - 1][j - 1])) + 1;
            }
            else
            {
                output[i][j] = 0;
            }
            max_ = max(max_, output[i][j]);
        }
    }
    return max_;
}

int main()
{
    int **arr, n, m, i, j;
    cin >> n >> m;
    arr = new int *[n];

    for (i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

    delete[] arr;

    return 0;
}