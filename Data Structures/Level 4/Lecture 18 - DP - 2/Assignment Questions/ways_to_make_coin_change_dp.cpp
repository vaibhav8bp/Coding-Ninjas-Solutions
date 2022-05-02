#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **output = new int *[numDenominations + 1];
    for (int i = 0; i < numDenominations + 1; i++)
    {
        output[i] = new int[value + 1];
    }
    for (int i = 0; i < numDenominations + 1; i++)
    {
        output[i][0] = 1;
    }
    for (int i = 1; i < value + 1; i++)
    {
        output[0][i] = 0;
    }
    for (int i = 1; i < numDenominations + 1; i++)
    {
        for (int j = 1; j < value + 1; j++)
        {
            int x = output[i - 1][j];
            int y = 0;
            if (j - denominations[numDenominations - i] >= 0)
            {
                y = output[i][j - denominations[numDenominations - i]];
            }
            output[i][j] = x + y;
        }
    }
    return output[numDenominations][value];
}

int main()
{

    int numDenominations;
    cin >> numDenominations;

    int *denominations = new int[numDenominations];

    for (int i = 0; i < numDenominations; i++)
    {
        cin >> denominations[i];
    }

    int value;
    cin >> value;

    cout << countWaysToMakeChange(denominations, numDenominations, value);

    delete[] denominations;
}