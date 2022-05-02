#include <iostream>
using namespace std;

int subsetSumToKHelper(int input[], int n, int startIndex, int output[][50], int k)
{
    if (startIndex == n)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int smallOutput1[10000][50], smallOutput2[10000][50];
    int smallOutputSize1 = subsetSumToKHelper(input, n, startIndex + 1, smallOutput1, k);
    int smallOutputSize2 = subsetSumToKHelper(input, n, startIndex + 1, smallOutput2, k - input[startIndex]);

    for (int i = 0; i < smallOutputSize1; i++)
    {
        for (int j = 0; j <= smallOutput1[i][0]; j++)
        {
            output[i][j] = smallOutput1[i][j];
        }
    }

    for (int i = 0; i < smallOutputSize2; i++)
    {
        int column_size = smallOutput2[i][0] + 1;
        output[i + smallOutputSize1][0] = column_size;
        for (int j = column_size; j > 1; j--)
        {
            output[i + smallOutputSize1][j] = smallOutput2[i][j - 1];
        }
        output[i + smallOutputSize1][1] = input[startIndex];
    }

    return smallOutputSize1 + smallOutputSize2;
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
    return subsetSumToKHelper(input, n, 0, output, k);
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
