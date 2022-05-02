#include <climits>
using namespace std;

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
            if (i >= j)
            {
                output[i][j] = 0;
            }
        }
    }
    for (int a = n - 1; a >= 1; a--)
    {
        int i = a;
        for (int j = i + 1; j <= n; j++)
        {
            int min = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int answer1 = output[i][k];
                int answer2 = output[k + 1][j];
                int answer3 = arr[i - 1] * arr[k] * arr[j];
                int temp = answer1 + answer2 + answer3;
                if (temp < min)
                {
                    min = temp;
                }
                output[i][j] = min;
            }
        }
    }
    return output[1][n];
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