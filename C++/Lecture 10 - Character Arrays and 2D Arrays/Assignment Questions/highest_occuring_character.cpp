#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

char highestOccurringChar(char input[])
{
    int frequency[123] = {0}, i, length = strlen(input), max = INT_MIN;
    char a;
    for (i = 0; i < length; i++)
    {
        a = input[i];
        frequency[a]++;
    }
    for (i = 0; i < 123; i++)
    {
        if (max < frequency[i])
        {
            max = frequency[i];
            a = i;
        }
    }
    return a;
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}