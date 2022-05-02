#include <iostream>
#include <cstring>
using namespace std;

void print(char input[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << input[i];
    }
    cout << endl;
}

void printSubstrings(char input[])
{
    for (int i = 0; i < strlen(input); i++)
    {
        for (int j = i; j < strlen(input); j++)
        {
            print(input, i, j);
        }
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}