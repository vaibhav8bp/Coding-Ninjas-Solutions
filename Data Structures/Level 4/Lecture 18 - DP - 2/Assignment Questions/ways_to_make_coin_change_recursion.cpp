#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
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
    int exclude = countWaysToMakeChange(denominations + 1, numDenominations - 1, value);
    int include = countWaysToMakeChange(denominations, numDenominations, value - denominations[0]);
    return include + exclude;
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