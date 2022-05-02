#include <iostream>
using namespace std;

int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value, int **output)
{
    if (value == 0)
    {
        return 1;
    }
    else if (value < 0)
    {
        return 0;
    }

    if (numDenominations <= 0)
    {
        return 0;
    }
    
    if (output[numDenominations][value] != -1)
    {
        return output[numDenominations][value];
    }
    int exclude = countWaysToMakeChangeHelper(denominations + 1, numDenominations - 1, value, output);
    int include = countWaysToMakeChangeHelper(denominations, numDenominations, value - denominations[0], output);
    output[numDenominations][value] = include + exclude;
    return output[numDenominations][value];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **output = new int *[numDenominations + 1];
    for (int i = 0; i < numDenominations + 1; i++)
    {
        output[i] = new int[value + 1];
    }
    for (int i = 0; i < numDenominations + 1; i++)
    {
        for (int j = 0; j < value + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return countWaysToMakeChangeHelper(denominations, numDenominations, value, output);
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